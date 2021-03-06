#include "account.h"

int Account::id_cnt = 0;

/**
 * @brief Account::Account basic constructor used to create a new account object.
 * @param newdbm Pointer to a databasemanager object that the accoutn will use for data storage and retrieval purposes
 */
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
    profileUsername = "";
    blogTweetUsername = "";

    monthDeparted = 0;
    dayDeparted = 0;
    yearDeparted = 0;

    myScrapbook = new Scrapbook(this);

    myBlog = new Blog(dbm); //Create new blog associated with user and retrieve all posts

    myTweet = new Tweet(dbm); //Create new Tweet associated with user and retrieve all posts

    // create a default profile for this account
    dbm->addProfile(accountID,"","","","",0);
}

/**
 * @brief Account::Account Constructor used to specify a username
 * @param usrName username for a new account object
 * @param newdbm Database manager object pointer used for data storage and retrieval purposes.
 */
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
    profileUsername = usrName.toStdString();
    blogTweetUsername = usrName.toStdString();

    monthDeparted = 0;
    dayDeparted = 0;
    yearDeparted = 0;

    myScrapbook = new Scrapbook(this);

    myBlog = new Blog(dbm); //Create new blog associated with user and retrieve all posts

    myTweet = new Tweet(dbm); //Create new Tweet associated with user and retrieve all posts

    // create a default profile for this account
    dbm->addProfile(accountID,"","","","",0);
}

/**
 * @brief Account constructor to rebuild an instance of existing account.
 * This contructor give all controls to the user
 * Thus, one possible risk is duplicate ID
 * Each of the parameters represents a field present in the accounts table of the program
 * @param accID the account ID
 * @param usrname the username
 * @param pwd the password
 * @param scrpBkID the ID of the scrapbook
 * @param tweetID
 * @param firstname
 * @param lastname
 * @param newdbm a pointer to the database manager object
 */
Account::Account(int accID,     QString usrname,    QString pw,
                int scrpBkID,   int blogID,         int tweetID,
                QString firstname,  QString lastname, DbManager *newdbm)
{
    dbm = newdbm;
    this->accountID = accID;
    // update id_cnt if needed
    if(accID >= id_cnt){
        id_cnt = accID + 1;
    }

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
    profileUsername = usrname.toStdString();
    blogTweetUsername = usrname.toStdString();

    //Retrieve all of the information associated with a user's profile
    dbm->retrieveAllProfileInfo(this);

    monthDeparted = 0;
    dayDeparted = 0;
    yearDeparted = 0;

    // create blog, tweet, scrapbook, instances using input IDs
    myScrapbook = new Scrapbook(scrpBkID, this);
    myBlog = new Blog(blogID, dbm);     // retrieve all blog posts inside the constructor
    myTweet = new Tweet(tweetID, dbm);   // retrieve all tweets inside the constructor

    // rebuild all chats
    retrieveAllChats();

    // rebuild all messages
    retrieveAllMessages();

}

/**
 * @brief Account::~Account Destructor for the Account object. Deletes all chats, the user's blog, and the user's scrapbook
 */
Account::~Account(){
    while(!myChats.empty()){
        delete myChats.back();
        myChats.pop_back();
    }
    delete myBlog;
    delete myTweet;
}

/**
 * @brief Getter for the current guest boolean.
 * @return isCurrentGuest
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
 * @return isSystemAdmin
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
 * @brief Account::retrieveAllBlogPosts Used to clear all blog posts within the user's blog and retrieves
 * all of the associated blog posts from the database
 */
void Account::retrieveAllBlogPosts(){
    // clear old posts
    myBlog->deleteAllPosts();
    // retrieve all posts
    dbm->retrieveAllBlogPosts(myBlog);
}

/**
 * @brief Account::retrieveAllTweets Retrieves all tweet posts from the database
 */
void Account::retrieveAllTweets(){
    // clear old posts
    myTweet->deleteAllPosts();
    // retrieve all posts
    dbm->retrieveAllTweets(myTweet);
}

/**
 * @brief Account::retrieveAllChats Retrieves all of the chats associated with the given user.
 */
void Account::retrieveAllChats(){
    dbm->retrieveAllChats(this);
}

/**
 * @brief Account::retrieveAllMessages For every chat contained in this user, retrieve all associated messages
 */
void Account::retrieveAllMessages(){
    for(unsigned i=0; i<myChats.size(); i++){
        dbm->retrieveAllMessages(myChats.at(i));
    }
}


/**
 * @brief Adds a new Chat to the user's list of chats.
 */
void Account::addChat(Chat* newChat) {
    myChats.push_back(newChat); //Add new chat to list of chats
    QVariant ID(accountID);
    dbm->addChat(ID,newChat->getChatID(),newChat->getTalkingToUser());
}

