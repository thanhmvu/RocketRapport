#include "system.h"

/**
 * @brief System::System Constructing a new system should access the Database, creating a
 * new Account for each AccountID found in the database. This means we'll also have to store the
 * usernames in the DB as well.
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
    for(auto acc: accounts) {
//        dbm->addUser(a->getAccountID(),a->getFirstName(),a->getLastName(),a->getGroupID(),    //
//                    a->getMyScrapbook()->getScrpbkID(),a->getUserBlog()->getBlogID(),
//                    a->getUserTweet()->getTweetID());
    }
}


/**
 * @brief Will allow the user to log into their account.
 */
bool System::login(std::string username, std::string password) {
    if (usernameExist(username)) {
        // If valid, check password
        // FLAUT HERE !!! IF USER HAS NOT LOG IN< CURRENTUSER WILL BE NULL
        if (password == currentUser->getPassword()) {
            std::cout << std::endl << "Successful login!" << std::endl;
            // Proceed to the main menu of the program.
            this->setLoggedIn(true);
        }
    } else {
        // If invalid, prompt username again and ask if they want to create a new account
        std::cout << std::endl << "Invalid credentials" << std::endl << "Please try again or create a new account." << std::endl;
        // After a short delay,
        // clear the window, and
        // return to beginning.
    }
}


/**
 * @brief If the user has not created an account they will be allowed to in this function.
 *
 * @return false if username is in use, true otherwise
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

    // add account to the system
    accounts[username] = newAccount;

    // add account to the database
    // NEED TO BE IMPLEMENTED !!
    // ...
    // ...

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
 * @brief Adds an account to the System's map of accounts.
 */
void System::addAccount(Account* newAccount) {
    accounts[newAccount->getUsername()] = newAccount;
}


/**
 * @brief Removes an account from the System's list of accounts.
 */
void System::removeAccount(Account* oldAccount) {
    accounts.erase(oldAccount->getUsername());
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


