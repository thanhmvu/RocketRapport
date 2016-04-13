#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include <string.h>
#include <QSqlError>
#include <QString>
#include <stdio.h>
#include <iostream>

class DbManager
{
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);
    bool addUser(const QVariant &AcntID, const QVariant &FrstName,const QVariant &LstName,   //This method is already configured to add in Account objects with their associated data fields
                 const QVariant &GrpID,const QVariant &ScrpBkID,const QVariant &BlogID,
                 const QVariant &TweetID);
    bool addGroup(const QVariant &GrpID, const QVariant &GrpAdmnId, bool actStatus,
                  const QVariant GrpName, const QVariant FeedID);
    bool addColumn(const QString name, const QString type);
    bool find(const QVariant &UsrID);
    bool printAllRows(const QString &column);
    bool deleteName(const QVariant &UsrID);
    bool rmAll();

};

#endif // DBMANAGER_H