/**
 * @brief Account::insertChat Used to insert chats from the database
 * @param newChat Pointer to a chat obtained from the database
 */
void Account::insertChat(Chat *newChat){
    myChats.push_back(newChat);
}

/**
 * @brief Removes the specified chat from the list of the user's chats.
 *
 * No Database involved yet
 */
void Account::removeChat(Chat* badChat) {
    // does not remove from the database
    for (unsigned i = 0; i < myChats.size(); i++) {
        if (badChat->getChatID() == myChats[i]->getChatID()) {
            myChats.erase(myChats.begin() + i);
            break;
        }
    }
}


///**
// * @brief Adds a new friend to the user's friend list.
// */
//void Account::addFriend(Account* newFriend) {
//    this->getFriendList().push_back(newFriend);
//}


///**
// * @brief Removes a friend from the user's friend list.
// */
//void Account::removeFriend(Account* badFriend) {
//    for (unsigned i = 0; i < this->getFriendList().size(); i++) {
//        if (&(*badFriend) == &(*(this->getFriendList()[i]))) {
//            this->getFriendList().erase(this->getFriendList().begin() + i);
//            break;
//        }
//    }
//}


/**
 * @brief Adds a group to the user's list of joined groups.
 */
bool Account::joinGroup(Group* newGroup) {
    if(newGroup != nullptr){
        // check if group already in the list
        for(Group * g : groups){
            if(g != nullptr){
                if(g->getGroupName().compare(newGroup->getGroupName()) == 0){
                    std::cout<< "Already in group\n";
                    return false;
                }
            }else{
                std::cout<< "null pointer in Account::joinGroup\n";
            }
        }
        // if not, add to the list
        groups.push_back(newGroup);
        return true;
    }else{
        std::cout<< "null pointer in Account::joinGroup\n";
        return false;
    }
}


/**
 * @brief Removes a group from the user's list of joined groups.
 *
 * No database involved yet
 */
