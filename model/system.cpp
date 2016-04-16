#include "system.h"

/**
 * @brief System::System Constructing a new system should access the Database, creating a
 * new Account for each AccountID found in the database. This means we'll also have to store the
 * usernames in the DB as well.
 * Constructing a system needs to load all accounts from the Database to the system
 * Need to create some kind of a method that retrieves each account from the database sequentially and adds their corresponding info IDs
 */
System::System()
{
    loggedIn = false;
    std::cout<< "New system created" << std::endl;

}

/**
 * @brief System::~System Destructor will store information currently in the system to the databse for the system
 * Remember that this methods parameters must match those in the DbManager class
 */
System::~System(){
    //For every Account in the System, store Account with associated values into the database

    // For more on looping through map, look at the link:
    // http://stackoverflow.com/questions/26281979/c-loop-through-map
    //Note that 'first' is used at the first value in the pair, and 'second' is the second value in the pair
    //In our case, the first value is a string, and the second is the actual account value (The map stores a pointer to the account object)
//    for(const auto &acc: accounts) {
//        Account* a = acc.second;
//        addAccount(a);     //Pass in a pointer to an account object stored in each pair of the map to the method that stores the accounts in the database
//    }
}


/**
 * @brief Will allow the user to log into their account.
 */
bool System::login(std::string username, std::string password) {
    if (usernameExist(username)) {
        // If valid, check password
        Account* queryAcc = accounts[username];
        if (password == queryAcc->getPassword()) {
            std::cout << std::endl << "Successful login!" << std::endl;
            // Proceed to the main menu of the program.
            currentUser = queryAcc;
            this->setLoggedIn(true);

            return true;
        }
    }

    // If invalid, prompt username again and ask if they want to create a new account
    /* @From Thanh:
     * Perhaps we have a "run" method
     * with the flow of the app,
     * including this kind of loop,
     * instead of having a loop explicitly in this method
     */
    std::cout << std::endl << "Invalid credentials" << std::endl << "Please try again or create a new account." << std::endl;
    // After a short delay,
    // clear the window, and
    // return to beginning.

    return false;
}


/**
 * @brief If the user has not created an account they will be allowed to in this function.
 *
 * @return false if username is in use, true otherwise
 * This method is also used to create a randomly generated ID for each of the User's fields that requires an ID (such as the Blog, Tweet, etc)
 */
bool System::createAccount(std::string username, std::string password, std::string firstname, std::string lastname) {
    // check if username is in use
    if (usernameExist(username)) {
        std::cout << "Username already exists!" << std::endl;
        return false;
    }

    // create new account
    Account* newAccount = new Account;
    newAccount->setUsername(username);
    newAccount->setPassword(password);
    newAccount->setFirstName(firstname);
    newAccount->setLastName(lastname);

    // add account to the system account map
    accounts[username] = newAccount;

    // add account to the database
    // NEED TO BE IMPLEMENTED !!
    // ...
    // ...

    addAccount(newAccount); //Add account to the database
    return true;
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
    const QString &x = QString::fromStdString(newAccount->getFirstName());
    const QString &y = QString::fromStdString(newAccount->getLastName());
    const QVariant accntD = newAccount->getAccountID();
    const QVariant frstName(x);
    const QVariant lstNme(y);
    const QVariant GrpID = newAccount->getGroupID();
    const QVariant ScrpBkID = newAccount->getMyScrapbook()->getScrpbkID();
    const QVariant BlgID = newAccount->getMyBlog()->getBlogID();
    const QVariant TweetID = newAccount->getMyTweet()->getTweetID();
    dbm->addUser(accntD,frstName,lstNme,GrpID,
                ScrpBkID,BlgID,TweetID);
}


/**
 * @brief Removes an account from the System's list of accounts.
 */
void System::removeAccount(Account* oldAccount) {
    accounts.erase(oldAccount->getUsername());
}

void System::printAllUsernames(){
    dbm->printAllRows("Usernames");
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


int System::numberOfAccount(){
    return accounts.size();
}

/**
 * @brief System::loadAccounts This method will be called in the constructor.
 * Will be used to load every account, and its associated IDs into the system.
 */
void System::loadAccounts(){

}

