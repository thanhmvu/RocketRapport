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
#include <QDateTime>
#include "account.h"
#include "blog.h"
#include "blogpost.h"
#include "tweet.h"
#include "tweetpost.h"
#include "scrapbook.h"
#include "scrapbookpost.h"
#include "chat.h"
#include "message.h"

class Account;

class DbManager
{
private:
    static int id_cnt;
    int id;
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);

    //Add methods
    static bool addUser(const QVariant &AcntID, const QVariant &FrstName,const QVariant &LstName,   //This method is already configured to add in Account objects with their associated data fields
                 const QVariant &ScrpBkID,const QVariant &BlogID,
                 const QVariant &TweetID, const QVariant &UserName, const QVariant &passWord);
    static bool addProfile (const QVariant &AcntID, const QVariant &Gender, const QVariant &AbtYslf, const QVariant HmAddress,
                     const QVariant &MstRcntEmplyr, const QVariant age);                     //The profile is the personalized list of a user's information
    static bool addGroup(const QVariant &GrpID, const QVariant &GrpAdmnId, bool actStatus,          //I'm going to skip over some of the add to table methods and move to messages, which I know Mike is about to work on
                  const QVariant &GrpName, const QVariant &FeedID);
    static bool addFeedPost(const QVariant &FeedID, const QVariant &feedPostID, const QVariant &feedPostText);
    static bool addBlogPost(const QVariant &BlogID, const QVariant &BlogPostID, const QVariant &timeDate, const QVariant &test);
    static bool addChat(const QVariant &AccountID, const QVariant &ChatID, const QVariant &sender);
    static bool addMessage(const QVariant &ChatID,const QVariant &MessageID, const QVariant &DateTime,
                    const QVariant text);

    //Methods used to modify the existing contents of the table
    bool addColumn(const QString name, const QString type);
    static bool find(const QVariant &UsrID, const QVariant &table); //Changed to static for debugging purposes
    bool printAllRows(const QString &column);
    bool deleteName(const QVariant &UsrID);

    //Retrieve methods
    int retrieveIntInfo(const QString &fieldName, const QString &tableName, const QString &checkName, const QVariant &ID);                     //I'm going to be using two different overloaded methods that can obtain information from the database given a query.
    std::string retrieveStringInfo(const QString &fieldName, const QString &tableName, const QString &checkName, const QVariant &ID);       //These methods will be used in pulling information from the database.
//    void retrieveAllAccounts(std::map<int,std::string> *one); //Store each username with its associated user ID. Use this information to obtain the other IDs
    void retrieveAllAccounts(std::map<std::string, Account*> &accounts);
    void retrieveAllBlogPosts(Blog *userBlog);
    void retrieveAllTweets(Tweet *userTweet);
    void retrieveAllMessages(Chat *userChat);
    void retrieveAllScbkPosts(Scrapbook *userScBook);

    bool rmAllAccounts();

};

#endif // DBMANAGER_H
