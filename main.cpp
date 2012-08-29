#include "csair.h"
#include <QtGui/QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	csAir w;
	w.show();
	return a.exec();
}
