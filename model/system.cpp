#include "system.h"

int System::id_cnt = 0;

/**
 * @brief System::System Constructing a new system should access the Database, creating a
 * new Account for each AccountID found in the database. This means we'll also have to store the
 * usernames in the DB as well.
 * @param &path used to specify the path that the system will use to access a database
 *
 * Creates a new usernameList map object (Private field from this class)
 * Constructing a system needs to load all accounts from the Database to the system
 * Need to create some kind of a method that retrieves each account from the database sequentially and adds their corresponding info IDs
 */
System::System(const QString &path)
{
    id = id_cnt;
    id_cnt++;

    loggedIn = false;
    usernameList = new std::map<int, std::string>; //Initializes the userNameList pointer

    dbm = new DbManager(path);
    loadAllAccounts(); //load from the database file
    for(auto pair: accounts){
        Account * acc = pair.second;
        std::cout<< acc->getFirstName() <<"\n";
    }

    std::cout<< "New system created containing " << accounts.size() << " accounts." << std::endl;
}

/**
 * @brief System::~System Destructor
 *
 * Since any new data would be immediately stored to the database,
 * the database is always up-to-date.
 * No need to store data to database here
 *
 * However, the destructor may want to delete any object
 * that it created in the heap to avoid memory leaks
 */
System::~System(){
    std::cout << "Delete System object" << std::endl;
}


/**
 * @brief Will allow the user to log into their account.
 * @return false if username does not exist
 * or password is incorect, true if both are correct.
 */
bool System::login(std::string username, std::string password) {
    bool success = false;

    if (usernameExist(username)) {
        qDebug() << "Valid username found";
        // If valid, check password
        Account *queryAcc = accounts[username]; //Is most likely causing a bad allocation
        std::cout << "Entered Value: " << password << std::endl;
        std::cout << "Expected Value: " << queryAcc->getPassword() << std::endl;

        if (password == queryAcc->getPassword()) {
            std::cout << std::endl << "Successful login!" << std::endl;
            // Proceed to the main menu of the program.
            currentUser = queryAcc;
            this->setLoggedIn(true);

            success = true;
        }
    }else{
        std::cout << std::endl << "Invalid credentials" << std::endl << "Please try again or create a new account." << std::endl;
    }

    return success;
}


/**
 * @brief If the user has not created an account they will be allowed to in this function.
 *
 * @return false if username is in use, true otherwise
 * This method is also used to create a randomly generated ID for each of the User's fields that requires an ID (such as the Blog, Tweet, etc)
 */
bool System::createAccount(std::string username, std::string password, std::string firstname, std::string lastname) {
    // check if username is in use
    bool success = false;
    std::cout << "Now entering create account method" << std::endl;
    if (usernameExist(username)) {
        std::cout << "Username already exists!" << std::endl;
    }
    else{
        // create new account
        Account* newAccount = new Account;
        newAccount->setUsername(username);
        newAccount->setPassword(password);
        newAccount->setFirstName(firstname);
        newAccount->setLastName(lastname);

        // add account to the system account map
        accounts[username] = newAccount;

        // add account to the database
        addAccount(newAccount);
        std::cout<< "New Account Created" << std::endl;
        success = true;
    }
    return success;
}


/**
 * @brief Adds a group to the System's list of groups.
 */
void System::addGroup(Group* newGroup) {
    this->getGroups().push_back(newGroup);
}


/**
 * @brief Removes a group from the System's list of groups.
 */
void System::removeGroup(Group* oldGroup) {
    for (int i = 0; i < this->getGroups().size(); i++) {
        if (&(*oldGroup) == &(*(this->getGroups()[i]))) {
            this->getGroups().erase(this->getGroups().begin() + i);
            break;
        }
    }
}


/**
 * @brief Adds an account to the Program's database.
 * @param Takes in a pointer to a new account object that we want to store
 */
void System::addAccount(Account* newAccount) {
//    std::cout << "Now entering add account method" << std::endl;
    const QString &x = QString::fromStdString(newAccount->getFirstName());
    const QString &y = QString::fromStdString(newAccount->getLastName());
    const QVariant accntD = newAccount->getAccountID();
    const QVariant frstName(x);
    const QVariant lstNme(y);
    const QString &a = QString::fromStdString(newAccount->getUsername() );
    const QString &b = QString::fromStdString(newAccount->getPassword() );
    const QVariant usrName(a);
    const QVariant passWord(b);

    const QVariant ScrpBkID = newAccount->getMyScrapbook()->getScrpbkID();
    const QVariant BlgID = newAccount->getMyBlog()->getBlogID();
    const QVariant TweetID = newAccount->getMyTweet()->getTweetID();

    dbm->addUser(accntD,frstName,lstNme,
                ScrpBkID,BlgID,TweetID,usrName,
                 passWord);
}


