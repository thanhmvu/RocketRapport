#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include "scrapbook.h"
#include "chat.h"
#include "group.h"
/**
 * @brief The Account class will be used to store user data. The account will be inherited by children classes such as system admins, current guests, and past guests.
 */
class Account
{
    Scrapbook* myScrapbook;
    std::vector<Chat*> myChats;

    std::vector<Account*> friendList;
    std::vector<Group*> groups;

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
    void setPhoneNumber(int number);

};

#endif // ACCOUNT_H
