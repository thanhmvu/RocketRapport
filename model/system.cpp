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

    dbm = new DbManager(path);

    // rebuild all accounts from the database
    loadAllAccounts();

    // rebuild all groups from the database
    // in turn, a group needs to rebuild the feed and links to accounts



    // print out info for debugging purpose
//    for(auto pair: accounts){
//        Account * acc = pair.second;
//        std::cout<< "First name std::cout: " << acc->getFirstName().toStdString() <<"\n";
//        qDebug()<< "First name qDebug: " << acc->getFirstName();
//    }
    std::cout<< "New system created containing " << accounts.size() << " accounts." << std::endl;
    std::cout<< "Account internal id_cnt value is: " << Account::getIdCnt() << std::endl;
    std::cout<< "Blog internal id_cnt value is: " << Blog::getIdCnt() << std::endl;    
    std::cout<< "BlogPost internal id_cnt value is: " << BlogPost::getIdCnt() << std::endl;
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
    delete dbm;
    ////////////////////////////////////////////////////////////////////
    /// delete accounts and groups
    //////////////////////////////////////////////////////////////////
    std::cout << "Delete System object" << std::endl;
}


/**
 * @brief Will allow the user to log into their account.
 * @return false if username does not exist
 * or password is incorect, true if both are correct.
 */
bool System::login(QString username, QString password) {
    bool success = false;

    if (usernameExist(username)) {
        qDebug() << "Valid username found";
        // If valid, check password
        Account *queryAcc = accounts[username]; //Is most likely causing a bad allocation
        //std::cout << "Entered Value: " << password << std::endl;
        //std::cout << "Expected Value: " << queryAcc->getPassword() << std::endl;
        qDebug() << "Entered Value: " << password;
        qDebug() << "Expected Value: " << queryAcc->getPassword();

        if (password == queryAcc->getPassword()) {
            //std::cout << std::endl << "Successful login!" << std::endl;
            qDebug()<< "Successful login!";
            // Proceed to the main menu of the program.
            currentUser = queryAcc;
            this->setLoggedIn(true);

            success = true;
        }
    }else{
//        std::cout << std::endl << "Invalid credentials" << std::endl << "Please try again or create a new account." << std::endl;
    }

    return success;
}


/**
 * @brief If the user has not created an account they will be allowed to in this function.
 *
 * @return false if username is in use, true otherwise
 * This method is also used to create a randomly generated ID for each of the User's fields that requires an ID (such as the Blog, Tweet, etc)
 */
bool System::createAccount(QString username, QString password, QString firstname, QString lastname) {
    // check if username is in use
    bool success = false;
//    std::cout << "Now entering create account method" << std::endl;
    if (usernameExist(username)) {
//        std::cout << "Username already exists!" << std::endl;
    }
    else{
        // create new account
        Account* newAccount = new Account(dbm);
        newAccount->setUsername(username);
        newAccount->setPassword(password);
        newAccount->setFirstName(firstname);
        newAccount->setLastName(lastname);

        // add account to the system account map
        accounts[username] = newAccount;

        // add account to the database
        addAccount(newAccount);
//        std::cout<< "New Account Created" << std::endl;
        currentUser = newAccount;
        this->setLoggedIn(true);
        success = true;
    }
    return success;
}


/**
 * @brief Adds a group to the System's list of groups.
 */
void System::addGroup(Group* newGroup) {
    this->getGroups().push_back(newGroup);
    dbm->addGroup(newGroup->getID(),newGroup->getAdmin()->getAccountID(),
                  newGroup->getIsActive(),newGroup->getGroupName(),newGroup->getFeed()->getFeedID() );
}


/**
 * @brief Removes a group from the System's list of groups.
 */
void System::removeGroup(Group* oldGroup) {
    for (unsigned i = 0; i < this->getGroups().size(); i++) {
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
    const QString &x = (newAccount->getFirstName());
    const QString &y = (newAccount->getLastName());
    const QVariant accntD = newAccount->getAccountID();
    const QVariant frstName(x);
    const QVariant lstNme(y);
    const QString &a = (newAccount->getUsername());
    const QString &b = (newAccount->getPassword());
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
std::map<QString, Account*> System::getAllAccounts() {
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
void System::setAccountMap(std::map<QString, Account*> aMap) {
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
bool System::usernameExist(QString username){
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
                     const int &ChatID, const QString &sender){
    const QVariant AcntID(AccountID);
    const QVariant ChtID(ChatID);
    const QVariant sndr(sender);
    dbm->addChat(AcntID,ChtID,sender);
    return true;
}

int System::numberOfAccount(){
    return accounts.size();
}

Account* System::getAccountByUsername(QString usrname){
    return accounts[usrname];
}

/**
 * @brief System::loadAllAccounts
 */
void System::loadAllAccounts(){
    // call dbm to rebuild accounts and load to accounts map
    dbm->retrieveAllAccounts(accounts);
}
