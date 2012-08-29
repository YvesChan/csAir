#include "csair.h"
#include <QtGui/QApplication>
#include <QDebug>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec *codec = QTextCodec::codecForName("System");    //获取系统编码
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);

	csAir w;
	w.show();
	return a.exec();
}
