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
	if(s == "����")return "Guangzhou";
	if(s == "�Ϻ�")return "Shanghai";
	if(s == "����")return "Beijing";
	if(s == "������")return "Haerbin";
	if(s == "�ɶ�")return "Chengdu";
	if(s == "����")return "Chongqing";
	if(s == "���")return "HongKong";
	if(s == "����")return "Dalian";
	if(s == "���")return "Tianjin";
}

void BookDialog::costChanged(int value){
	ui.cost->setText(QString::number(ui.price->text().toInt() * value));
}

void BookDialog::bookConfirm(){
	QMessageBox m;
	if(ui.name->text() == ""){m.setText("�������ÿ�����"); m.exec(); return;}
	if(ui.identy->text() == ""){m.setText("������֤����"); m.exec(); return;}
	if(ui.amount->value() == 0){m.setText("�����붩Ʊ��"); m.exec(); return;}
	if(editDB(toEng(ui.depc->text()),toEng(ui.arrc->text()),ui.depd->text(),ui.ID->text(),"remain",QString::number(-(ui.amount->value())),ui.cabin->text()) 
		&& manageUserDB(ui.name->text(), ui.identy->text(), ui.number->text(), ui.amount->value(), toEng(ui.depc->text()) + " " + toEng(ui.arrc->text()) + " " + ui.depd->text() + " " + ui.ID->text() + " " + ui.cabin->text()))m.setText("Ԥ���ɹ�");
	else m.setText("Ԥ��ʧ��");
	m.exec();
	emit rejected();
	return;
}