/**hSwizzle79
 * @brief Removes an account from the System's list of accounts.
 */
void System::removeAccount(Account* oldAccount) {
    accounts.erase(oldAccount->getUsername()); //Must also remove value from the database
}

void System::printAllUsernames(){
    dbm->printAllRows("UserName");
    std::cout << "Finished Printing All Usernames" << std::endl;
}

/**
 * @brief Getter for the current user.
 */
Account* System::getCurrentUser() {
    return this->currentUser;
}


/**
 * @brief Setter for the current user.
 */
void System::setCurrentUser(Account* cUser) {
    this->currentUser = cUser;
}


/**
 * @brief Getter for the account list.
 *
 * @return a copy of current account map (with pointers to actual accounts)
 */
std::map<std::string, Account*> System::getAllAccounts() {
    return this->accounts;
}

/**
 * @brief System::getDbm Method used to retrieve the databasemanager and all it's related info. Used in the Account class
 * @return Pointer to the dbm the system is currently using.
 */
DbManager* System::getDbm(){
    return dbm;
}

/**
 * @brief Setter for the account list.
 */
void System::setAccountMap(std::map<std::string, Account*> aMap) {
    this->accounts = aMap;
}


/**
 * @brief Getter for logged in boolean.
 */
bool System::getLoggedIn() {
    return this->loggedIn;
}


/**
 * @brief Setter for logged in boolean.
 */
void System::setLoggedIn(bool logged) {
    this->loggedIn = logged;
}

/**
 * @brief Getter than returns the list of groups the System contains.
 */
std::vector<Group*> System::getGroups() {
    return this->groups;
}

/**
 * @brief check if an account is exists in the system
 * @param the username of the account
 * @return true if the account exists
 */
bool System::usernameExist(std::string username){
    // for more on map::find, look at the link below
    // http://www.cplusplus.com/reference/map/map/find/
    if(accounts.find(username) == accounts.end()){
        return false;
    }else{
        return true;
    }
}

/**
 * @brief System::addChat
 * @param AccountID ID of the account to whome this chat is initiated by. Used for data retrieval purposes.
 * @param ChatID ID of this particular chat instance.
 * @param sender Name of the initator of this chat
 * Remove this method if it is not necessary
 * @return
 */
bool System::addChat(const int &AccountID,
                     const int &ChatID, const std::string &sender){
    const QVariant AcntID(AccountID);
    const QVariant ChtID(ChatID);
    QString convert = QString::fromStdString(sender);
    const QVariant sndr(convert);
    dbm->addChat(AcntID,ChtID,sndr);
    return true;
}

int System::numberOfAccount(){
    return accounts.size();
}

Account* System::getAccountByUsername(std::string usrname){
    return accounts[usrname];
}

/**
 * @brief System::loadAllAccounts
 */
void System::loadAllAccounts(){
    // call dbm to rebuild accounts and load to accounts map
    dbm->retrieveAllAccounts(accounts);
}


///**
// * @brief System::loadAccounts This method will be called in the constructor.
// * Will be used to load every account, and its associated IDs into the system.
// * @param one Map of usernames passed into the
// */
//void System::loadAccounts(std::map<int, std::string> *one){
//    std::cout<< "Now entering method to load values to usernameList map \n";
//    system("pwd");
//    dbm->retrieveAllAccounts(one); //Adds all usernames with their corresponding userIDs into the system
////    std::cout<<"All accounts are loaded from the database" << std::endl;
//}
///**
// * @brief System::fillAccountsMap Iterate through the map of usernames, storing an account pointer at each.
// * User after the system has been constructed, thereby filling the usernameList map.
// * Taken from http://www.cplusplus.com/reference/map/map/begin/
// * Right now, the program is generating pointers pointing to the same location in memory
// * */
//void System::fillAccountsMap(){
//    std::cout << "Now entering fill accounts map method" << std::endl;
//    for(std::map<int,std::string>::iterator it=usernameList->begin();it!=usernameList->end();++it ){
//        std::pair<std::string, Account*> insert;
//        Account *acntpntr = new Account();
//        QString one = "PassWord"; QString two = "accounts"; QString three = "UserName"; QString four = QString::fromStdString(it->second); //Use this method to attach a password to the given account object
//        acntpntr->setPassword(dbm->retrieveStringInfo(one,two,three,four));
//        insert.first = it->second;
//        insert.second = acntpntr;
//        accounts.insert(insert);
//        std::cout << insert.first << " " << insert.second << std::endl;
//    }
//    std::cout << "Accounts Size: " << accounts.size() << std::endl;
//}
