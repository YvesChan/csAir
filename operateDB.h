#ifndef OPERATEDB_H
#define OPERATEDB_H

#include <QString>
#include <QDate>
#include <QDomElement>

bool updateDB();
bool createDB(QString date);
bool queryDB(const QString &, const QString &, const QDate &, QDomElement* &); 



#endif