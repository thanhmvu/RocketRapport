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
    retrieveAllAccounts();

    //Rebuild all groups
    retrieveAllGroups();

    //link groups to accounts
    linkGroupAccount();

    std::cout<< "New system created containing " << accounts.size() << " accounts and "
             << groups.size() << " groups." << std::endl;
    printAllIdCnt();

    html_path = "../index.html";
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
    while(!groups.empty()){
        delete groups.back();
        groups.pop_back();
    }
    deleteAllAccounts();
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
//        qDebug() << "Valid username found";
        // If valid, check password
        Account *queryAcc = accounts[username]; //Is most likely causing a bad allocation
        //std::cout << "Entered Value: " << password << std::endl;
        //std::cout << "Expected Value: " << queryAcc->getPassword() << std::endl;
//        qDebug() << "Entered Value: " << password;
//        qDebug() << "Expected Value: " << queryAcc->getPassword();

        if (password == queryAcc->getPassword()) {
            //std::cout << std::endl << "Successful login!" << std::endl;
//            qDebug()<< "Successful login!";
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
 * @brief create new group
 *
 * @return false if groupname is in use, true otherwise
 */
Group* System::createGroup(QString gName) {
    // check if group name is in use
    for(Group* g: groups){
        if(g->getGroupName().compare(gName) == 0){
            //std::cout << "Group name already exists!" << std::endl;
            return nullptr;
        }
    }

    // otherwise, create new group
    Group* newGroup = new Group(gName, dbm);

    // add account to group vector and the database
    addGroup(newGroup);

    return newGroup;
}

/**
 * @brief Adds a group to the System's list of groups. Add to the dbManager's table titled "groups"
 * @param newGroup Pointer to a new group object that we want to add to the system.
 * Is used to add a new Group to the database.
 */
void System::addGroup(Group* newGroup) {
    groups.push_back(newGroup);
    dbm->addGroup(newGroup->getID(),newGroup->getAdminID(),
                  newGroup->getIsActive(),newGroup->getGroupName(),newGroup->getBlog()->getBlogID() );
}

/**
 * @brief System::insertGroup Method used to add a group object whose information has been found in the database
 * @param newGroup Pointer to a group object the program wants to add to the local memory.
 */
void System::insertGroup(Group *newGroup){
    groups.push_back(newGroup);
}


/**
 * @brief Removes a group from the System's list of groups.
 * @param Pointer to the group we want to remove from the system.
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
 * @brief System::pairGroupWithUser Add a groupID, UserID pair to the groupUsers table in the database
 * @param group Group pointer we're passing in to obtain the group's ID
 * @param account Account pointer we're passing in to obtain the account's ID
 */
bool System::pairGroupWithUser(Group *group, Account *account){
    dbm->addGroupUserPair(group->getID(),account->getAccountID() );
    return true;
}


/**
 * @brief Adds an account to the Program's database.
 * @param Takes in a pointer to a new account object that we want to store
 */
void System::addAccount(Account* newAccount) {
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


/**
 * @brief System::removeAccount Method used to remove an account from the system.
 * @param oldAccount Pointer to account we want to remove
 */
void System::removeAccount(Account* oldAccount) {
    accounts.erase(oldAccount->getUsername()); //Must also remove value from the database
}

/**
 * @brief System::printAllUsernames Methos used for testing purposes.
 */
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
//bool System::addChat(const int &AccountID,
//                     const int &ChatID, const QString &Receiver){
//    const QVariant AcntID(AccountID);
//    const QVariant ChtID(ChatID);
//    dbm->addChat(AcntID,ChtID, Receiver);
//    return true;
//}

/**
 * @brief System::numberOfAccount
 * @return Returns the number of accounts being stored in the system.
 */
int System::numberOfAccount(){
    return accounts.size();
}

/**
 * @brief System::getAccountByUsername Method used to obtain account object using their username
 * @param usrname Name of the account we want to retrieve
 * @return Account object associated with the given username
 */
Account* System::getAccountByUsername(QString usrname){
    if(usernameExist(usrname)){
        return accounts[usrname];
    }else{
        std::cout << "System::getAccountByUsername fail. User does not exist.\n";
        return nullptr;
    }
}

/**
 * @brief System::getAccountByUsername Method used to obtain account object using their username
 * @param usrname Name of the account we want to retrieve
 * @return Account object associated with the given username
 */
Group* System::getGroupByName(QString name){
    for(Group * g: groups){
        if(g->getGroupName().compare(name) == 0){
            return g;
        }
    }
    std::cout << "System::getGroupByName fail. Group does not exist.\n";
    return nullptr;
}

/**
 * @brief System::getAccountByID Return a pointer to an account object given the account's ID
 * @param ID The identification number of the account we want to retrieve
 * @return Pointer to an account object with the given ID
 */
Account* System::getAccountByID(int ID){

}

/**
 * @brief System::loadAllAccounts Clears every account located in the vector (local memory) before reloading all accounts from the database
 */
void System::retrieveAllAccounts(){
    // clear old accounts
    deleteAllAccounts();
    // call dbm to rebuild all accounts and load to accounts map
    dbm->retrieveAllAccounts(accounts);
}

/**
 * @brief System::retrieveAllGroups Method used to obtain all group objects that have info stored in DB
 */
void System::retrieveAllGroups(){
    //clear old groups
    deleteAllGroups();
    // rebuild all groups
    dbm->retrieveAllGroups(this);
}

/**
 * @brief System::retrieveAllUsersInGroup Method used to "attach" the IDs of every account belonging to a group to their respective groups
 * @param groupToAdd Group which we want to attach all associated account IDs
 */
void System::retrieveAllUsersInGroup(Group* groupToAdd){
    dbm->retrieveAllUsersInGroup(groupToAdd);
}

/**
 * @brief System::printAllIdCnt method used for testing/verification purposes. Prints all information associated contained in this system.
 */
void System::printAllIdCnt(){
    std::cout<< "All id_cnt values is: " << std::endl;
    std::cout<< "Account    : " << Account::getIdCnt() << std::endl;
    std::cout<< "Blog       : " << Blog::getIdCnt() << std::endl;
    std::cout<< "BlogPost   : " << BlogPost::getIdCnt() << std::endl;
    std::cout<< "Tweet      : " << Tweet::getIdCnt() << std::endl;
    std::cout<< "TweetPost  : " << TweetPost::getIdCnt() << std::endl;
    std::cout<< "Chat       : " << Chat::getIdCnt() << std::endl;
    std::cout<< "Group      : " << Group::getIdCnt() << std::endl;
    std::cout<< "Message    : " << Message::getIdCnt() << std::endl;
    std::cout<< "Scrapbook  : " << Scrapbook::getIdCnt() << std::endl;
    std::cout<< "ScrpbkPost : " << ScrapbookPost::getIdCnt() << std::endl;

//    std::cout<< "Comment    : " << Comment::getIdCnt() << std::endl;
//    std::cout<< "Feed       : " << Feed::getIdCnt() << std::endl;
}

/**
 * @brief System::linkGroupAccount add accounts to groups and group to account
 */
void System::linkGroupAccount(){
    //Assign a list of integers showing which accounts are in each group for
    for(int i=0; i<groups.size(); i++){
        retrieveAllUsersInGroup( groups.at(i) );
    }

    //Assign a list of pointers showing which accounts are in each group for
    for(int i=0; i<groups.size(); i++){
        addAccountsToGroup(groups.at(i));
    }
}

/**
 * @brief System::addAccountsToGroup Add all account pointers that have
 * @param group pointer to the group object we want to add acocounts to
 */
void System::addAccountsToGroup(Group *group){
    std::vector<int> IDList = group->getGroupMemberIDs();

    for(int i=0; i < IDList.size(); i++){
        for(auto const &ent : accounts){

            if(IDList.at(i) == ent.second->getAccountID() ){
                Account* insertAc = ent.second;
                // add the account to the group
                group->addGroupMember(insertAc);
                // add the group to this user
                insertAc->joinGroup(group);
            }

        }
    }

}

/**
 * @brief System::deleteAllAccounts Delete every account located in the system memory
 */
void System::deleteAllAccounts(){
    for(auto pair: accounts){
        delete pair.second;
        accounts[pair.first] = nullptr;
    }
    accounts.clear();
    currentUser = nullptr;
}

/**
 * @brief System::deleteAllGroups Delete every group located in the system memory
 */
void System::deleteAllGroups(){
    while(!groups.empty()){
        delete groups.back();
        groups.pop_back();
    }
}

/**
 * @brief System::refreshSystem used to reload the system information. Resets current user
 * and obtains all account information from the database.
 */
void System::refreshSystem(){
    if(currentUser != nullptr){
        // temporarily store current user's username
        QString curr_username = currentUser->getUsername();

        // reload all accounts
        retrieveAllAccounts();

        // retrieve current user
        currentUser = getAccountByUsername(curr_username);
    }else{
        // reload all accounts
        retrieveAllAccounts();
    }

    //Rebuild all groups
    retrieveAllGroups();

    //link groups to accounts
    linkGroupAccount();
}

/**
 * @brief System::getHtmlPath return the path of the html file
 */
std::string System::getHtmlPath(){
    return html_path;
}
