#ifndef SYSTEM_H
#define SYSTEM_H
#include "account.h"
//#include "dbtool.h"
#include "dbmanager.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

class Group;
class Account;
class DbManager;
/**
 * @brief The System class will be used to store information to and retrive information from the database, operating much like the PlayerGameHistory class did in the lab
 * assignments.
 * I'm going to be reusing a lot of functionality from the PGH in this class.
 * The flow will work like this:
 * User starts program -> Accounts are loaded to the system from database
 */
class System
{
    Account* currentUser;
    std::map<std::string, Account*> accounts;
    //std::map<int, std::__cxx11::string> *usernameList = new std::map<int, std::__cxx11::string>;
    std::map<int, std::__cxx11::string> *usernameList;
    std::vector<Group*> groups;
    DbManager* dbm = new DbManager("./gProjectDB.db"); //Make sure this line works
    bool gui;
    bool textUi;
    bool loggedIn;

    void openDatabase();
public:
    System();
    ~System();

    bool login(std::string username, std::string password);
    bool createAccount(std::string username, std::string password, std::string firstname, std::string lastname);

    void addGroup(Group* newGroup);
    void removeGroup(Group* oldGroup);
    void addAccount(Account* newAccount);
    void removeAccount(Account* oldAccount);
    bool usernameExist(std::string username);

    void loadAccounts(std::map<int, std::__cxx11::string> *one); //Method called in the constructor that will be used to create a list of accounts accessible to the user.

    Account* getCurrentUser();
    bool getLoggedIn();
    std::vector<Group*> getGroups();
    std::map <std::string, Account*> getAllAccounts();

    void setCurrentUser(Account* cUser);
    void setLoggedIn(bool logged);
    void setAccountMap(std::map<std::string, Account*> aMap);

    int numberOfAccount();
    //Used for testing purposes
    void printAllUsernames();

};

#endif // SYSTEM_H
