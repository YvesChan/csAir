/********************************************************************************
** Form generated from reading UI file 'manage.ui'
**
** Created: Sun Sep 2 01:12:25 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGE_H
#define UI_MANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_MDialog
{
public:
    QLineEdit *name;
    QLineEdit *identy;
    QLabel *label;
    QLabel *label_2;
    QPushButton *search;
    QTableWidget *tableWidget;

    void setupUi(QDialog *MDialog)
    {
        if (MDialog->objectName().isEmpty())
            MDialog->setObjectName(QString::fromUtf8("MDialog"));
        MDialog->resize(419, 245);
        name = new QLineEdit(MDialog);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(50, 10, 81, 20));
        identy = new QLineEdit(MDialog);
        identy->setObjectName(QString::fromUtf8("identy"));
        identy->setGeometry(QRect(190, 10, 113, 20));
        label = new QLabel(MDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 31, 21));
        label_2 = new QLabel(MDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 10, 41, 21));
        search = new QPushButton(MDialog);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(330, 10, 51, 23));
        tableWidget = new QTableWidget(MDialog);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 40, 420, 201));
        tableWidget->setAutoScroll(true);
        tableWidget->setAutoScrollMargin(16);

        retranslateUi(MDialog);

        QMetaObject::connectSlotsByName(MDialog);
    } // setupUi

    void retranslateUi(QDialog *MDialog)
    {
        MDialog->setWindowTitle(QApplication::translate("MDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MDialog", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MDialog", "\350\257\201\344\273\266\345\217\267", 0, QApplication::UnicodeUTF8));
        search->setText(QApplication::translate("MDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MDialog", "\345\207\272\345\217\221", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MDialog", "\346\212\265\350\276\276", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MDialog", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MDialog", "\350\210\252\347\217\255\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MDialog", "\350\210\261\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MDialog", "\350\256\242\347\245\250\351\207\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MDialog: public Ui_MDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_H
