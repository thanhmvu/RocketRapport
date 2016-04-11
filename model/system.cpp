#include "system.h"


System::System()
{
    loggedIn = false;
    std::cout<< "New system created" << std::endl;
    for (int i = 0; i < this->getAccountList().size(); i++) {

    }
}

/**
 * @brief System::~System Destructor will store information currently in the system to the databse for the system
 */
System::~System(){

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
 */
void System::createAccount() {
    // NEED TO ADD TO DATABASE LOGIC ONCE THE METHODS ARE FINALIZED.
    Account* newAccount = new Account;
    accountList.push_back(newAccount);

    std::string tempString;
    int tempInt;

    std::cout << "Enter your new account information below." << std::endl;

    // User inputs username.
    bool uniqueUName = false;
    while (!uniqueUName) {
        bool inUse = false;
        std::cout << "Username: ";
        std::cin >> tempString;
        for (int i = 0; i < this->getUsernames().size(); i++) {
            if (tempString == this->getUsernames()[i]) {
                inUse = true;
            }
        }
        if (!inUse) {
            uniqueUName = true;
            (*newAccount).setUsername(tempString);
            this->addUsername(tempString);
        } else {
            std::cout << std::endl << "Username already in use. Enter a new one." << std::endl;
        }
    }

    // User inputs password.
    std::cout << std::endl << "Password: ";
    std::cin >> tempString;
    (*newAccount).setPassword(tempString);

    // User inputs first name.
    std::cout << std::endl << "First Name: ";
    std::cin >> tempString;
    (*newAccount).setFirstName(tempString);

    // User inputs last name.
    std::cout << std::endl << "Last Name: ";
    std::cin >> tempString;
    (*newAccount).setLastName(tempString);

    // User inputs gender.
    std::cout << std::endl << "Gender: ";
    std::cin >> tempString;
    (*newAccount).setGender(tempString);

    // User inputs about yourself information.
    std::cout << std::endl << "About Yourself: ";
    std::getline(std::cin, tempString);
    (*newAccount).setAbout(tempString);

    // User enters home address.
    std::cout << std::endl << "Home Address: ";
    std::getline(std::cin, tempString);
    (*newAccount).setAddress(tempString);

    // User enters profile picture.
    std::cout << std::endl << "Profile Picture: ";
    std::cin >> tempString;
    (*newAccount).setProfilePicture(tempString);

    // User enters most recent employer.
    std::cout << std::endl << "Most Recent Employer: ";
    std::getline(std::cin, tempString);
    (*newAccount).setMostRecentEmployer(tempString);

    // User enters age.
    std::cout << std::endl << "Age: ";
    std::cin >> tempInt;
    (*newAccount).setAge(tempInt);

    // User enters phone number.
    std::cout << std::endl << "Phone Number: ";
    std::cin >> tempInt;
    (*newAccount).setPhoneNumber(tempInt);
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
 * @brief Getter for the list of usernames.
 */
std::vector<std::string> System::getUsernames() {
    return this->getUsernames();
}


/**
 * @brief Adds a username to the list of usernames.
 */
void System::addUsername(std::string uName) {
    this->getUsernames().push_back(uName);
}


/**
 * @brief Removes a username from the list of usernames.
 */
void System::removeUsername(std::string uName) {
    for (int i = 0; i < this->getUsernames().size(); i++) {
        if (this->getUsernames()[i] == uName) {
            this->getUsernames().erase(this->getUsernames().begin() + i);
            break;
        }
    }
}

