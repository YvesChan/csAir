/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Thu Aug 30 17:20:08 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *depc;
    QLineEdit *dept;
    QLineEdit *depd;
    QLineEdit *ID;
    QLineEdit *cabin;
    QLineEdit *remain;
    QLineEdit *arrc;
    QLineEdit *arrt;
    QLineEdit *totalt;
    QLineEdit *plane;
    QLineEdit *quota;
    QLineEdit *price;
    QGroupBox *groupBox_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(342, 418);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 301, 211));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 60, 54, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 54, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 120, 54, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 54, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 30, 54, 21));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 120, 54, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 150, 54, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 150, 54, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 90, 54, 21));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(160, 90, 54, 21));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 180, 54, 21));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(160, 180, 54, 21));
        depc = new QLineEdit(groupBox);
        depc->setObjectName(QString::fromUtf8("depc"));
        depc->setEnabled(false);
        depc->setGeometry(QRect(80, 30, 61, 20));
        dept = new QLineEdit(groupBox);
        dept->setObjectName(QString::fromUtf8("dept"));
        dept->setEnabled(false);
        dept->setGeometry(QRect(80, 60, 61, 20));
        depd = new QLineEdit(groupBox);
        depd->setObjectName(QString::fromUtf8("depd"));
        depd->setEnabled(false);
        depd->setGeometry(QRect(80, 90, 61, 20));
        ID = new QLineEdit(groupBox);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setEnabled(false);
        ID->setGeometry(QRect(80, 120, 61, 20));
        cabin = new QLineEdit(groupBox);
        cabin->setObjectName(QString::fromUtf8("cabin"));
        cabin->setEnabled(false);
        cabin->setGeometry(QRect(80, 150, 61, 20));
        remain = new QLineEdit(groupBox);
        remain->setObjectName(QString::fromUtf8("remain"));
        remain->setEnabled(false);
        remain->setGeometry(QRect(80, 180, 61, 20));
        arrc = new QLineEdit(groupBox);
        arrc->setObjectName(QString::fromUtf8("arrc"));
        arrc->setEnabled(false);
        arrc->setGeometry(QRect(220, 30, 61, 20));
        arrt = new QLineEdit(groupBox);
        arrt->setObjectName(QString::fromUtf8("arrt"));
        arrt->setEnabled(false);
        arrt->setGeometry(QRect(220, 60, 61, 20));
        totalt = new QLineEdit(groupBox);
        totalt->setObjectName(QString::fromUtf8("totalt"));
        totalt->setEnabled(false);
        totalt->setGeometry(QRect(220, 90, 61, 20));
        plane = new QLineEdit(groupBox);
        plane->setObjectName(QString::fromUtf8("plane"));
        plane->setEnabled(false);
        plane->setGeometry(QRect(220, 120, 61, 20));
        quota = new QLineEdit(groupBox);
        quota->setObjectName(QString::fromUtf8("quota"));
        quota->setEnabled(false);
        quota->setGeometry(QRect(220, 150, 61, 20));
        price = new QLineEdit(groupBox);
        price->setObjectName(QString::fromUtf8("price"));
        price->setEnabled(false);
        price->setGeometry(QRect(220, 180, 61, 20));
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 240, 291, 121));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 30, 31, 21));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 60, 54, 21));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 90, 54, 21));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 30, 101, 20));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 60, 191, 20));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(70, 90, 191, 20));
        ok = new QPushButton(Dialog);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(160, 380, 61, 21));
        cancel = new QPushButton(Dialog);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(250, 380, 61, 21));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\350\210\252\347\217\255\351\242\204\350\256\242\344\277\241\346\201\257\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "\350\210\252\347\217\255\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "\346\212\265\350\276\276\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\345\207\272\345\217\221\345\237\216\345\270\202", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "\351\243\236\346\234\272\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "\345\207\272\345\217\221\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "\346\212\265\350\276\276\345\237\216\345\270\202", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Dialog", "\350\210\252\347\217\255\345\217\267\347\240\201", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog", "\350\210\261\344\275\215\347\255\211\347\272\247", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Dialog", "\344\271\230\345\256\242\351\205\215\351\242\235", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Dialog", "\345\207\272\345\217\221\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Dialog", "\350\210\252\347\250\213\351\234\200\346\227\266", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Dialog", "\345\217\257\351\200\211\344\275\231\351\242\235", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Dialog", "\346\234\272\347\245\250\344\273\267\346\240\274", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Dialog", "\346\227\205\345\256\242\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Dialog", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Dialog", "\350\257\201\344\273\266\345\217\267", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Dialog", "\346\211\213\346\234\272\345\217\267", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("Dialog", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("Dialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
