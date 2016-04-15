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
    for (int i = 0; i < this->getAccountList().size(); i++) {

    }
}

/**
 * @brief System::~System Destructor will store information currently in the system to the databse for the system
 * Remember that this methods parameters must match those in the DbManager class
 */
System::~System(){
    //For every Account in the System, store Account with associated values into the database
    for (int i = 0; i < this->getAccountList().size(); i++) {
        Account *a = accountList.at(i);
//        dbm->addUser(a->getAccountID(),a->getFirstName(),a->getLastName(),a->getGroupID(),    //
//                    a->getMyScrapbook()->getScrpbkID(),a->getUserBlog()->getBlogID(),
//                    a->getUserTweet()->getTweetID());
    }
}


/**
 * @brief Will allow the user to log into their account.
 */
void System::login() {
    std::string temp;
    bool validUsername = false;

    while (this->getLoggedIn() == false) {
        std::cout << "UserName: ";
        std::cin >> temp;

        for (int i = 0; i < this->getAccountList().size(); i++) {
            if (temp == (*((this->getAccountList())[i])).getUsername()) {
                validUsername = true;
                this->setCurrentUser((this->getAccountList())[i]);
            }
        }

        if (validUsername) {
            // If valid, prompt password
            std::cout << std::endl << "Password: ";
            std::cin >> temp;
            if (temp == (*(this->getCurrentUser())).getPassword()) {
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
}


/**
 * @brief If the user has not created an account they will be allowed to in this function.
 *
 * @return false if username is in use, true otherwise
 */
bool System::createAccount(std::string username, std::string password, std::string firstname, std::string lastname) {
    // check if username is in use
    for (int i = 0; i < accountList.size(); i++) {
        if (username == accountList[i]->getUsername()) {
            std::cout << "Username already exists!" << std::endl;
            return false;
        }
    }

    // create new account
    Account* newAccount = new Account;
    newAccount->setUsername(username);
    newAccount->setPassword(password);
    newAccount->setFirstName(firstname);
    newAccount->setLastName(lastname);

    // add account to the system
    accountList.push_back(newAccount);

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
 * @brief Adds an account to the System's list of accounts.
 */
void System::addAccount(Account* newAccount) {
    this->getAccountList().push_back(newAccount);
}


/**
 * @brief Removes an account from the System's list of accounts.
 */
void System::removeAccount(Account* oldAccount) {
    for (int i = 0; i < this->getAccountList().size(); i++) {
        if (&(*oldAccount) == &(*(this->getAccountList()[i]))) {
            this->getAccountList().erase(this->getAccountList().begin() + i);
            break;
        }
    }
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
 */
std::vector<Account*> System::getAccountList() {
    return this->accountList;
}

/**
 * @brief Setter for the account list.
 */
void System::setAccountList(std::vector<Account*> aList) {
    this->accountList = aList;
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

bool System::usernameExist(std::string username){
    for (int i = 0; i < accountList.size(); i++) {
        if (username == accountList[i]->getUsername()) {
            return true;
        }
    }
    return false;
}


