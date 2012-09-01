#include "manage.h"
#include "csair.h"
#include "operateDB.h"
#include <QDialog>
#include <QTableWidget>
#include <QDomDocument>
#include <QFile>
#include <QLineEdit>
#include <QMessageBox>
#include <QInputDialog>
#include <QPushButton>
#include <QString>
#include <QModelIndex>
#include <QPoint>
#include <QTextStream>
#include <QDebug>

Manager::Manager(csAir *parent) : QDialog(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setColumnCount(7);
	ui.tableWidget->setColumnWidth(0, 60);
	ui.tableWidget->setColumnWidth(1, 60);
	ui.tableWidget->setColumnWidth(2, 90);
	ui.tableWidget->setColumnWidth(3, 60);
	ui.tableWidget->setColumnWidth(4, 40);
	ui.tableWidget->setColumnWidth(5, 50);
	ui.tableWidget->setColumnWidth(6, 58);
	ui.tableWidget->verticalHeader()->setVisible(false);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

	//establish conncection between database and DOM tree
	QFile file("Resources\\userDB.xml");
	if(!file.open(QFile::ReadOnly) || !doc.setContent(&file)){
		QMessageBox m;
		m.setText("无法读取用户数据");
		m.exec();
		close();
		return;
	} 
	file.close();

	connect(ui.search, SIGNAL(clicked()), this, SLOT(searchClicked()));
}

void Manager::searchClicked(){
	if(ui.name->text() == ""){
		QMessageBox m;
		m.setText("请输入姓名");
		m.exec();
		return;
	} 
	if(ui.identy->text() == ""){
		QMessageBox m;
		m.setText("请输入证件号");
		m.exec();
		return;
	} 

	int row = 0;
	bool find = false;
	QDomElement elem = doc.documentElement();
	for(elem = elem.firstChildElement(); !elem.isNull(); elem = elem.nextSiblingElement()){
		if(elem.attribute("name") == ui.name->text() && elem.attribute("identy") == ui.identy->text()){
			find = true;
			ui.tableWidget->insertRow(ui.tableWidget->rowCount());
			QTableWidgetItem* depc = new QTableWidgetItem(toChi(elem.attribute("depCity")));
			QTableWidgetItem* arrc = new QTableWidgetItem(toChi(elem.attribute("arrCity")));
			QTableWidgetItem* date = new QTableWidgetItem(elem.attribute("date"));
			QTableWidgetItem* ID = new QTableWidgetItem(elem.attribute("ID"));
			QTableWidgetItem* cabin = new QTableWidgetItem(elem.attribute("cabin"));
			QTableWidgetItem* amount = new QTableWidgetItem(elem.attribute("amount"));
			QPushButton* ret = new QPushButton("退票");
			ui.tableWidget->setItem(row, 0, depc);
			ui.tableWidget->setItem(row, 1, arrc);
			ui.tableWidget->setItem(row, 2, date);
			ui.tableWidget->setItem(row, 3, ID);
			ui.tableWidget->setItem(row, 4, cabin);
			ui.tableWidget->setItem(row, 5, amount);
			ui.tableWidget->setCellWidget(row, 6, ret);
			row ++;

			connect(ret,SIGNAL(clicked()),this,SLOT(returnClicked()));
		}
	}

	if(!find){
		QMessageBox m;
		m.setText("姓名或证件号错误，请重新输入");
		m.exec();
	}

}

void Manager::returnClicked(){
	QPushButton* sender = qobject_cast<QPushButton *>(QObject::sender());
	if(sender == NULL)return;
	QModelIndex mindex = ui.tableWidget->indexAt(QPoint(sender->frameGeometry().x(), sender->frameGeometry().y()));
	int clickRow = mindex.row();
	QTableWidgetItem* item = ui.tableWidget->item(clickRow, 5);       //get current amount
	int currAmo = item->text().toInt();
	QString ID = ui.tableWidget->item(clickRow, 3)->text();      //get flightID

	bool isOK = false;
	int retNum = QInputDialog::getInt(this, "确认退票", "请输入退票数量", 1, 1, currAmo, 1, &isOK);
	if(isOK){
		//change window view and date(DOM) in memory
		QDomElement elem, root = doc.documentElement();
		for(elem = root.firstChildElement(); !elem.isNull(); elem = elem.nextSiblingElement()){
			if(elem.attribute("ID") == ID && elem.attribute("identy") == ui.identy->text()){
				if(retNum == currAmo){          //return all tickets of the flight
					root.removeChild(elem);      //delete information from database file
					ui.tableWidget->removeRow(clickRow);       //change table view
				}
				else {               //only modify information in table view and database
					elem.setAttribute("amount", currAmo - retNum);
					item->setText(QString::number(currAmo - retNum));
					qDebug() << elem.attribute("amount");
				}
				break;
			}
		}

		//sync to database file
		QFile file("Resources\\userDB.xml");
		if(!file.open(QFile::WriteOnly | QFile::Truncate)){
			QMessageBox::information(this, "csAir", "无法写入用户数据");
			return;
		}
		QTextStream out(&file);
		doc.save(out,4);
		file.close();

		//modify the system's database
		QString dc = toEng(ui.tableWidget->item(clickRow, 0)->text());
		QString ac = toEng(ui.tableWidget->item(clickRow, 1)->text());
		if(!editDB(dc, ac, ui.tableWidget->item(clickRow, 2)->text(), ui.tableWidget->item(clickRow, 3)->text(),
			"remain", QString::number(retNum), ui.tableWidget->item(clickRow, 4)->text())){
				QMessageBox::information(this, "csAir", "无法写入系统数据");
				return;
		}

		QMessageBox::information(this, "csAir", "退票成功");
	}
}

QString Manager::toChi(QString s){
	if(s == "Guangzhou")return "广州";
	if(s == "Shanghai")return "上海";
	if(s == "Beijing")return "北京";
	if(s == "Haerbin")return "哈尔滨";
	if(s == "Chengdu")return "成都";
	if(s == "Chongqing")return "重庆";
	if(s == "HongKong")return "香港";
	if(s == "Dalian")return "大连";
	if(s == "Tianjin")return "天津";
}

QString Manager::toEng(QString s){
	if(s == "广州")return "Guangzhou";
	if(s == "上海")return "Shanghai";
	if(s == "北京")return "Beijing";
	if(s == "哈尔滨")return "Haerbin";
	if(s == "成都")return "Chengdu";
	if(s == "重庆")return "Chongqing";
	if(s == "香港")return "HongKong";
	if(s == "大连")return "Dalian";
	if(s == "天津")return "Tianjin";
}