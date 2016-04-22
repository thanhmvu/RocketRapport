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
private:
    static int id_cnt;
    int id;
    Account* currentUser;
    std::map<std::string, Account*> accounts; //Used to associate stored account objects with their corresponding usernames
    std::map<int, std::string> *usernameList; //This is the map being used in the database.
    std::vector<Group*> groups;
    DbManager* dbm /*= new DbManager("./gProjectDB.db")*/; //Make sure this line works
    bool gui;
    bool textUi;
    bool loggedIn;

    void openDatabase();
public:
    System(const QString &path);
    ~System();

    bool login(std::string username, std::string password);
    bool createAccount(std::string username, std::string password, std::string firstname, std::string lastname);

    void addGroup(Group* newGroup);
    void removeGroup(Group* oldGroup);
    void addAccount(Account* newAccount);
    void removeAccount(Account* oldAccount);
    bool usernameExist(std::string username);
    bool addChat(const int &AccountID,
                 const int &ChatID, const std::string &sender);

    void loadAccounts(std::map<int, std::string> *one); //Method called in the constructor that will be used to create a list of accounts accessible to the user.
    void fillAccountsMap();

    Account* getCurrentUser();
    Account* getAccountByUsername(std::string usrname);
    bool getLoggedIn();
    std::vector<Group*> getGroups();
    std::map <std::string, Account*> getAllAccounts();
    DbManager* getDbm();   //Return the dbm the system is using

    void setCurrentUser(Account* cUser);
    void setLoggedIn(bool logged);
    void setAccountMap(std::map<std::string, Account*> aMap);

    int numberOfAccount();

    //Used for testing purposes
    void printAllUsernames();


    void loadAllAccounts();

};

#endif // SYSTEM_H
