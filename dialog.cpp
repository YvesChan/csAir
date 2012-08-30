#include "dialog.h"
#include "csair.h"
#include "operateDB.h"
#include <QDialog>
#include <QDomElement>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QLineEdit>
#include <QDebug>

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
	
}
