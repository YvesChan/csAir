#ifndef CSAIR_H
#define CSAIR_H

#include <QtGui/QMainWindow>
#include "ui_csair.h"

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
private:
	Ui::csAirClass ui;
};


#endif // CSAIR_H
