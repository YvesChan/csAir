#include "dialog.h"
#include "csair.h"
#include "operateDB.h"
#include <QDialog>
#include <QDomElement>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>

BookDialog::BookDialog(csAir *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	QString depCity = parent->getDepCity();
	QString arrCity = parent->getArrCity();
	QString date = parent->getDate();
	QDomElement* ds = parent->getDataSource();
	QTableWidgetItem* flight = parent->getFlight();
	QTableWidget* table = flight->tableWidget();
	QString flightID = table->item(flight->row(),0)->text();      //get the selected row and its first column is flightID
	QString cabin;
	switch(flight->column()){
		case 3: cabin = "A";break;
		case 4: cabin = "B";break;
		case 5: cabin = "C";break;
	}

	connect(ui.cancel,SIGNAL(clicked()),this,SLOT(close()));
	connect(this,SIGNAL(rejected()),this,SLOT(close()));
	connect(ui.amount,SIGNAL(valueChanged(int)),this,SLOT(costChanged(int)));
	connect(ui.ok,SIGNAL(clicked()),this,SLOT(bookConfirm()));

	for(ds = &(ds->firstChildElement()); !ds->isNull() && ds->attribute("ID") != flightID; ds = &(ds->nextSiblingElement()));
	if(ds->isNull()){qDebug() << "sth wrong!"; emit reject();}
	ui.depc->setText(depCity);
	ui.arrc->setText(arrCity);
	ui.dept->setText(ds->attribute("depTime"));
	ui.arrt->setText(ds->attribute("arrTime"));
	ui.depd->setText(date);
	ui.totalt->setText(ds->attribute("totalTime"));
	ui.ID->setText(flightID);
	ui.plane->setText(ds->attribute("plane"));
	for(ds = &(ds->firstChildElement()); !ds->isNull() && ds->attribute("name") != cabin; ds = &(ds->nextSiblingElement()));
	if(ds->isNull()){qDebug() << "sth wrong!"; emit reject();}
	ui.cabin->setText(cabin);
	ui.quota->setText(ds->attribute("quota"));
	ui.remain->setText(ds->attribute("remain"));
	ui.price->setText(ds->attribute("price"));
	
	ui.amount->setValue(0);
	ui.amount->setMaximum(ui.remain->text().toInt());
	//ui.cost->setText(QString::number(ui.price->text().toInt()));
}

QString BookDialog::toEng(QString s){
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

void BookDialog::costChanged(int value){
	ui.cost->setText(QString::number(ui.price->text().toInt() * value));
}

void BookDialog::bookConfirm(){
	QMessageBox m;
	if(ui.name->text() == ""){m.setText("请输入旅客姓名"); m.exec(); return;}
	if(ui.identy->text() == ""){m.setText("请输入证件号"); m.exec(); return;}
	if(ui.amount->value() == 0){m.setText("请输入订票量"); m.exec(); return;}
	if(editDB(toEng(ui.depc->text()),toEng(ui.arrc->text()),ui.depd->text(),ui.ID->text(),"remain",QString::number(-(ui.amount->value())),ui.cabin->text()) 
		&& manageUserDB(ui.name->text(), ui.identy->text(), ui.number->text(), ui.amount->value(), toEng(ui.depc->text()) + " " + toEng(ui.arrc->text()) + " " + ui.depd->text() + " " + ui.ID->text() + " " + ui.cabin->text()))m.setText("预订成功");
	else m.setText("预订失败");
	m.exec();
	emit rejected();
	return;
}