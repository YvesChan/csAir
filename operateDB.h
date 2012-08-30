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


#endif