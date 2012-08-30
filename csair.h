#ifndef CSAIR_H
#define CSAIR_H

#include <QtGui/QMainWindow>
#include "ui_csair.h"
#include <QTableWidgetItem>
#include <QDomElement>

class csAir : public QMainWindow
{
	Q_OBJECT

public:
	csAir(QWidget *parent = 0, Qt::WFlags flags = 0);
	QString toEng(int);
	QString getSelectDate(){return date;}
	int getIndex(){return index;}
	QString getDepCity(){return depCity;}
	QString getArrCity(){return arrCity;}
	QString getDate(){return date;}
	QDomElement* getDataSource(){return elem[index];}
	QTableWidgetItem* getFlight(){return bookedItem;}


	//~csAir();
signals:
	//void query(const QString &, const QString &, const QDate &);

	private slots:
		void findClick();
		void dateClicked(const QDate &date);
		void queryClicked();
		void booked(QTableWidgetItem*);
		void tabChanged(int index);
		void bookClicked();
		//void test(QTableWidgetItem*);

private:
	Ui::csAirClass ui;
	bool isBook;
	QString date;
	QString depCity;
	QString arrCity;
	int index;
	QTableWidgetItem* bookedItem;
	//QTableWidget* tableWidget;
	QDomElement* elem[30];
};
/*
class grid : public QWidget
{
	Q_OBJECT

public:
	grid(QString);

signals:
	void radioClicked();
	*/

#endif // CSAIR_H
