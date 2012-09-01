/********************************************************************************
** Form generated from reading UI file 'csair.ui'
**
** Created: Sun Sep 2 01:12:25 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSAIR_H
#define UI_CSAIR_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include <datetext.h>

QT_BEGIN_NAMESPACE

class Ui_csAirClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QComboBox *depart;
    QLabel *label_2;
    QComboBox *arrive;
    QLabel *label_3;
    DateText *dateText;
    QCalendarWidget *calendarWidget;
    QPushButton *query;
    QTabWidget *tabWidget;
    QPushButton *book;
    QPushButton *manage;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *csAirClass)
    {
        if (csAirClass->objectName().isEmpty())
            csAirClass->setObjectName(QString::fromUtf8("csAirClass"));
        csAirClass->setEnabled(true);
        csAirClass->resize(611, 394);
        centralWidget = new QWidget(csAirClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 51, 21));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        depart = new QComboBox(centralWidget);
        depart->setObjectName(QString::fromUtf8("depart"));
        depart->setGeometry(QRect(60, 10, 61, 21));
        depart->setEditable(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 10, 51, 21));
        arrive = new QComboBox(centralWidget);
        arrive->setObjectName(QString::fromUtf8("arrive"));
        arrive->setGeometry(QRect(180, 10, 61, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 10, 54, 21));
        dateText = new DateText(centralWidget);
        dateText->setObjectName(QString::fromUtf8("dateText"));
        dateText->setEnabled(true);
        dateText->setGeometry(QRect(310, 10, 71, 20));
        dateText->setEchoMode(QLineEdit::Normal);
        dateText->setReadOnly(true);
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setEnabled(true);
        calendarWidget->setGeometry(QRect(220, 30, 241, 171));
        calendarWidget->setMinimumDate(QDate(2012, 8, 27));
        calendarWidget->setMaximumDate(QDate(2012, 9, 27));
        calendarWidget->setFirstDayOfWeek(Qt::Sunday);
        calendarWidget->setGridVisible(false);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);
        calendarWidget->setDateEditAcceptDelay(1500);
        query = new QPushButton(centralWidget);
        query->setObjectName(QString::fromUtf8("query"));
        query->setGeometry(QRect(400, 10, 61, 31));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 50, 611, 331));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(30, 16));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        book = new QPushButton(centralWidget);
        book->setObjectName(QString::fromUtf8("book"));
        book->setGeometry(QRect(470, 10, 61, 31));
        manage = new QPushButton(centralWidget);
        manage->setObjectName(QString::fromUtf8("manage"));
        manage->setGeometry(QRect(540, 10, 61, 31));
        csAirClass->setCentralWidget(centralWidget);
        label->raise();
        depart->raise();
        label_2->raise();
        arrive->raise();
        label_3->raise();
        dateText->raise();
        query->raise();
        tabWidget->raise();
        calendarWidget->raise();
        book->raise();
        manage->raise();
        statusBar = new QStatusBar(csAirClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        csAirClass->setStatusBar(statusBar);

        retranslateUi(csAirClass);

        depart->setCurrentIndex(0);
        arrive->setCurrentIndex(0);
        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(csAirClass);
    } // setupUi

    void retranslateUi(QMainWindow *csAirClass)
    {
        csAirClass->setWindowTitle(QApplication::translate("csAirClass", "csAir", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("csAirClass", "\345\207\272\345\217\221\345\237\216\345\270\202", 0, QApplication::UnicodeUTF8));
        depart->clear();
        depart->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("csAirClass", "\344\270\212\346\265\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\271\277\345\267\236", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\214\227\344\272\254", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\223\210\345\260\224\346\273\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\351\246\231\346\270\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\346\210\220\351\203\275", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\244\247\350\277\236", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\351\207\215\345\272\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\244\251\346\264\245", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("csAirClass", "\345\210\260\350\276\276\345\237\216\345\270\202", 0, QApplication::UnicodeUTF8));
        arrive->clear();
        arrive->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("csAirClass", "\344\270\212\346\265\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\271\277\345\267\236", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\214\227\344\272\254", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\223\210\345\260\224\346\273\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\351\246\231\346\270\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\346\210\220\351\203\275", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\244\247\350\277\236", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\351\207\215\345\272\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("csAirClass", "\345\244\251\346\264\245", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("csAirClass", "\345\207\272\345\217\221\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        dateText->setText(QString());
        dateText->setPlaceholderText(QString());
        query->setText(QApplication::translate("csAirClass", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        book->setText(QApplication::translate("csAirClass", "\351\242\204\350\256\242", 0, QApplication::UnicodeUTF8));
        manage->setText(QApplication::translate("csAirClass", "\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class csAirClass: public Ui_csAirClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSAIR_H
