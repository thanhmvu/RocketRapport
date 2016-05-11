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
    std::string blogTweetUsername;

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
    /**
     * @brief Account::Account basic constructor used to create a new account object.
     * @param newdbm Pointer to a databasemanager object that the accoutn will use for data storage and retrieval purposes
     */
    Account(DbManager *newdbm);
    /**
     * @brief Account::Account Constructor used to specify a username
     * @param usrName username for a new account object
     * @param newdbm Database manager object pointer used for data storage and retrieval purposes.
     */
    Account(QString usrName, DbManager *newdbm);
    /**
     * @brief Account constructor to rebuild an instance of existing account.
     * This contructor give all controls to the user
     * Thus, one possible risk is duplicate ID
     * Each of the parameters represents a field present in the accounts table of the program
     */
    Account(int accID,     QString usrname,    QString pw,
            int scrpBkID,   int blogID,         int tweetID,
            QString firstname,  QString lastname, DbManager *newdbm);
    /**
     * @brief Account::~Account Destructor for the Account object. Deletes all chats, the user's blog, and the user's scrapbook
     */
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
//    void addFriend(Account* newFriend); //No code for this method
//    void removeFriend(Account* badFriend); //No code for this method
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
    QString     getFullName();
    QString     getGender();
    QString     getAbout();
    QString     getAddress();
    QString     getProfilePicture();
    QString     getMostRecentEmployer();
    std::vector<Chat*>      getMyChats();
    std::vector<Chat*>      getChatVector();
    std::vector<Account*>   getFriendList();
    std::vector<Group*>     getGroups();
    std::string getProfileUsername();
    int getIndexOfProfile();
    Chat * getChatByPartnerName(QString talking_to_usr_name);
    std::string getBlogTweetUsername();

    System*     getSystem();

    // setters
    /**
     * @brief Setter for the current guest boolean.
     */
    void setIsCurrentGuest(bool cGuest);
    /**
     * @brief Setter for the past guest boolean.
     */
    void setIsPastGuest(bool pGuest);
    /**
     * @brief Setter for the system admin boolean.
     */
    void setIsSystemAdmin(bool sAdmin);
    /**
     * @brief Setter for the group admin boolean.
     */
    void setIsGroupAdmin(bool gAdmin);

    /**
     * @brief Setter for the user's username.
     */
    void setUsername(QString uName);
    /**
     * @brief Setter for the user's password.
     */
    void setPassword(QString pWord);
    /**
     * @brief Setter for the user's scrapbook.
     */
    void setMyScrapbook(Scrapbook* sBook);
    /**
     * @brief Setter for the user's first name.
     */
    void setFirstName(QString fName);
    /**
     * @brief Setter for the user's last name.
     */
    void setLastName(QString lName);
    /**
     * @brief Setter for the user's gender.
     */
    void setGender(QString gend);
    /**
     * @brief Setter for the user's "about yourself" information.
     */
    void setAbout(QString about);
    /**
     * @brief Setter for the user's home address.
     */
    void setAddress(QString address);
    /**
     * @brief Setter for the user's profile picture.
     */
    void setProfilePicture(QString picture);
    /**
     * @brief Setter for the user's most recent employer.
     */
    void setMostRecentEmployer(QString employer);
    /**
     * @brief Setter for the user's age.
     */
    void setAge(int age);
    /**
     * @brief Setter for the user's phone number.
     */
    void setPhoneNumber(int number);
    /**
     * @brief Setter that sets the System object.
     */
    void setSystem(System* newSystem);
    /**
     * @brief Setter for the profile username variable.
     */
    void setProfileUsername(std::string name);
    void setBlogTweetUsername(std::string name);
    /**
     * @brief Setter for the index of profile.
     */
    void setIndexOfProfile(int index);

    /**
     * @brief Changes the user to a current guest.
     */
    void promoteToCurrentGuest();
    /**
     * @brief Changes the user to a past guest.
     */
    void promoteToPastGuest();
    /**
     * @brief Changes the user to a system admin.
     */
    void promoteToSystemAdmin();
    /**
     * @brief Changes the user to a group admin.
     */
    void promoteToGroupAdmin();

    // Functions specific to a current guest.
//    void departRanch();
    /**
     * @brief Getter for the Blog pointer.
     */
    Blog*   getMyBlog();
    /**
     * @brief Getter for the Tweet pointer.
     */
    Tweet*  getMyTweet();

    /**
     * @brief Setter for the Blog pointer.
     */
    void setMyBlog(Blog* myBlog);
    /**
     * @brief Setter for the Tweet pointer.
     */
    void setMyTweet(Tweet* myTweet);


//    void setMonthDeparted(int month);
//    void setDayDeparted(int day);
//    void setYearDeparted(int year);

    // Functions specific to a past guest.
//    std::vector<QString> getProjectsWorkedOn();
//    void addProject(QString projectName);
//    void removeProject(QString projectName);

//    int getMonthDeparted();
//    int getDayDeparted();
//    int getYearDeparted();

    // Functions specific to a system admin.
//    void addGroup(Group* newGroup);
//    void addAccount(Account* newAccount, QString username, QString firstName, QString lastName);
//    void deleteGroup(Group* oldGroup);
//    void deleteAccount(Account* oldAccount);
//    void deleteBlogPost(Blog* targetBlog, BlogPost* badPost);
//    void deleteTweetPost(Tweet* targetTweet, TweetPost* badPost);
//    void deleteScrapbookPost(Scrapbook* targetScrapbook, ScrapbookPost* badPost);

    // Funtions for testing
    /**
     * @brief getIdCnt Method used to retrieve the current static id_cnt
     */
    static int getIdCnt(){ return id_cnt; };
};

#endif // ACCOUNT_H
