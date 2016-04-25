#include "account.h"

int Account::id_cnt = 0;

Account::Account(DbManager *newdbm)
{
    dbm = newdbm;
    this->accountID = id_cnt;
    id_cnt++;

    isCurrentGuest = true;
    isPastGuest = false;
    isSystemAdmin = false;
    isGroupAdmin = false;

    username = "none";
    password = "none";
    firstName = "none";
    lastName = "none";
    gender = "none";
    aboutYourself = "none";
    homeAddress = "none";
    profilePicture = "none";
    mostRecentEmployer = "none";
    age = 0;
    phoneNumber = 0;

    monthDeparted = 0;
    dayDeparted = 0;
    yearDeparted = 0;

    myScrapbook = new Scrapbook();
    myScrapbook->setID(newdbm->retrieveIntInfo("ScrpBkID","accounts","AccountID",accountID));

    myBlog = new Blog(dbm); //Create new blog associated with user
    myBlog->setID( newdbm->retrieveIntInfo("BlogID","accounts","AccountID",accountID) ); //Method used to manually set the ID value of the new user Blog

    myTweet = new Tweet(dbm); //Create new Tweet associated with user
    myTweet->setID( newdbm->retrieveIntInfo("TweetID","accounts","AccountID",accountID) ); //Method used to manually set the ID value of the new user Tweet

    //Methods to access the database and retrieve all of the user's associated posts and information.
    newdbm->retrieveAllBlogPosts(myBlog);
    newdbm->retrieveAllTweets(myTweet);

    //Iterate through list of chats the user has and store each of the messages in the db to each chat
    for(unsigned i=0; i<myChats.size(); i++){
        newdbm->retrieveAllMessages(myChats.at(i));
    }
}

Account::Account(QString usrName, DbManager *newdbm){
    dbm = newdbm;
    this->accountID = id_cnt;
    id_cnt++;

    isCurrentGuest = true;
    isPastGuest = false;
    isSystemAdmin = false;
    isGroupAdmin = false;

    username = usrName;
    password = "none";
    firstName = "none";
    lastName = "none";
    gender = "none";
    aboutYourself = "none";
    homeAddress = "none";
    profilePicture = "none";
    mostRecentEmployer = "none";
    age = 0;
    phoneNumber = 0;

    monthDeparted = 0;
    dayDeparted = 0;
    yearDeparted = 0;

    myScrapbook = new Scrapbook();
    myBlog = new Blog(dbm);
    myTweet = new Tweet(dbm);
    for(unsigned i=0; i<myChats.size(); i++){
        newdbm->retrieveAllMessages(myChats.at(i));
    }
}

/**
 * @brief Account constructor to rebuild an instance of existing account.
 *
 * This contructor give all controls to the user
 * Thus, one possible risk is duplicate ID
 */
