#ifndef SYSTEM_H
#define SYSTEM_H
#include "account.h"
#include "dbtool.h"
#include "dbmanager.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

class Group;
class Account;

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

    Account* getCurrentUser();
    bool getLoggedIn();
    std::vector<Group*> getGroups();
    std::map <std::string, Account*> getAllAccounts();

    void setCurrentUser(Account* cUser);
    void setLoggedIn(bool logged);
    void setAccountMap(std::map<std::string, Account*> aMap);

    //Used for testing purposes
    void printAllUsernames();

};

#endif // SYSTEM_H
