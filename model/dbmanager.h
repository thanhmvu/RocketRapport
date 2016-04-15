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

    //Add methods
    bool addUser(const QVariant &AcntID, const QVariant &FrstName,const QVariant &LstName,   //This method is already configured to add in Account objects with their associated data fields
                 const QVariant &GrpID,const QVariant &ScrpBkID,const QVariant &BlogID,
                 const QVariant &TweetID);
    bool addGroup(const QVariant &GrpID, const QVariant &GrpAdmnId, bool actStatus,          //I'm going to skip over some of the add to table methods and move to messages, which I know Mike is about to work on
                  const QVariant GrpName, const QVariant FeedID);
    bool addChat(const QVariant &AccountID, const QVariant &ChatID, const QVariant &sender);
    bool addMessage(const QVariant &ChatID,const QVariant &MessageID, const QVariant &DateTime,
                    const QVariant text,const QVariant imageURL,const QVariant receiver);

    bool addColumn(const QString name, const QString type);
    bool find(const QVariant &UsrID, const QVariant &table);
    bool printAllRows(const QString &column);
    bool deleteName(const QVariant &UsrID);

    bool saveAccountInfo();

    bool rmAll();
    //We also need some kind of means of pulling information from the database one row at a time

};

#endif // DBMANAGER_H
