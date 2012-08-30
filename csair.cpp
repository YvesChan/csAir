#include "csair.h"
#include <QtGui/QMainWindow>
#include <QDateTime>
#include "operateDB.h"
#include <QDomElement>
#include <QMessageBox>
#include <QTableWidget>
#include <Qt>
#include <QTabWidget>
#include <QComboBox>

csAir::csAir(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	updateDB();      //automatically update database while program start

	ui.setupUi(this);
	ui.calendarWidget->setVisible(false);
	QString date = QString::number(ui.calendarWidget->selectedDate().year()) + "-" + QString::number(ui.calendarWidget->selectedDate().month()) + "-" + QString::number(ui.calendarWidget->selectedDate().day());
	ui.dateText->setText(date);

	QDate d;
	QDateTime dt;
	dt.setDate(d.currentDate());
	ui.calendarWidget->setMinimumDate(dt.date());
	ui.calendarWidget->setMaximumDate(dt.addDays(30).date());

	isBook = false;

	connect(ui.dateText,SIGNAL(dateTextClick()),this,SLOT(findClick()));
	connect(ui.calendarWidget,SIGNAL(clicked(const QDate&)),this,SLOT(dateClicked(const QDate&)));
	connect(ui.query,SIGNAL(clicked()),this,SLOT(queryClicked()));
	connect(ui.tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tabChanged(int)));
}

QString csAir::toEng(int i){
	switch(i){
		case 1: return "Shanghai";
		case 2: return "Guangzhou";
		case 3: return "Beijing";
		case 4: return "Haerbin";
		case 5: return "HongKong";
		case 6: return "Chengdu";
		case 7: return "Dalian";
		case 8: return "Chongqing";
		case 9: return "Tianjin";
	}
}


void csAir::findClick(){
	ui.calendarWidget->setVisible(true);
}

void csAir::dateClicked(const QDate &date){
	ui.dateText->setText(QString::number(date.year()) + "-" + QString::number(date.month()) + "-" + QString::number(date.day()));
	ui.calendarWidget->setVisible(false);
}


void csAir::queryClicked(){
	if(ui.depart->currentIndex() == 0){
		QMessageBox msg;
		msg.setText("请选择出发城市");
		msg.exec();
		return;
	}
	if(ui.arrive->currentIndex() == 0){
		QMessageBox msg;
		msg.setText("请选择抵达城市");
		msg.exec();
		return;
	}
	QDomElement* elem;
	if(!queryDB(toEng(ui.depart->currentIndex()), toEng(ui.arrive->currentIndex()), ui.calendarWidget->selectedDate(), elem)){
		QMessageBox msg;
		msg.setText("查询数据库失败");
		return;
	}
	QWidget* tab = new QWidget();
	tab->setObjectName(QString::fromUtf8("tab"));
	tableWidget = new QTableWidget(tab);
	QDomElement e;
	int count = 0;
	QTableWidgetItem *col1 = new QTableWidgetItem("航班号");
	QTableWidgetItem *col2 = new QTableWidgetItem("出发/抵达时间");
	QTableWidgetItem *col3 = new QTableWidgetItem("飞机型号");
	QTableWidgetItem *col4 = new QTableWidgetItem("头等舱(￥)");
	QTableWidgetItem *col5 = new QTableWidgetItem("商务舱(￥)");
	QTableWidgetItem *col6 = new QTableWidgetItem("经济舱(￥)");
	tableWidget->setColumnCount(6);
	tableWidget->setRowCount(8);
	tableWidget->setHorizontalHeaderItem(0, col1);
	tableWidget->setHorizontalHeaderItem(1, col2);
	tableWidget->setHorizontalHeaderItem(2, col3);
	tableWidget->setHorizontalHeaderItem(3, col4);
	tableWidget->setHorizontalHeaderItem(4, col5);
	tableWidget->setHorizontalHeaderItem(5, col6);

	for(e = elem->firstChildElement(); !e.isNull(); e = e.nextSiblingElement(),count ++){
		QTableWidgetItem *row = new QTableWidgetItem();
		tableWidget->setVerticalHeaderItem(count,row);
		QTableWidgetItem *ID = new QTableWidgetItem(e.attribute("ID"));
		//ID->setFlags(Qt::ItemIsEnabled);
		QTableWidgetItem *dat = new QTableWidgetItem(e.attribute("depTime") + " / " + e.attribute("arrTime"));
		//dat->setFlags(Qt::ItemIsEnabled);
		QTableWidgetItem *plane = new QTableWidgetItem(e.attribute("plane"));
		//plane->setFlags(Qt::ItemIsEnabled);
		QTableWidgetItem *A = new QTableWidgetItem(e.firstChildElement().attribute("price"));
		QTableWidgetItem *B = new QTableWidgetItem(e.firstChildElement().nextSiblingElement().attribute("price"));
		QTableWidgetItem *C = new QTableWidgetItem(e.lastChildElement().attribute("price"));
		A->setCheckState(Qt::Unchecked);
		B->setCheckState(Qt::Unchecked);
		C->setCheckState(Qt::Unchecked);
		tableWidget->setItem(count, 0, ID);
		tableWidget->setItem(count, 1, dat);
		tableWidget->setItem(count, 2, plane);
		tableWidget->setItem(count, 3, A);
		tableWidget->setItem(count, 4, B);
		tableWidget->setItem(count, 5, C);
	}

	tableWidget->setGeometry(QRect(0, 0, 611, 301));
	tableWidget->setLineWidth(1);
	tableWidget->setAutoScrollMargin(16);
	tableWidget->setIconSize(QSize(0, 0));
	tableWidget->setSortingEnabled(false);
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
	tableWidget->verticalHeader()->setVisible(false);

	int index = ui.tabWidget->addTab(tab, ui.depart->currentText() + " -> " + ui.arrive->currentText() + "  " + ui.calendarWidget->selectedDate().toString("yyyy-MM-dd"));
	ui.tabWidget->setCurrentIndex(index);

	//connect(tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(booked(int, int)));
	connect(tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(booked(QTableWidgetItem*)));
}

void csAir::booked(QTableWidgetItem* item){
	/*
	if(tableWidget->item(row,column)->checkState() == Qt::Unchecked)isBook = false;
	else if(!isBook){
		isBook = true;
		bookedItem = tableWidget->item(row,column);
	}
	else {
		bookedItem->setCheckState(Qt::Unchecked);
		bookedItem = tableWidget->item(row,column);
		isBook = true;
	}
	*/
	if(item->checkState() == Qt::Unchecked)isBook = false;
	else if(!isBook){
		isBook = true;
		bookedItem = item;
	}
	else {
		bookedItem->setCheckState(Qt::Unchecked);
		bookedItem = item;
		isBook = true;
		}
}

void csAir::tabChanged(int index){
	if(isBook){
		bookedItem->setCheckState(Qt::Unchecked);
		isBook = false;
	}
}
/*
void csAir::test(QTableWidgetItem*){
	QMessageBox m;
	m.setText("!!!");
	m.exec();
}
*/
/*
csAir::~csAir()
{

}
*/