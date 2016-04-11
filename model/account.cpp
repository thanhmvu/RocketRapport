#include "account.h"

int Account::id_cnt = 0;

Account::Account()
{
    this->accountID = id_cnt;
    id_cnt++;
}

Account::Account(std::string usrName){
    this->accountID = id_cnt;
    id_cnt++;

    username = usrName;
}


/**
 * @brief Adds a new Chat to the user's list of chats.
 */
void Account::addChat(Chat* newChat) {
    this->getMyChats().push_back(newChat);
}


/**
 * @brief Removes the specified chat from the list of the user's chats.
 */
void Account::removeChat(Chat* badChat) {
    for (int i = 0; i < this->getMyChats().size(); i++) {
        if (&(*badChat) == &(*(this->getMyChats()[i]))) {
            this->getMyChats().erase(this->getMyChats().begin() + i);
            break;
        }
    }
}


/**
 * @brief Adds a new friend to the user's friend list.
 */
void Account::addFriend(Account* newFriend) {
    this->getFriendList().push_back(newFriend);
}


/**
 * @brief Removes a friend from the user's friend list.
 */
void Account::removeFriend(Account* badFriend) {
    for (int i = 0; i < this->getFriendList().size(); i++) {
        if (&(*badFriend) == &(*(this->getFriendList()[i]))) {
            this->getFriendList().erase(this->getFriendList().begin() + i);
            break;
        }
    }
}


/**
 * @brief Adds a group to the user's list of joined groups.
 */
void Account::joinGroup(Group* newGroup) {
    this->getGroups().push_back(newGroup);
}


/**
 * @brief Removes a group from the user's list of joined groups.
 */
void Account::leaveGroup(Group* badGroup) {
    for (int i = 0; i < this->getGroups().size(); i++) {
        if (&(*badGroup) == &(*(this->getGroups()[i]))) {
            this->getGroups().erase(this->getGroups().begin() + i);
            break;
        }
    }
}


/**
 * @brief Getter for the user's username.
 */
std::string Account::getUsername() {
    return this->username;
}


/**
 * @brief Setter for the user's username.
 */
void Account::setUsername(std::string uName) {
    this->username = uName;
}


/**
 * @brief Getter for the user's password.
 */
std::string Account::getPassword() {
    return this->password;
}


/**
 * @brief Setter for the user's password.
 */
void Account::setPassword(std::string pWord) {
    this->password = pWord;
}


/**
 * @brief Getter for the user's scrapbook.
 */
Scrapbook* Account::getMyScrapbook() {
    return this->myScrapbook;
}


/**
 * @brief Setter for the user's scrapbook.
 */
void Account::setMyScrapbook(Scrapbook* sBook) {
    this->myScrapbook = sBook;
}


/**
 * @brief Getter for the user's list of chats.
 */
std::vector<Chat*> Account::getMyChats() {
    return this->myChats;
}


/**
 * @brief Getter for the user's friends list.
 */
std::vector<Account*> Account::getFriendList() {
    return this->friendList;
}


/**
 * @brief Getter for the list of groups the user is in.
 */
std::vector<Group*> Account::getGroups() {
    return this->groups;
}


/**
 * @brief Getter for the user's first name.
 */
std::string Account::getFirstName() {
    return this->firstName;
}


/**
 * @brief Setter for the user's first name.
 */
void Account::setFirstName(std::string fName) {
    this->firstName = fName;
}


/**
 * @brief Getter for the user's last name.
 */
std::string Account::getLastName() {
    return this->lastName;
}


/**
 * @brief Setter for the user's last name.
 */
void Account::setLastName(std::string lName) {
    this->lastName = lName;
}


/**
 * @brief Getter for the user's gender.
 */
std::string Account::getGender() {
    return this->gender;
}


/**
 * @brief Setter for the user's gender.
 */
void Account::setGender(std::string gend) {
    this->gender = gend;
}


/**
 * @brief Getter for the user's "about yourself" information.
 */
std::string Account::getAbout() {
    return this->aboutYourself;
}


/**
 * @brief Setter for the user's "about yourself" information.
 */
void Account::setAbout(std::string about) {
    this->aboutYourself = about;
}


/**
 * @brief Getter for the user's home address.
 */
std::string Account::getAddress() {
    return this->homeAddress;
}


/**
 * @brief Setter for the user's home address.
 */
void Account::setAddress(std::string address) {
    this->homeAddress = address;
}


/**
 * @brief Getter for the user's profile picture.
 */
std::string Account::getProfilePicture() {
    return this->profilePicture;
}


/**
 * @brief Setter for the user's profile picture.
 */
void Account::setProfilePicture(std::string picture) {
    this->profilePicture = picture;
}


/**
 * @brief Getter for the user's most recent employer.
 */
std::string Account::getMostRecentEmployer() {
    return this->mostRecentEmployer;
}


/**
 * @brief Setter for the user's most recent employer.
 */
void Account::setMostRecentEmployer(std::string employer) {
    this->mostRecentEmployer = employer;
}


/**
 * @brief Getter for the user's age.
 */
int Account::getAge() {
    return this->age;
}


/**
 * @brief Setter for the user's age.
 */
void Account::setAge(int age) {
    this->age = age;
}


/**
 * @brief Getter for the user's phone number.
 */
int Account::getPhoneNumber() {
    return this->phoneNumber;
}


/**
 * @brief Setter for the user's phone number.
 */
void Account::setPhoneNumber(int number) {
    this->phoneNumber = number;
}
