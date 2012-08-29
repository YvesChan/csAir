#include "csair.h"
#include <QtGui/QMainWindow>
#include <QDateTime>
#include "operateDB.h"
#include <QDomElement>
#include <QMessageBox>

csAir::csAir(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	updateDB();
	ui.setupUi(this);
	ui.calendarWidget->setVisible(false);
	QString date = QString::number(ui.calendarWidget->selectedDate().year()) + "-" + QString::number(ui.calendarWidget->selectedDate().month()) + "-" + QString::number(ui.calendarWidget->selectedDate().day());
	ui.dateText->setText(date);

	QDate d;
	QDateTime dt;
	dt.setDate(d.currentDate());
	ui.calendarWidget->setMinimumDate(dt.date());
	ui.calendarWidget->setMaximumDate(dt.addDays(30).date());
	
	connect(ui.dateText,SIGNAL(dateTextClick()),this,SLOT(findClick()));
	connect(ui.calendarWidget,SIGNAL(clicked(const QDate&)),this,SLOT(dateClicked(const QDate&)));
	connect(ui.query,SIGNAL(clicked()),this,SLOT(queryClicked()));
	//connect(ui.query,SIGNAL(query(QString &, QString &, QDate &)),this,SLOT(queryClicked(QString &, QString &, QDate &)));
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

DateText::DateText(QWidget * parent)
	:QLineEdit(parent){};

void DateText::mousePressEvent(QMouseEvent *e){
	if(e->button() == Qt::LeftButton)
		emit dateTextClick();
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
	QDomElement e;
	int count = 0;
	for(e = elem->firstChildElement(); !e.isNull(); e.nextSiblingElement(),count ++){
		QTableWidgetItem *row = new QTableWidgetItem();
		ui.tableWidget->setHorizontalHeaderItem(count,row);
		QTableWidgetItem *ID = new QTableWidgetItem(e.attribute("ID"));
		QTableWidgetItem *dat = new QTableWidgetItem(e.attribute("depTime") + " // " + e.attribute("arrTime"));
		QTableWidgetItem *plane = new QTableWidgetItem(e.attribute("plane"));
		QTableWidgetItem *A = new QTableWidgetItem(e.firstChildElement().attribute("price"));
		QTableWidgetItem *B = new QTableWidgetItem(e.firstChildElement().nextSiblingElement().attribute("price"));
		QTableWidgetItem *C = new QTableWidgetItem(e.lastChildElement().attribute("price"));
	}
}
	
/*
csAir::~csAir()
{

}
*/