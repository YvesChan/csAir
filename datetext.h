#ifndef DATETEXT_H
#define DATETEXT_H

#include <QLineEdit>
#include <QMouseEvent>
#include <QWidget>

class DateText : public QLineEdit
{
	Q_OBJECT
public:
	DateText(QWidget * parent = 0):QLineEdit(parent){};
	void DateText::mousePressEvent(QMouseEvent *e){
	if(e->button() == Qt::LeftButton)
		emit dateTextClick();
}
signals:
	void dateTextClick();

};

#endif