Account::Account(int accID,     QString usrname,    QString pw,
                int scrpBkID,   int blogID,         int tweetID,
                QString firstname,  QString lastname, DbManager *newdbm)
{
    dbm = newdbm;
    this->accountID = accID;
    id_cnt++;

    isCurrentGuest = true;
    isPastGuest = false;
    isSystemAdmin = false;
    isGroupAdmin = false;

    username = usrname;
    password = pw;
    firstName = firstname;
    lastName = lastname;
    gender = "none";
    aboutYourself = "none";
    homeAddress = "none";
    profilePicture = "none";
    mostRecentEmployer = "none";
    age = 0;
    phoneNumber = 0;

    monthDeparted = 0;
    dayDeparted = 0;
    yearDeparted = 0;

    // create blog, tweet, scrapbook, instances using input IDs
    myScrapbook = new Scrapbook();
    myBlog = new Blog(dbm);
    myTweet = new Tweet(dbm);

    // then call database methods to rebuild the posts of each instance


    // rebuild chats

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

void Account::retrieveAllBlogPosts(){
    dbm->retrieveAllBlogPosts(myBlog);
}

void Account::retrieveAllMessages(){

}

void Account::retrieveAllTweets(){
    dbm->retrieveAllTweets(myTweet);
}

/**
 * @brief Adds a new Chat to the user's list of chats.
 */
void Account::addChat(Chat* newChat) {
    myChats.push_back(newChat); //Add new chat to list of chats
    QVariant ID(accountID);
    int i = newChat->getChatID();
    QVariant chatID(i);
    dbm->addChat(ID,chatID,newChat->getTalkingToUser());
}


/**
 * @brief Removes the specified chat from the list of the user's chats.
 */
void Account::removeChat(Chat* badChat) {
    for (unsigned i = 0; i < this->getMyChats().size(); i++) {
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
    for (unsigned i = 0; i < this->getFriendList().size(); i++) {
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
    for (unsigned i = 0; i < this->getGroups().size(); i++) {
        if (&(*badGroup) == &(*(this->getGroups()[i]))) {
            this->getGroups().erase(this->getGroups().begin() + i);
            break;
        }
    }
}


/**
 * @brief Getter for the user's username.
 */
QString Account::getUsername() {
    return this->username;
}


/**
 * @brief Setter for the user's username.
 */
void Account::setUsername(QString uName) {
    this->username = uName;
}


/**
 * @brief Getter for the user's password.
 */
QString Account::getPassword() {
    return this->password;
}


/**
 * @brief Setter for the user's password.
 */
void Account::setPassword(QString pWord) {
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
    int x = myChats.size();
    myChats.clear();

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
QString Account::getFirstName() {
    return this->firstName;
}


/**
 * @brief Setter for the user's first name.
 */
void Account::setFirstName(QString fName) {
    this->firstName = fName;
}


/**
 * @brief Getter for the user's last name.
 */
QString Account::getLastName() {
    return this->lastName;
}


/**
 * @brief Setter for the user's last name.
 */
void Account::setLastName(QString lName) {
    this->lastName = lName;
}


/**
 * @brief Getter for the user's gender.
 */
QString Account::getGender() {
    return this->gender;
}


/**
 * @brief Setter for the user's gender.
 */
void Account::setGender(QString gend) {
    this->gender = gend;
}


/**
 * @brief Getter for the user's "about yourself" information.
 */
QString Account::getAbout() {
    return this->aboutYourself;
}


/**
 * @brief Setter for the user's "about yourself" information.
 */
void Account::setAbout(QString about) {
    this->aboutYourself = about;
}


/**
 * @brief Getter for the user's home address.
 */
QString Account::getAddress() {
    return this->homeAddress;
}


/**
 * @brief Setter for the user's home address.
 */
void Account::setAddress(QString address) {
    this->homeAddress = address;
}


/**
 * @brief Getter for the user's profile picture.
 */
QString Account::getProfilePicture() {
    return this->profilePicture;
}


/**
 * @brief Setter for the user's profile picture.
 */
void Account::setProfilePicture(QString picture) {
    this->profilePicture = picture;
}


/**
 * @brief Getter for the user's most recent employer.
 */
QString Account::getMostRecentEmployer() {
    return this->mostRecentEmployer;
}


/**
 * @brief Setter for the user's most recent employer.
 */
void Account::setMostRecentEmployer(QString employer) {
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

///**
// * @brief Account::getGroupID Returns the ID number of the group this Account belongs to
// */
//int Account::getGroupID(){
//    return myGroup->getID();
//}

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
    return nullptr;
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
    return nullptr;
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
std::vector<QString> Account::getProjectsWorkedOn() {
    if (this->getIsPastGuest() == true) {
        return this->projectsWorkedOn;
    }else{
        std::vector<QString> empty_vector;
        return empty_vector;
    }
}


/**
 * @brief Adds a project to the past guest's list of projects.
 */
void Account::addProject(QString projectName) {
    if (this->getIsPastGuest() == true) {
        this->getProjectsWorkedOn().push_back(projectName);
    }
}


/**
 * @brief Adds a project to the past guest's list of projects.
 */
void Account::removeProject(QString projectName) {
    if (this->getIsPastGuest() == true) {
        for (unsigned i = 0; i < this->getProjectsWorkedOn().size(); i++) {
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
    return 0;
}


/**
 * @brief Getter for the past guest's day departed from the ranch.
 */
int Account::getDayDeparted() {
    if (this->getIsPastGuest() == true) {
        return this->dayDeparted;
    }
    return 0;
}


/**
 * @brief Getter for the past guest's year departed from the ranch.
 */
int Account::getYearDeparted() {
    if (this->getIsPastGuest() == true) {
        return this->yearDeparted;
    }
    return 0;
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
void Account::addAccount(Account* newAccount, QString username, QString firstName, QString lastName) {
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
    return nullptr;
}


/**
 * @brief Setter that sets the System object.
 */
void Account::setSystem(System* newSystem) {
    if (this->getIsSystemAdmin() == true) {
        this->theSystem = newSystem;
    }
}

int Account::getIdCnt(){
    return id_cnt;
}

// GROUP ADMIN

///**
// * @brief Getter that returns the group that this group admin is in charge of.
// */
//Group* Account::getGroup() {
//    if (this->getIsGroupAdmin() == true) {
//        return this->myGroup;
//    }
//}


///**
// * @brief Adds a new account/user to the group that this admin is in charge of.
// */
//void Account::addMember(Account* newMember) {
////    if (this->getIsGroupAdmin() == true) {
////        this->getGroup()->addGroupMember(newMember);
////    }
//}


///**
// * @brief Removes an account/user from the group that this admin is in charge of.
// */
//void Account::removeMember(Account* oldMember) {
////    if (this->getIsGroupAdmin() == true) {
////        this->getGroup()->removeGroupMember(oldMember);
////    }
//}


///**
// * @brief Changes the name of the group that this admin is in charge of.
// */
//void Account::editGroupName(QString name) {
////    if (this->getIsGroupAdmin() == true) {
////        this->getGroup()->setGroupName(name);
////    }
//}
