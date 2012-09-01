#ifndef MANAGE_H
#define MANAGE_H

#include "ui_manage.h"
#include "csair.h"
#include <QDialog>


class Manager : public QDialog
{
	Q_OBJECT

public:
	Manager(csAir* parent);
	QString toChi(QString);
	QString toEng(QString);

	private slots:
		void searchClicked();
		void returnClicked();

private:
	Ui::MDialog ui;
	QDomDocument doc;    //note: Keep the DOM tree and table view, database file synchronization
};

#endif