#ifndef OPERATEDB_H
#define OPERATEDB_H

#include <QString>
#include <QDate>
#include <QDomElement>

//update the whole database in 30 days from today
bool updateDB();

//create single day's database file for the specific date
bool createDB(QString date);

//query the database and return the DOM tree which contains all the flights information at the same day
bool queryDB(const QString &, const QString &, const QDate &, QDomElement* &); 

//modify the database file according to the given parameter ( two conditions )
bool editDB(QString depc, QString arrc, QString date, QString ID, QString tag, QString value, QString cabin);

//create and maintain USER information database (book tickets)
//parameter flyInfo contains: "depcity arrcity date flightID"
bool manageUserDB(const QString &name, const QString &identy, const QString &num, int amount, const QString &flyInfo);

//maintain USER information database (return tickets)
//bool manageUserDB(const QString &name, const QString &identy, QDomElement* &elem);

#endif