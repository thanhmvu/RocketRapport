#include "account.h"

int Account::id_cnt = 0;

Account::Account()
{
    this->accountID = id_cnt;
    id_cnt++;

    isCurrentGuest = true;
    isPastGuest = false;
    isSystemAdmin = false;
    isGroupAdmin = false;
}

Account::Account(std::string usrName){
    this->accountID = id_cnt;
    id_cnt++;

    isCurrentGuest = true;
    isPastGuest = false;
    isSystemAdmin = false;
    isGroupAdmin = false;

    username = usrName;
}


/**
 * @brief Getter for the current guest boolean.
 */
bool Account::getIsCurrentGuest() {
    return this->isCurrentGuest;
}


/**
 * @brief Getter for the past guest boolean.
 */
bool Account::getIsPastGuest() {
    return this->isPastGuest;
}


/**
 * @brief Getter for the system admin boolean.
 */
bool Account::getIsSystemAdmin() {
    return this->isSystemAdmin;
}


/**
 * @brief Getter for the group admin boolean.
 */
bool Account::getIsGroupAdmin() {
    return this->isGroupAdmin;
}


/**
 * @brief Setter for the current guest boolean.
 */
void Account::setIsCurrentGuest(bool cGuest) {
    this->isCurrentGuest = cGuest;
}


/**
 * @brief Setter for the past guest boolean.
 */
void Account::setIsPastGuest(bool pGuest) {
    this->isPastGuest = pGuest;
}


/**
 * @brief Setter for the system admin boolean.
 */
void Account::setIsSystemAdmin(bool sAdmin) {
    this->isSystemAdmin = sAdmin;
}


/**
 * @brief Setter for the group admin boolean.
 */
void Account::setIsGroupAdmin(bool gAdmin) {
    this->isGroupAdmin = gAdmin;
}


/**
 * @brief Changes the user to a current guest.
 */
void Account::promoteToCurrentGuest() {
    this->setIsCurrentGuest(true);
    this->setIsPastGuest(false);
    this->setIsGroupAdmin(false);
    this->setIsSystemAdmin(false);
}


/**
 * @brief Changes the user to a past guest.
 */
void Account::promoteToPastGuest() {
    this->setIsCurrentGuest(false);
    this->setIsPastGuest(true);
    this->setIsGroupAdmin(false);
    this->setIsSystemAdmin(false);
}


/**
 * @brief Changes the user to a system admin.
 */
void Account::promoteToSystemAdmin() {
    this->setIsCurrentGuest(true);
    this->setIsPastGuest(false);
    this->setIsSystemAdmin(true);
}


/**
 * @brief Changes the user to a group admin.
 */
