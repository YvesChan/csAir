#include <QDomDocument>
#include <QDomNode>
#include <QFile>
#include <QDomElement>
#include <ctime>
#include <cstdlib>
#include <QTextStream>
#include <QDateTime>
#include <QFileInfo>
#include <QDebug>
#include "operateDB.h"
#include <QStringList>

using namespace std;

//update the whole database in 30 days from today
bool updateDB(){
	QDateTime dt;
	QDate d;
	dt.setDate(d.currentDate());   //get current date
	QFileInfo dbfile;
	for(int x = 0; x < 31; x ++){
		QString date = dt.addDays(x).toString("yyyy-MM-dd");
		//qDebug() << date;
		dbfile.setFile("Resources\\" + date + ".xml");
		if(dbfile.exists())continue;     //check if data file existed
		else if(!createDB(date))return false;
	}

	dbfile.setFile("Resources\\userDB.xml");
	if(!dbfile.exists()){
		QFile file("Resources\\userDB.xml");
		if(!file.open(QFile::WriteOnly | QFile::Text))return false;
		QDomDocument doc;
		QDomProcessingInstruction instruction;
		instruction = doc.createProcessingInstruction("xml","version=\"1.0\"");
		doc.appendChild(instruction);
		QDomElement root = doc.createElement("userIndex");
		doc.appendChild(root);
		QTextStream out(&file);
		doc.save(out,4);
		file.close();
	}

	return true;
}

//create single day's database file
bool createDB(QString date){
	srand(time(NULL));

	//define environmental variable for random function to select
	QString city[9] = {"Guangzhou","Shanghai","Beijing","Haerbin","Chengdu","Chongqing","HongKong","Dalian","Tianjin"};
	QString planes[4] = {"A300","A310","A320","A340"};
	QString cab[3][3] = {{"A","1","8"},{"B","0.7","30"},{"C","0.4","150"}};

	//associate with data file, create XML file declaration and root element
	QFile file("Resources\\" + date + ".xml");
	if(!file.open(QFile::WriteOnly | QFile::Text))return false;
	QDomDocument doc;
	QDomProcessingInstruction instruction;
	instruction = doc.createProcessingInstruction("xml","version=\"1.0\"");
	doc.appendChild(instruction);
	QDomElement root = doc.createElement("dateIndex");
	doc.appendChild(root);

	//define tag reference
	QDomElement depCity;
	QDomElement arrCity;
	QDomElement flight;
	//QDomElement ID;
	//QDomElement depTime;
	//QDomElement arrTime;
	//QDomElement totalTime;
	//QDomElement plane;
	//QDomElement cabins;
	QDomElement cabin;
	//QDomElement price;
	//QDomElement quota; 
	//QDomElement remain;

	//Loop to produce sub-elements
	for(int i = 0; i < 9; i ++){
		depCity = doc.createElement("depCity");
		depCity.setAttribute("name",city[i]);
		root.appendChild(depCity);
		for(int j = 0; j < 9; j ++){
			if(city[i] == city[j])continue;    //if repeated
			arrCity = doc.createElement("arrCity");
			arrCity.setAttribute("name",city[j]);
			depCity.appendChild(arrCity);
			int totalt = rand() % 4 + 1;      //travel duration
			for(int k = 0; k < 8; k ++){
				int num = rand() % 9000 + 1000;     //flight number
				int dept = 8 + k * 2;              //departure time
				int arrt = (dept + totalt) % 25;          //arrive time
				int pri = (rand() % 20) * 100 + 2000;    //price of A cabin
				flight = doc.createElement("flight");
				arrCity.appendChild(flight);
				flight.setAttribute("ID","CZ" + QString::number(num));
				flight.setAttribute("depTime", QString::number(dept) + ":00");
				flight.setAttribute("arrTime", QString::number(arrt) + ":00");
				flight.setAttribute("totalTime", QString::number(totalt) + " hours");
				flight.setAttribute("plane", planes[rand() % 4]);
				
				/*
				ID = doc.createElement("ID");
				depTime = doc.createElement("depTime");
				arrTime = doc.createElement("arrTime");
				totalTime = doc.createElement("totalTime");
				plane = doc.createElement("plane");
				cabins = doc.createElement("cabins");
				flight.appendChild(ID);
				flight.appendChild(depTime);
				flight.appendChild(arrTime);
				flight.appendChild(totalTime);
				flight.appendChild(plane);
				flight.appendChild(cabins);
				ID.appendChild(doc.createTextNode("CZ" + QString::number(num)));
				depTime.appendChild(doc.createTextNode(QString::number(dept) + ":00"));
				arrTime.appendChild(doc.createTextNode(QString::number(arrt) + ":00"));
				totalTime.appendChild(doc.createTextNode(QString::number(totalt) + " hours"));
				plane.appendChild(doc.createTextNode(planes[rand() % 4]));
				*/
				for(int m = 0; m < 3; m ++){
					cabin = doc.createElement("cabin");
					flight.appendChild(cabin);
					cabin.setAttribute("name", cab[m][0]);
					cabin.setAttribute("price", QString::number(int(pri * cab[m][1].toFloat())));
					cabin.setAttribute("quota", cab[m][2]);
					cabin.setAttribute("remain", cab[m][2]);
					/*
					price = doc.createElement("price");
					quota = doc.createElement("quota");
					remain = doc.createElement("remain");
					price.appendChild(doc.createTextNode(QString::number(int(pri * cab[l][1].toFloat()))));
					quota.appendChild(doc.createTextNode(cab[l][2]));
					remain.appendChild(doc.createTextNode(cab[l][2]));
					cabin.appendChild(price);
					cabin.appendChild(quota);
					cabin.appendChild(remain);
					*/
				}
			}
		}
	}

	//save the dom tree into xml file
	QTextStream out(&file);
	doc.save(out,4);
	file.close();

	return true;
}

