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
				for(int l = 0; l < 3; l ++){
					cabin = doc.createElement("cabin");
					flight.appendChild(cabin);
					cabin.setAttribute("name", cab[l][0]);
					cabin.setAttribute("price", QString::number(int(pri * cab[l][1].toFloat())));
					cabin.setAttribute("quota", cab[1][2]);
					cabin.setAttribute("remain", cab[1][2]);
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

//API for query datebase
bool queryDB(const QString &dep, const QString &arr, const QDate &date, QDomElement* &elem){
	QDomDocument doc;
	QFile file("Resources\\" + date.toString("yyyy-MM-dd") + ".xml");
	if(!file.open(QFile::ReadOnly))return false;
	if(!doc.setContent(&file))return false;
	QDomNode root = doc.documentElement();
	QDomElement ret;
	//search for the goal flights and return the DOM subtree as a parameter
	for(ret = root.firstChildElement(); ret.attribute("name") != dep; ret = ret.nextSiblingElement());
	for(ret = ret.firstChildElement(); ret.attribute("name") != arr; ret = ret.nextSiblingElement());
	if(ret.isNull())return false;
	elem = new QDomElement(ret);
	return true;
}