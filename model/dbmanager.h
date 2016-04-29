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
//#include "feed.h"
//#include "feedpost.h"
#include "scrapbook.h"
#include "scrapbookpost.h"
#include "chat.h"
#include "message.h"
#include "group.h"

//We're going to need to forward declare the classes that use a dbm object
class Account;
class Chat;
class Blog;
class Tweet;
//class Feed;
class System;
class Group;
class Scrapbook;

class DbManager
{
private:
    static int id_cnt;
    int id;
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);
    ~DbManager();
    DbManager();

    //////////////////////////////// Add methods
    //This method is already configured to add in Account objects with their associated data fields
    bool addUser(const QVariant &AcntID  , const QVariant &FrstName,
                 const QVariant &LstName , const QVariant &ScrpBkID,
                 const QVariant &BlogID  , const QVariant &TweetID,
                 const QVariant &UserName, const QVariant &passWord);

    bool addGroup   (const QVariant &GrpID      , const QVariant &GrpAdmnId,
                     bool actStatus             , const QVariant &GrpName,
                     const QVariant &FeedID);

//    bool addFeedPost(const QVariant &FeedPostID , const QVariant &FeedID,
//                     const QVariant &timeDate   , const QVariant &text);

    bool addBlogPost(const QVariant &BlogPostID , const QVariant &BlogID,
                     const QVariant &timeDate   , const QVariant &text);

    bool addChat    (const QVariant &AccountID  , const QVariant &ChatID,
                     const QString &receiver);

    bool addMessage (const QVariant &ChatID     , const QVariant &MessageID,
                     const QVariant &DateTime   , const QVariant &text);

    bool addTweetPost(const QVariant &TweetPostID, const QVariant &TweetID,
                      const QVariant &TimeDate   , const QVariant &Text);

    bool addGroupUserPair(const QVariant GroupID, const QVariant UserID);



    // not implemented yet
//    bool addProfile (const QVariant &AcntID, const QVariant &Gender, const QVariant &AbtYslf, const QVariant HmAddress,
//                     const QVariant &MstRcntEmplyr, const QVariant age);                     //The profile is the personalized list of a user's information



    //////////////////////////////// Methods used to modify the existing contents of the table
    bool addColumn(const QString name, const QString type);
    bool find(const QVariant &UsrID, const QVariant &table); //Changed to static for debugging purposes
    bool printAllRows(const QString &column);
    bool deleteName(const QVariant &UsrID);

    //////////////////////////////// Retrieve methods
    int retrieveIntInfo(const QString &fieldName, const QString &tableName, const QString &checkName, const QVariant &ID);                     //I'm going to be using two different overloaded methods that can obtain information from the database given a query.
    QString retrieveStringInfo(const QString &fieldName, const QString &tableName, const QString &checkName, const QVariant &ID);       //These methods will be used in pulling information from the database.
    void retrieveAllAccounts(std::map<QString, Account*> &accounts);
    void retrieveAllBlogPosts(Blog *userBlog);
    void retrieveAllTweets(Tweet *userTweet);
//    void retrieveAllFeedPosts(Feed *groupFeed);
    void retrieveAllMessages(Chat *userChat);
    void retrieveAllScbkPosts(Scrapbook *userScBook);
    void retrieveAllChats(Account *user);
    void retrieveAllGroups(System *newSystem);
    void retrieveAllUsersInGroup(Group *group);

    bool updateTable(const QVariant tableName, const QVariant columnToChange, const QVariant newColumnValue,
                     const QVariant checkField, const QVariant checkFieldValue);
    bool rmAllAccounts();
    void deleteTable(const QVariant tableName);

};

#endif // DBMANAGER_H
