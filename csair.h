#ifndef CSAIR_H
#define CSAIR_H

#include <QtGui/QMainWindow>
#include "ui_csair.h"
#include <QTableWidgetItem>

class csAir : public QMainWindow
{
	Q_OBJECT

public:
	csAir(QWidget *parent = 0, Qt::WFlags flags = 0);
	QString toEng(int);
	//~csAir();
signals:
	//void query(const QString &, const QString &, const QDate &);

	private slots:
		void findClick();
		void dateClicked(const QDate &date);
		void queryClicked();
		void booked(QTableWidgetItem*);
		void tabChanged(int index);
		//void test(QTableWidgetItem*);

private:
	Ui::csAirClass ui;
	bool isBook;
	QTableWidgetItem* bookedItem;
	QTableWidget* tableWidget;
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
