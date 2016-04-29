#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include <ctime>
#include "scrapbook.h"
#include "dbmanager.h"
#include "chat.h"
#include "group.h"
#include "blog.h"
#include "tweet.h"
#include "system.h"

class System;
class Group;
class Chat;
class DbManager; //Going to try saving chat information directly using dbm
class Blog;
class Tweet;
class Scrapbook;

/**
 * @brief The Account class will be used to store user data. The account will be inherited by children classes such as system admins, current guests, and past guests.
 */
class Account
{
private:
    static int id_cnt;

    bool isCurrentGuest;
    bool isPastGuest;
    bool isSystemAdmin;
    bool isGroupAdmin;

    // Private members specific to a general account
    Scrapbook* myScrapbook;
    std::vector<Chat*> myChats; // the account owns these objects
    std::vector<Account*> friendList; // the account does not own these objects
    std::vector<Group*> groups; // the account does not own these objects
    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString gender;
    QString aboutYourself;
    QString homeAddress;
    QString profilePicture;
    QString mostRecentEmployer;
    int age;
    int phoneNumber;
    int accountID;
    std::string profileUsername;
    int indexOfProfile;

    // Private members specific to a current guest.
    // the account owns these objects
    Blog* myBlog;
    Tweet* myTweet;

    // Private members specific to a past guest.
    std::vector<QString> projectsWorkedOn;
    int monthDeparted;
    int dayDeparted;
    int yearDeparted;

    // Private members specific to a system admin.
    // the account does not own these objects
    System* theSystem;
    DbManager* dbm;

public:
    //Constructors
    Account(DbManager *newdbm);
    Account(QString usrName, DbManager *newdbm);
    Account(int accID,     QString usrname,    QString pw,
            int scrpBkID,   int blogID,         int tweetID,
            QString firstname,  QString lastname, DbManager *newdbm);
    ~Account();

    //Functions to obtain information from the database
    void retrieveAllBlogPosts();
    void retrieveAllTweets();
    void retrieveAllChats();
    void retrieveAllMessages();

    // Functions specific to a general account.
    void addChat(Chat* newChat);
    void insertChat(Chat* newChat);
    void removeChat(Chat* badChat);
    void addFriend(Account* newFriend); //No code for this method
    void removeFriend(Account* badFriend); //No code for this method
    bool joinGroup(Group* newGroup);
    void leaveGroup(Group* badGroup);

    // getters
    bool    getIsCurrentGuest();
    bool    getIsPastGuest();
    bool    getIsSystemAdmin();
    bool    getIsGroupAdmin();

    int     getAge();
    int     getPhoneNumber();
    int     getAccountID();
    QString     getUsername();
    QString     getPassword();
    Scrapbook*      getMyScrapbook();
    QString     getFirstName();
    QString     getLastName();
    QString     getGender();
    QString     getAbout();
    QString     getAddress();
    QString     getProfilePicture();
    QString     getMostRecentEmployer();
    std::vector<Chat*>      getMyChats();
    std::vector<Account*>   getFriendList();
    std::vector<Group*>     getGroups();
    std::string getProfileUsername();
    int getIndexOfProfile();
    Chat * getChatByPartnerName(QString talking_to_usr_name);

    System*     getSystem();

    // setters
    void setIsCurrentGuest(bool cGuest);
    void setIsPastGuest(bool pGuest);
    void setIsSystemAdmin(bool sAdmin);
    void setIsGroupAdmin(bool gAdmin);

    void setUsername(QString uName);
    void setPassword(QString pWord);
    void setMyScrapbook(Scrapbook* sBook);
    void setFirstName(QString fName);
    void setLastName(QString lName);
    void setGender(QString gend);
    void setAbout(QString about);
    void setAddress(QString address);
    void setProfilePicture(QString picture);
    void setMostRecentEmployer(QString employer);
    void setAge(int age);
    void setPhoneNumber(int number);
    void setSystem(System* newSystem);
    void setProfileUsername(std::string name);
    void setIndexOfProfile(int index);

    void promoteToCurrentGuest();
    void promoteToPastGuest();
    void promoteToSystemAdmin();
    void promoteToGroupAdmin();

    // Functions specific to a current guest.
    void departRanch();
    Blog*   getMyBlog();
    Tweet*  getMyTweet();

    void setMyBlog(Blog* myBlog);
    void setMyTweet(Tweet* myTweet);
    void setMonthDeparted(int month);
    void setDayDeparted(int day);
    void setYearDeparted(int year);

    // Functions specific to a past guest.
    std::vector<QString> getProjectsWorkedOn();
    void addProject(QString projectName);
    void removeProject(QString projectName);

    int getMonthDeparted();
    int getDayDeparted();
    int getYearDeparted();

    // Functions specific to a system admin.
    void addGroup(Group* newGroup);
    void addAccount(Account* newAccount, QString username, QString firstName, QString lastName);
    void deleteGroup(Group* oldGroup);
    void deleteAccount(Account* oldAccount);
    void deleteBlogPost(Blog* targetBlog, BlogPost* badPost);
    void deleteTweetPost(Tweet* targetTweet, TweetPost* badPost);
    void deleteScrapbookPost(Scrapbook* targetScrapbook, ScrapbookPost* badPost);

    // Funtions for testing
    static int getIdCnt(){ return id_cnt; };
};

#endif // ACCOUNT_H
