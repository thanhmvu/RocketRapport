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
#include <map>

class DbManager
{
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);

    //Add methods
    bool addUser(const QVariant &AcntID, const QVariant &FrstName,const QVariant &LstName,   //This method is already configured to add in Account objects with their associated data fields
                 const QVariant &GrpID,const QVariant &ScrpBkID,const QVariant &BlogID,
                 const QVariant &TweetID, const QVariant &UserName, const QVariant &passWord);
    bool addProfile (const QVariant &AcntID, const QVariant &Gender, const QVariant &AbtYslf, const QVariant HmAddress,
                     const QVariant &MstRcntEmplyr, const QVariant age);                     //The profile is the personalized list of a user's information
    bool addGroup(const QVariant &GrpID, const QVariant &GrpAdmnId, bool actStatus,          //I'm going to skip over some of the add to table methods and move to messages, which I know Mike is about to work on
                  const QVariant &GrpName, const QVariant &FeedID);
    bool addFeedPost(const QVariant &FeedID, const QVariant &feedPostID, const QVariant &feedPostText);
    bool addBlogPost(const QVariant &BlogID, const QVariant &BlogPostID, const QVariant &timeDate, const QVariant &test);
    bool addChat(const QVariant &AccountID, const QVariant &ChatID, const QVariant &sender);
    bool addMessage(const QVariant &ChatID,const QVariant &MessageID, const QVariant &DateTime,
                    const QVariant text,const QVariant imageURL,const QVariant receiver);



    bool addColumn(const QString name, const QString type);
    bool find(const QVariant &UsrID, const QVariant &table);
    bool printAllRows(const QString &column);
    bool deleteName(const QVariant &UsrID);

    int retrieveIntInfo(const QString &fieldName, const QString &tableName, const QString &checkName, const QVariant &ID);                     //I'm going to be using two different overloaded methods that can obtain information from the database given a query.
    std::string retrieveStringInfo(const QString &fieldName, const QString &tableName, const QString &checkName, const QVariant &ID);       //These methods will be used in pulling information from the database.
    void retrieveAllAccounts(std::map<int,std::string> *one); //Store each username with its associated user ID. Use this information to obtain the other IDs
    //The above method entails that we may need to change the existing map object in the system or create a new Map entirely.
    bool saveAccountInfo();

    bool rmAll();
    //We also need some kind of means of pulling information from the database one row at a time

};

#endif // DBMANAGER_H