void Account::promoteToGroupAdmin() {
    this->setIsCurrentGuest(true);
    this->setIsPastGuest(false);
    this->setIsGroupAdmin(true);
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
 * @brief Account::getAccountID Used to obtain accountID value.
 */
int Account::getAccountID(){
    return accountID;
}

/**
 * @brief Account::getGroupID Returns the ID number of the group this Account belongs to
 */
int Account::getGroupID(){
    return groupID;
}

/**
 * @brief Setter for the user's phone number.
 */
void Account::setPhoneNumber(int number) {
    this->phoneNumber = number;
}

// CURRENT GUEST

/**
 * @brief Sets the depart boolen to true indicating that the user is leaving the ranch.
 */
void Account::departRanch() {
    if (this->getIsCurrentGuest() == true) {
        this->promoteToPastGuest();

        time_t currentTime;
        struct tm *localTime;
        time(&currentTime);
        localTime = localtime(&currentTime);
        this->setDayDeparted(localTime->tm_mday);
        this->setMonthDeparted(localTime->tm_mon + 1);
        this->setYearDeparted(localTime->tm_year + 1900);
    }
}


/**
 * @brief Getter for the Blog pointer.
 */
Blog* Account::getMyBlog() {
    if (this->getIsCurrentGuest() == true) {
        return this->myBlog;
    }
}


/**
 * @brief Setter for the Blog pointer.
 */
void Account::setMyBlog(Blog* myBlog) {
    if (this->getIsCurrentGuest() == true) {
        this->myBlog = myBlog;
    }
}


/**
 * @brief Getter for the Tweet pointer.
 */
Tweet* Account::getMyTweet() {
    if (this->getIsCurrentGuest() == true) {
        return this->myTweet;
    }
}


/**
 * @brief Setter for the Tweet pointer.
 */
void Account::setMyTweet(Tweet* myTweet) {
    if (this->getIsCurrentGuest() == true) {
        this->myTweet = myTweet;
    }
}


/**
 * @brief Setter for the current guest's month departed from the ranch.
 */
void Account::setMonthDeparted(int month) {
    if (this->getIsCurrentGuest() == true) {
        this->monthDeparted = month;
    }
}


/**
 * @brief Setter for the current guest's day departed from the ranch.
 */
void Account::setDayDeparted(int day) {
    if (this->getIsCurrentGuest() == true) {
        this->dayDeparted = day;
    }
}


/**
 * @brief Setter for the current guest's year departed from the ranch.
 */
void Account::setYearDeparted(int year) {
    if (this->getIsCurrentGuest() == true) {
        this->yearDeparted = year;
    }
}

// PAST GUEST

/**
 * @brief Getter for the past guest's list of projects worked on.
 */
std::vector<std::string> Account::getProjectsWorkedOn() {
    if (this->getIsPastGuest() == true) {
        return this->projectsWorkedOn;
    }
}


/**
 * @brief Adds a project to the past guest's list of projects.
 */
void Account::addProject(std::string projectName) {
    if (this->getIsPastGuest() == true) {
        this->getProjectsWorkedOn().push_back(projectName);
    }
}


/**
 * @brief Adds a project to the past guest's list of projects.
 */
void Account::removeProject(std::string projectName) {
    if (this->getIsPastGuest() == true) {
        for (int i = 0; i < this->getProjectsWorkedOn().size(); i++) {
            if (projectName == this->getProjectsWorkedOn()[i]) {
                this->getProjectsWorkedOn().erase(this->getProjectsWorkedOn().begin() + i);
                break;
            }
        }
    }
}


/**
 * @brief Getter for the past guest's month departed from the ranch.
 */
int Account::getMonthDeparted() {
    if (this->getIsPastGuest() == true) {
        return this->monthDeparted;
    }
}


/**
 * @brief Getter for the past guest's day departed from the ranch.
 */
int Account::getDayDeparted() {
    if (this->getIsPastGuest() == true) {
        return this->dayDeparted;
    }
}


/**
 * @brief Getter for the past guest's year departed from the ranch.
 */
int Account::getYearDeparted() {
    if (this->getIsPastGuest() == true) {
        return this->yearDeparted;
    }
}

// SYSTEM ADMIN

/**
 * @brief Adds a group to the System's list of groups.
 */
void Account::addGroup(Group* newGroup) {
    if (this->getIsSystemAdmin() == true) {
        this->getSystem()->addGroup(newGroup);
    }
}


/**
 * @brief Removes a group from the System's list of groups.
 */
void Account::deleteGroup(Group* oldGroup) {
    if (this->getIsSystemAdmin() == true) {
        this->getSystem()->removeGroup(oldGroup);
    }
}


/**
 * @brief Adds an account to the System's list of accounts.
 */
void Account::addAccount(Account* newAccount, std::string username, std::string firstName, std::string lastName) {
    if (this->getIsSystemAdmin() == true) {
        (*newAccount).setFirstName(firstName);
        (*newAccount).setLastName(lastName);
        (*newAccount).setUsername(username);

        this->getSystem()->addAccount(newAccount);
    }
}


/**
 * @brief Removes an account from the System's list of accounts.
 */
void Account::deleteAccount(Account* oldAccount) {
    if (this->getIsSystemAdmin() == true) {
        this->getSystem()->removeAccount(oldAccount);
    }
}


/**
 * @brief Removes a blog post from the Blog in question.
 */
void Account::deleteBlogPost(Blog* targetBlog, BlogPost* badPost) {
    if (this->getIsSystemAdmin() == true) {
        (*targetBlog).deletePost(badPost);
    }
}


/**
 * @brief Removes a tweet post from the Tweet in question.
 */
void Account::deleteTweetPost(Tweet* targetTweet, TweetPost* badPost) {
    if (this->getIsSystemAdmin() == true) {
        (*targetTweet).deletePost(badPost);
    }
}


/**
 * @brief Removes a scracpbook post from the Scrapbook in question.
 */
void Account::deleteScrapbookPost(Scrapbook* targetScrapbook, ScrapbookPost* badPost) {
    if (this->getIsSystemAdmin() == true) {
        (*targetScrapbook).deletePost(badPost);
    }
}


/**
 * @brief Getter that returns the System object.
 */
System* Account::getSystem() {
    if (this->getIsSystemAdmin() == true) {
        return this->theSystem;
    }
}


/**
 * @brief Setter that sets the System object.
 */
void Account::setSystem(System* newSystem) {
    if (this->getIsSystemAdmin() == true) {
        this->theSystem = newSystem;
    }
}

// GROUP ADMIN

/**
 * @brief Getter that returns the group that this group admin is in charge of.
 */
Group* Account::getGroup() {
    if (this->getIsGroupAdmin() == true) {
        return this->myGroup;
    }
}


/**
 * @brief Adds a new account/user to the group that this admin is in charge of.
 */
void Account::addMember(Account* newMember) {
//    if (this->getIsGroupAdmin() == true) {
//        this->getGroup()->addGroupMember(newMember);
//    }
}


/**
 * @brief Removes an account/user from the group that this admin is in charge of.
 */
void Account::removeMember(Account* oldMember) {
//    if (this->getIsGroupAdmin() == true) {
//        this->getGroup()->removeGroupMember(oldMember);
//    }
}


/**
 * @brief Changes the name of the group that this admin is in charge of.
 */
void Account::editGroupName(std::string name) {
//    if (this->getIsGroupAdmin() == true) {
//        this->getGroup()->setGroupName(name);
//    }
}
