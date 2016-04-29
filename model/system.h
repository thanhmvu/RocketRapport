#ifndef SYSTEM_H
#define SYSTEM_H
#include "account.h"
//#include "dbtool.h"
#include "dbmanager.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <QDebug>
#include <QString>

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
    std::map<QString, Account*> accounts; //Used to associate stored account objects with their corresponding usernames
    std::vector<Group*> groups;
    DbManager* dbm /*= new DbManager("./gProjectDB.db")*/; //Make sure this line works
    bool gui;
    bool textUi;
    bool loggedIn;
    std::string html_path;

    void openDatabase();


public:
    System(const QString &path);
    ~System();

    // getters
    Account* getCurrentUser();
    Account* getAccountByUsername(QString usrname);
    Account* getAccountByID(int ID);
    bool getLoggedIn();
    std::vector<Group*> getGroups();
    std::map <QString, Account*> getAllAccounts();
    DbManager* getDbm();   //Return the dbm the system is using
    int numberOfAccount();
    std::string getHtmlPath();

    // setter
    void setCurrentUser(Account* cUser);
    void setLoggedIn(bool logged);
    void setAccountMap(std::map<QString, Account*> aMap);


    bool login(QString username, QString password);
    bool createAccount(QString username, QString password,
                       QString firstname, QString lastname);
    bool createGroup(QString gName);
    void addGroup(Group* newGroup);
    void insertGroup(Group* newGroup);
    void removeGroup(Group* oldGroup);
    void pairGroupWithUser(Group* group,Account* account);
    void addAccount(Account* newAccount);
    void removeAccount(Account* oldAccount);
    bool usernameExist(QString username);
    void retrieveAllAccounts();
    void retrieveAllGroups();
    void retrieveAllUsersInGroup(Group* groupToAdd);
    void addAccountsToGroup(Group* group);
    void deleteAllAccounts();
    void refreshSystem();

    //    bool addChat(const int &AccountID,
    //                 const int &ChatID, const QString &sender)

    // for debugging purpose
    void printAllUsernames();
    static int getIdCnt(){ return id_cnt; };
    static void printAllIdCnt();
};

#endif // SYSTEM_H
