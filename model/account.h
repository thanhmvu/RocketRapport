#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include "scrapbook.h"
#include "chat.h"
#include "group.h"
#include "blog.h"
#include "tweet.h"

class Group;

/**
 * @brief The Account class will be used to store user data. The account will be inherited by children classes such as system admins, current guests, and past guests.
 */
class Account
{
    Scrapbook* myScrapbook;
    std::vector<Chat*> myChats;
    Tweet* t = new Tweet();
    std::vector<Account*> friendList;
    std::vector<Group*> groups;
    Blog* userBlog = new Blog();
    // The follwing "block" is used to store the user's personal information
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
    int groupID;


public:
    Account();
    Account(std::string usrName);

    static int id_cnt;

    // Functions to be used to manipulate the vectors that each account contains.
    void addChat(Chat* newChat);
    void removeChat(Chat* badChat);
    void addFriend(Account* newFriend);
    void removeFriend(Account* badFriend);
    void joinGroup(Group* newGroup);
    void leaveGroup(Group* badGroup);

    // Getter and Setters for the Account private members
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
    int getAccountID();
    int getGroupID();
    void setPhoneNumber(int number);
    Blog* getUserBlog();
    Tweet* getUserTweet();
};

#endif // ACCOUNT_H
