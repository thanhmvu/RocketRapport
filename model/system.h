#ifndef SYSTEM_H
#define SYSTEM_H
#include "account.h"
#include "dbtool.h"
#include "dbtablerranch.h"
#include "dbmanager.h"
#include <string>
#include <vector>
#include <iostream>
class DBTableRRanch;
class DbManager;

/**
 * @brief The System class will be used to store information to and retrive information from the database, operating much like the PlayerGameHistory class did in the lab
 * assignments.
 * I'm going to be reusing a lot of functionality from the PGH in this class.
 * The flow will work like this:
 * User starts program ->
 */
class System
{
    Account* currentUser;
    std::vector<Account*> accountList;
    std::vector<Group*> groups;
    //DbManager* dbm = new DbManager("./gProjectDB.db"); //Make sure this line works
    bool gui;
    bool textUi;
    bool loggedIn;

    void openDatabase();
public:
    System();
    ~System();

    void login();
    bool createAccount(std::string username, std::string password, std::string firstname, std::string lastname);

    void addGroup(Group* newGroup);
    void removeGroup(Group* oldGroup);
    void addAccount(Account* newAccount);
    void removeAccount(Account* oldAccount);
    bool usernameExist(std::string username);

    Account* getCurrentUser();
    std::vector<Account*> getAccountList();
    void setCurrentUser(Account* cUser);
    void setAccountList(std::vector<Account*> aList);
    bool getLoggedIn();
    void setLoggedIn(bool logged);
    std::vector<Group*> getGroups();

};

#endif // SYSTEM_H
