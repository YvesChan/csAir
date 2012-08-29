#ifndef DATETEXT_H
#define DATETEXT_H

#include <QLineEdit>
#include <QMouseEvent>
#include <QWidget>

class DateText : public QLineEdit
{
	Q_OBJECT
public:
	DateText(QWidget * parent = 0);
	void mousePressEvent(QMouseEvent *e);
signals:
	void dateTextClick();
};

#endif