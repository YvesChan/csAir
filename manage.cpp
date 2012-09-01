#include "manage.h"
#include "csair.h"
#include "operateDB.h"
#include <QDialog>
#include <QTableWidget>
#include <QDomDocument>
#include <QFile>
#include <QLineEdit>
#include <QMessageBox>
#include <QInputDialog>
#include <QPushButton>
#include <QString>
#include <QModelIndex>
#include <QPoint>
#include <QTextStream>
#include <QDebug>

Manager::Manager(csAir *parent) : QDialog(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setColumnCount(7);
	ui.tableWidget->setColumnWidth(0, 60);
	ui.tableWidget->setColumnWidth(1, 60);
	ui.tableWidget->setColumnWidth(2, 90);
	ui.tableWidget->setColumnWidth(3, 60);
	ui.tableWidget->setColumnWidth(4, 40);
	ui.tableWidget->setColumnWidth(5, 50);
	ui.tableWidget->setColumnWidth(6, 58);
	ui.tableWidget->verticalHeader()->setVisible(false);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

	//establish conncection between database and DOM tree
	QFile file("Resources\\userDB.xml");
	if(!file.open(QFile::ReadOnly) || !doc.setContent(&file)){
		QMessageBox m;
		m.setText("�޷���ȡ�û�����");
		m.exec();
		close();
		return;
	} 
	file.close();

	connect(ui.search, SIGNAL(clicked()), this, SLOT(searchClicked()));
}

void Manager::searchClicked(){
	if(ui.name->text() == ""){
		QMessageBox m;
		m.setText("����������");
		m.exec();
		return;
	} 
	if(ui.identy->text() == ""){
		QMessageBox m;
		m.setText("������֤����");
		m.exec();
		return;
	} 

	int row = 0;
	bool find = false;
	QDomElement elem = doc.documentElement();
	for(elem = elem.firstChildElement(); !elem.isNull(); elem = elem.nextSiblingElement()){
		if(elem.attribute("name") == ui.name->text() && elem.attribute("identy") == ui.identy->text()){
			find = true;
			ui.tableWidget->insertRow(ui.tableWidget->rowCount());
			QTableWidgetItem* depc = new QTableWidgetItem(toChi(elem.attribute("depCity")));
			QTableWidgetItem* arrc = new QTableWidgetItem(toChi(elem.attribute("arrCity")));
			QTableWidgetItem* date = new QTableWidgetItem(elem.attribute("date"));
			QTableWidgetItem* ID = new QTableWidgetItem(elem.attribute("ID"));
			QTableWidgetItem* cabin = new QTableWidgetItem(elem.attribute("cabin"));
			QTableWidgetItem* amount = new QTableWidgetItem(elem.attribute("amount"));
			QPushButton* ret = new QPushButton("��Ʊ");
			ui.tableWidget->setItem(row, 0, depc);
			ui.tableWidget->setItem(row, 1, arrc);
			ui.tableWidget->setItem(row, 2, date);
			ui.tableWidget->setItem(row, 3, ID);
			ui.tableWidget->setItem(row, 4, cabin);
			ui.tableWidget->setItem(row, 5, amount);
			ui.tableWidget->setCellWidget(row, 6, ret);
			row ++;

			connect(ret,SIGNAL(clicked()),this,SLOT(returnClicked()));
		}
	}

	if(!find){
		QMessageBox m;
		m.setText("������֤���Ŵ�������������");
		m.exec();
	}

}

void Manager::returnClicked(){
	QPushButton* sender = qobject_cast<QPushButton *>(QObject::sender());
	if(sender == NULL)return;
	QModelIndex mindex = ui.tableWidget->indexAt(QPoint(sender->frameGeometry().x(), sender->frameGeometry().y()));
	int clickRow = mindex.row();
	QTableWidgetItem* item = ui.tableWidget->item(clickRow, 5);       //get current amount
	int currAmo = item->text().toInt();
	QString ID = ui.tableWidget->item(clickRow, 3)->text();      //get flightID

	bool isOK = false;
	int retNum = QInputDialog::getInt(this, "ȷ����Ʊ", "��������Ʊ����", 1, 1, currAmo, 1, &isOK);
	if(isOK){
		//change window view and date(DOM) in memory
		QDomElement elem, root = doc.documentElement();
		for(elem = root.firstChildElement(); !elem.isNull(); elem = elem.nextSiblingElement()){
			if(elem.attribute("ID") == ID && elem.attribute("identy") == ui.identy->text()){
				if(retNum == currAmo){          //return all tickets of the flight
					root.removeChild(elem);      //delete information from database file
					ui.tableWidget->removeRow(clickRow);       //change table view
				}
				else {               //only modify information in table view and database
					elem.setAttribute("amount", currAmo - retNum);
					item->setText(QString::number(currAmo - retNum));
					qDebug() << elem.attribute("amount");
				}
				break;
			}
		}

		//sync to database file
		QFile file("Resources\\userDB.xml");
		if(!file.open(QFile::WriteOnly | QFile::Truncate)){
			QMessageBox::information(this, "csAir", "�޷�д���û�����");
			return;
		}
		QTextStream out(&file);
		doc.save(out,4);
		file.close();

		//modify the system's database
		QString dc = toEng(ui.tableWidget->item(clickRow, 0)->text());
		QString ac = toEng(ui.tableWidget->item(clickRow, 1)->text());
		if(!editDB(dc, ac, ui.tableWidget->item(clickRow, 2)->text(), ui.tableWidget->item(clickRow, 3)->text(),
			"remain", QString::number(retNum), ui.tableWidget->item(clickRow, 4)->text())){
				QMessageBox::information(this, "csAir", "�޷�д��ϵͳ����");
				return;
		}

		QMessageBox::information(this, "csAir", "��Ʊ�ɹ�");
	}
}

QString Manager::toChi(QString s){
	if(s == "Guangzhou")return "����";
	if(s == "Shanghai")return "�Ϻ�";
	if(s == "Beijing")return "����";
	if(s == "Haerbin")return "������";
	if(s == "Chengdu")return "�ɶ�";
	if(s == "Chongqing")return "����";
	if(s == "HongKong")return "���";
	if(s == "Dalian")return "����";
	if(s == "Tianjin")return "���";
}

QString Manager::toEng(QString s){
	if(s == "����")return "Guangzhou";
	if(s == "�Ϻ�")return "Shanghai";
	if(s == "����")return "Beijing";
	if(s == "������")return "Haerbin";
	if(s == "�ɶ�")return "Chengdu";
	if(s == "����")return "Chongqing";
	if(s == "���")return "HongKong";
	if(s == "����")return "Dalian";
	if(s == "���")return "Tianjin";
}