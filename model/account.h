#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include <ctime>
#include "scrapbook.h"
#include "chat.h"
#include "group.h"
#include "blog.h"
#include "tweet.h"
#include "system.h"

class System;
class Group;

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

    // Private members specific to a group admin.
//    Group* myGroup; // WARNING: there can be multiple groups


public:
    Account();
    Account(std::string usrName);

    bool getIsCurrentGuest();
    bool getIsPastGuest();
    bool getIsSystemAdmin();
    bool getIsGroupAdmin();
    void setIsCurrentGuest(bool cGuest);
    void setIsPastGuest(bool pGuest);
    void setIsSystemAdmin(bool sAdmin);
    void setIsGroupAdmin(bool gAdmin);
    void promoteToCurrentGuest();
    void promoteToPastGuest();
    void promoteToSystemAdmin();
    void promoteToGroupAdmin();

    // Functions specific to a general account.
    void addChat(Chat* newChat);
    void removeChat(Chat* badChat);
    void addFriend(Account* newFriend);
    void removeFriend(Account* badFriend);
    void joinGroup(Group* newGroup);
    void leaveGroup(Group* badGroup);
    std::string getUsername();
    void setUsername(std::string uName);
    std::string getPassword();
    void setPassword(std::string pWord);
    Scrapbook* getMyScrapbook();
    void setMyScrapbook(Scrapbook* sBook);
    std::vector<Chat*> getMyChats();
    std::vector<Account*> getFriendList();
    std::vector<Group*> getGroups();
    std::string getFirstName();
    void setFirstName(std::string fName);
    std::string getLastName();
    void setLastName(std::string lName);
    std::string getGender();
    void setGender(std::string gend);
    std::string getAbout();
    void setAbout(std::string about);
    std::string getAddress();
    void setAddress(std::string address);
    std::string getProfilePicture();
    void setProfilePicture(std::string picture);
    std::string getMostRecentEmployer();
    void setMostRecentEmployer(std::string employer);
    int getAge();
    void setAge(int age);
    int getPhoneNumber();
    void setPhoneNumber(int number);
    int getAccountID();
//    int getGroupID(); // WARNING: there can be multiple groups

    // Functions specific to a current guest.
    void departRanch();
    Blog* getMyBlog();
    void setMyBlog(Blog* myBlog);
    Tweet* getMyTweet();
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
    void deleteGroup(Group* oldGroup);
    void addAccount(Account* newAccount, std::string username, std::string firstName, std::string lastName);
    void deleteAccount(Account* oldAccount);
    void deleteBlogPost(Blog* targetBlog, BlogPost* badPost);
    void deleteTweetPost(Tweet* targetTweet, TweetPost* badPost);
    void deleteScrapbookPost(Scrapbook* targetScrapbook, ScrapbookPost* badPost);
    System* getSystem();
    void setSystem(System* newSystem);

    // Functions specific to a group admin.
//    Group* getGroup();
//    void addMember(Account* newMember);
//    void removeMember(Account* oldMember);
//    void editGroupName(std::string name);
};

#endif // ACCOUNT_H