void Account::leaveGroup(Group* badGroup) {
    // does not remove from the database
    for (unsigned i = 0; i < groups.size(); i++) {
        if (badGroup->getID() == groups[i]->getID()) {
            groups.erase(groups.begin() + i);
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
    this->profileUsername = uName.toStdString();
    this->blogTweetUsername = uName.toStdString();
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
    this->password = pWord;//Iterate through all accounts in available map

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
 * @brief Getter for the user's list of chats. Update from the database
 */
std::vector<Chat*> Account::getMyChats() {
    // delete all chats and reload from databases
    while(!myChats.empty()){
        delete myChats.back();
        myChats.pop_back();
    }
    dbm->retrieveAllChats(this);
    return myChats;
}

/**
 * @brief Getter for the user's list of chats. No database involved
 */
std::vector<Chat*> Account::getChatVector() {
    return myChats;
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
 * @brief Getter for the user's fullname.
 */
QString Account::getFullName() {
    return (firstName +" "+ lastName);
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


/**
 * @brief Getter that returns the username of the profile to be displayed.
 */
std::string Account::getProfileUsername() {
    return this->profileUsername;
}


/**
 * @brief Setter for the profile username variable.
 */
void Account::setProfileUsername(std::string name) {
    this->profileUsername = name;
}

// CURRENT GUEST

///**
// * @brief Sets the depart boolen to true indicating that the user is leaving the ranch.
// */
//void Account::departRanch() {
//    if (this->getIsCurrentGuest() == true) {
//        this->promoteToPastGuest();

//        time_t currentTime;
//        struct tm *localTime;
//        time(&currentTime);
//        localTime = localtime(&currentTime);
//        this->setDayDeparted(localTime->tm_mday);
//        this->setMonthDeparted(localTime->tm_mon + 1);
//        this->setYearDeparted(localTime->tm_year + 1900);
//    }
//}


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


///**
// * @brief Setter for the current guest's month departed from the ranch.
// */
//void Account::setMonthDeparted(int month) {
//    if (this->getIsCurrentGuest() == true) {
//        this->monthDeparted = month;
//    }
//}


///**
// * @brief Setter for the current guest's day departed from the ranch.
// */
//void Account::setDayDeparted(int day) {
//    if (this->getIsCurrentGuest() == true) {
//        this->dayDeparted = day;
//    }
//}


///**
// * @brief Setter for the current guest's year departed from the ranch.
// */
//void Account::setYearDeparted(int year) {
//    if (this->getIsCurrentGuest() == true) {
//        this->yearDeparted = year;
//    }
//}

//// PAST GUEST

///**
// * @brief Getter for the past guest's list of projects worked on.
// */
//std::vector<QString> Account::getProjectsWorkedOn() {
//    if (this->getIsPastGuest() == true) {
//        return this->projectsWorkedOn;
//    }else{
//        std::vector<QString> empty_vector;
//        return empty_vector;
//    }
//}


///**
// * @brief Adds a project to the past guest's list of projects.
// */
//void Account::addProject(QString projectName) {
//    if (this->getIsPastGuest() == true) {
//        this->getProjectsWorkedOn().push_back(projectName);
//    }
//}


///**
// * @brief Adds a project to the past guest's list of projects.
// */
//void Account::removeProject(QString projectName) {
//    if (this->getIsPastGuest() == true) {
//        for (unsigned i = 0; i < this->getProjectsWorkedOn().size(); i++) {
//            if (projectName == this->getProjectsWorkedOn()[i]) {
//                this->getProjectsWorkedOn().erase(this->getProjectsWorkedOn().begin() + i);
//                break;
//            }
//        }
//    }
//}


///**
// * @brief Getter for the past guest's month departed from the ranch.
// */
//int Account::getMonthDeparted() {
//    if (this->getIsPastGuest() == true) {
//        return this->monthDeparted;
//    }
//    return 0;
//}


///**
// * @brief Getter for the past guest's day departed from the ranch.
// */
//int Account::getDayDeparted() {
//    if (this->getIsPastGuest() == true) {
//        return this->dayDeparted;
//    }
//    return 0;
//}


///**
// * @brief Getter for the past guest's year departed from the ranch.
// */
//int Account::getYearDeparted() {
//    if (this->getIsPastGuest() == true) {
//        return this->yearDeparted;
//    }
//    return 0;
//}

//// SYSTEM ADMIN

///**
// * @brief Adds a group to the System's list of groups.
// */
//void Account::addGroup(Group* newGroup) {
//    if (this->getIsSystemAdmin() == true) {
//        this->getSystem()->addGroup(newGroup);
//    }
//}


///**
// * @brief Removes a group from the System's list of groups.
// */
//void Account::deleteGroup(Group* oldGroup) {
//    if (this->getIsSystemAdmin() == true) {
//        this->getSystem()->removeGroup(oldGroup);
//    }
//}


///**
// * @brief Adds an account to the System's list of accounts.
// */
//void Account::addAccount(Account* newAccount, QString username, QString firstName, QString lastName) {
//    if (this->getIsSystemAdmin() == true) {
//        (*newAccount).setFirstName(firstName);
//        (*newAccount).setLastName(lastName);
//        (*newAccount).setUsername(username);

//        this->getSystem()->addAccount(newAccount);
//    }
//}


///**
// * @brief Removes an account from the System's list of accounts.
// */
//void Account::deleteAccount(Account* oldAccount) {
//    if (this->getIsSystemAdmin() == true) {
//        this->getSystem()->removeAccount(oldAccount);
//    }
//}


///**
// * @brief Removes a blog post from the Blog in question.
// */
//void Account::deleteBlogPost(Blog* targetBlog, BlogPost* badPost) {
//    if (this->getIsSystemAdmin() == true) {
//        (*targetBlog).deletePost(badPost);
//    }
//}


///**
// * @brief Removes a tweet post from the Tweet in question.
// */
//void Account::deleteTweetPost(Tweet* targetTweet, TweetPost* badPost) {
//    if (this->getIsSystemAdmin() == true) {
//        (*targetTweet).deletePost(badPost);
//    }
//}


///**
// * @brief Removes a scracpbook post from the Scrapbook in question.
// */
//void Account::deleteScrapbookPost(Scrapbook* targetScrapbook, ScrapbookPost* badPost) {
//    if (this->getIsSystemAdmin() == true) {
//        (*targetScrapbook).deletePost(badPost);
//    }
//}


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


/**
 * @brief Getter for the index in the account map of the profile to be displayed.
 */
int Account::getIndexOfProfile() {
    return this->indexOfProfile;
}


/**
 * @brief Setter for the index of profile.
 */
void Account::setIndexOfProfile(int index) {
    this->indexOfProfile = index;
}


/**
 * @brief Getter for the username of which blog/tweet we are displaying.
 */
std::string Account::getBlogTweetUsername() {
    return this->blogTweetUsername;
}


/**
 * @brief Setter for the blog tweet username.
 */
void Account::setBlogTweetUsername(std::string name) {
    this->blogTweetUsername = name;
}

/**
 * @brief get chat for specific talking-to user
 * @return a pointer to that chat or null pointer if there is no chat
 */
Chat * Account::getChatByPartnerName(QString talking_to_usr_name){
    for(Chat* chat: this->myChats){
        if(chat->getTalkingToUser().compare(talking_to_usr_name) == 0){
            return chat;
        }
    }
    return nullptr;
}
