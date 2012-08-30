#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include "csair.h"
#include <QDialog>

class BookDialog : public QDialog
{
	Q_OBJECT

public:
	BookDialog(csAir* parent);

private:
	Ui::Dialog ui;

};

#endif