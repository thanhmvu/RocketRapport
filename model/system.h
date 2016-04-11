#ifndef SYSTEM_H
#define SYSTEM_H
#include "account.h"
#include "dbtool.h"
#include "dbtablerranch.h"
#include <string>
#include <vector>
#include <iostream>
class DBTableRRanch;
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
    std::vector<std::string> usernames;
    DBTool dTool;
    DBTableRRanch dbtr;
    bool gui;
    bool textUi;
    bool loggedIn;

    void openDatabase();
public:
    System();
    ~System();

    void login();
    void createAccount();

    Account* getCurrentUser();
    void setCurrentUser(Account* cUser);
    std::vector<Account*> getAccountList();
    void setAccountList(std::vector<Account*> aList);
    std::vector<std::string> getUsernames();
    void addUsername(std::string uName);
    void removeUsername(std::string uName);
    bool getLoggedIn();
    void setLoggedIn(bool logged);

};

#endif // SYSTEM_H
