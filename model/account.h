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
class DbManager; //Going to try saving chat information directly using dbm

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
    std::vector<Chat*> myChats;
    std::vector<Account*> friendList;
    std::vector<Group*> groups;
    std::string username;
    std::string password;
    std::string firstName;
    std::string lastName;
    std::string gender;
    std::string aboutYourself;
    std::string homeAddress;
    std::string profilePicture;
    std::string mostRecentEmployer;
    int age;
    int phoneNumber;
    int accountID;

    // Private members specific to a current guest.
    Blog* myBlog;
    Tweet* myTweet;

    // Private members specific to a past guest.
    std::vector<std::string> projectsWorkedOn;
    int monthDeparted;
    int dayDeparted;
    int yearDeparted;

    // Private members specific to a system admin.
    System* theSystem;
    DbManager* dbm;

public:
    Account();
    Account(std::string usrName);
    Account(int accID,     std::string usrname,    std::string pw,
            int scrpBkID,   int blogID,         int tweetID,
            std::string firstname,  std::string lastname);

    //Functions to obtain information from the database
    void retrieveAllBlogPosts();
    void retrieveAllTweets();
    void retrieveAllMessages();

    // Functions specific to a general account.
    void addChat(Chat* newChat);
    void removeChat(Chat* badChat);
    void addFriend(Account* newFriend);
    void removeFriend(Account* badFriend);
    void joinGroup(Group* newGroup);
    void leaveGroup(Group* badGroup);

    // getters
    bool    getIsCurrentGuest();
    bool    getIsPastGuest();
    bool    getIsSystemAdmin();
    bool    getIsGroupAdmin();

    int     getAge();
    int     getPhoneNumber();
    int     getAccountID();
    std::string     getUsername();
    std::string     getPassword();
    Scrapbook*      getMyScrapbook();
    std::string     getFirstName();
    std::string     getLastName();
    std::string     getGender();
    std::string     getAbout();
    std::string     getAddress();
    std::string     getProfilePicture();
    std::string     getMostRecentEmployer();
    std::vector<Chat*>      getMyChats();
    std::vector<Account*>   getFriendList();
    std::vector<Group*>     getGroups();
    System*     getSystem();

    // setters
    void setIsCurrentGuest(bool cGuest);
    void setIsPastGuest(bool pGuest);
    void setIsSystemAdmin(bool sAdmin);
    void setIsGroupAdmin(bool gAdmin);

    void setUsername(std::string uName);
    void setPassword(std::string pWord);
    void setMyScrapbook(Scrapbook* sBook);
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setGender(std::string gend);
    void setAbout(std::string about);
    void setAddress(std::string address);
    void setProfilePicture(std::string picture);
    void setMostRecentEmployer(std::string employer);
    void setAge(int age);
    void setPhoneNumber(int number);
    void setSystem(System* newSystem);

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
    std::vector<std::string> getProjectsWorkedOn();
    void addProject(std::string projectName);
    void removeProject(std::string projectName);

    int getMonthDeparted();
    int getDayDeparted();
    int getYearDeparted();

    // Functions specific to a system admin.
    void addGroup(Group* newGroup);
    void addAccount(Account* newAccount, std::string username, std::string firstName, std::string lastName);
    void deleteGroup(Group* oldGroup);
    void deleteAccount(Account* oldAccount);
    void deleteBlogPost(Blog* targetBlog, BlogPost* badPost);
    void deleteTweetPost(Tweet* targetTweet, TweetPost* badPost);
    void deleteScrapbookPost(Scrapbook* targetScrapbook, ScrapbookPost* badPost);

    // Funtions for testing
    static int getIdCnt();
};

#endif // ACCOUNT_H