//API for query datebase, return a DOM tree's pointer.
bool queryDB(const QString &dep, const QString &arr, const QDate &date, QDomElement* &elem){
	QDomDocument doc;
	QFile file("Resources\\" + date.toString("yyyy-MM-dd") + ".xml");
	if(!file.open(QFile::ReadOnly))return false;
	if(!doc.setContent(&file))return false;
	QDomNode root = doc.documentElement();
	QDomElement ret;
	//search for the goal flights , create a DOM subtree in heap and return its pointer as a parameter
	for(ret = root.firstChildElement(); ret.attribute("name") != dep; ret = ret.nextSiblingElement());
	for(ret = ret.firstChildElement(); ret.attribute("name") != arr; ret = ret.nextSiblingElement());
	if(ret.isNull())return false;
	elem = new QDomElement(ret);
	file.close();
	return true;
}

//modify the flight information (modify cabin's remain tickets or specific tag's value)
//if tag = remain, then value is the variable (include positive or negative number)
bool editDB(QString depc, QString arrc, QString date, QString ID, QString tag, QString value, QString cabin = ""){
	QDomDocument doc;
	QFile file("Resources\\" + date + ".xml");
	if(!file.open(QFile::ReadOnly))return false;
	if(!doc.setContent(&file))return false;

	QDomElement elem = doc.documentElement();
	for(elem = elem.firstChildElement(); !elem.isNull() && elem.attribute("name") != depc; elem = elem.nextSiblingElement());
	for(elem = elem.firstChildElement(); !elem.isNull() && elem.attribute("name") != arrc; elem = elem.nextSiblingElement());
	for(elem = elem.firstChildElement(); !elem.isNull() && elem.attribute("ID") != ID; elem = elem.nextSiblingElement());
	if(elem.isNull())return false;
	if(cabin == "")elem.setAttribute(tag, value);
	else {
		for(elem = elem.firstChildElement(); !elem.isNull() && elem.attribute("name") != cabin; elem = elem.nextSiblingElement());
		if(tag == "remain"){         //number variable is passed 
			int curr = elem.attribute("remain").toInt();
			elem.setAttribute("remain", curr + value.toInt());
		}
		else elem.setAttribute(tag, value);
	}
	file.close();
	if(!file.open(QFile::WriteOnly | QFile::Truncate))return false;
	QTextStream out(&file);
	doc.save(out,4);
	file.close();
	return true;
}

//create and maintain USER information database
//parameter flyInfo contains: "depcity arrcity date flightID cabin"
bool manageUserDB(const QString &name, const QString &identy, const QString &num, int amount, const QString &flyInfo){
	QDomDocument doc;
	QFile file("Resources\\userDB.xml");
	if(!file.open(QFile::ReadOnly))return false;
	if(!doc.setContent(&file))return false;
	QStringList info = flyInfo.split(" ");

	QDomElement root = doc.documentElement();
	QDomElement elem;
	//judge if exist the same flight
	for(elem = root.firstChildElement(); !elem.isNull(); elem = elem.nextSiblingElement())
		if(elem.attribute("identy") == identy && elem.attribute("ID") == info[3]){
			elem.setAttribute("amount", elem.attribute("amount").toInt() + amount);
			break;
		}
	if(elem.isNull()){
		elem = doc.createElement("passenger");
		root.appendChild(elem);
		elem.setAttribute("name", name);
		elem.setAttribute("identy", identy);
		elem.setAttribute("number", num);
		elem.setAttribute("ID", info[3]);
		elem.setAttribute("cabin", info[4]);
		elem.setAttribute("amount", amount);
		elem.setAttribute("depCity", info[0]);
		elem.setAttribute("arrCity", info[1]);
		elem.setAttribute("date", info[2]);
	}

	file.close();
	if(!file.open(QFile::WriteOnly | QFile::Truncate))return false;
	QTextStream out(&file);
	doc.save(out,4);
	file.close();
	return true;
}

//maintain USER information database (return tickets)
/*
bool manageUserDB(const QString &name, const QString &identy, QDomDocument* &doc){
	QFile file("Resources\\userDB.xml");
	if(!file.open(QFile::ReadOnly))return false;
	if(!doc.setContent(&file))return false;
	QDomElement root = doc.documentElement();
	*/