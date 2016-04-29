#include "dbmanager.h"

int DbManager::id_cnt =0;

/**
 * @brief DbManager::DbManager Class used to "communicate" between the program and the database.
 * @param path String used to specify where the program will be accessing a database file.
 */
DbManager::DbManager(const QString &path)
{
    id = id_cnt;
    id_cnt++;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    qDebug()<< m_db.connectionName() << "\n";
    if (!m_db.open()){
        std::cout << "Error: Connection with database failure" << std::endl;
    }
    else{
        std::cout << "Database: Connection is A-Ok" << std::endl;
    }
}

/**
 * @brief DbManager::~DbManager Desuctor that will close the database connection
 */
DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
    //qDebug() << "Delete DbManager object";
}


//////////////////////////////////////////////////////////////////////////
/// Add methods
//////////////////////////////////////////////////////////////////////////

/**
 * @brief DbManager::addUser Method used to add user objects with associated object IDs to the database
 * @param AcntID   ID number used to associate a User object with a name and a series of other ID's
 * @param FrstName First name of the new user
 * @param LstName Last name of the new user
 * @param GrpID Id of the group the user belongs to. Will be set to an arbitrary default value
 * @param ScrpBkID ID of the scrapbook belonging to the user
 * @param BlogID ID of the blog belonging to the user
 * @param TweetID ID of the tweet system that belongs to the user
 * @return Returns true if the add method works successfully
 */
bool DbManager::addUser(const QVariant &AcntID  , const QVariant &FrstName,
                        const QVariant &LstName , const QVariant &ScrpBkID,
                        const QVariant &BlogID  , const QVariant &TweetID,
                        const QVariant &UserName, const QVariant &passWord){
    bool success = false;
    QSqlQuery query; //Prepares a new QSqlQuery

    if(!find(AcntID, "accounts") ){
        std::cout << "Value not found" << std::endl;
        query.prepare("INSERT INTO accounts VALUES ( (:AcntID),(:UserName),(:PassWord),(:ScrpBkID),(:BlogID),(:TweetID),(:FrstName),(:LstName) )");
        query.bindValue(":AcntID", AcntID);
        query.bindValue(":UserName",UserName);
        query.bindValue(":PassWord",passWord);
        query.bindValue(":ScrpBkID", ScrpBkID);
        query.bindValue(":BlogID", BlogID);
        query.bindValue(":TweetID", TweetID);
        query.bindValue(":FrstName", FrstName);
        query.bindValue(":LstName", LstName);

        if(query.exec()){
            success = true;
        }else{
            qDebug() << "removePerson error: "
                     << query.lastError();
        }
    }
    else{
        std::cout << "Element already contained in database" << std::endl;
        success = false;
    }

    return success;
}

/**
 * @brief DbManager::addGroup Method used to add a Group and its asociated information into a table
 * @param GrpID ID of the newly created group
 * @param GrpAdmnId Account ID of the account that is  the admin of this particular group
 * @param actStatus Boolean signifying if a group is active or not.
 * @param GrpName Name of the newly created group
 * @param BlogID ID of the Blog belonging to this particular group
 * @return Returns true if the add method works successfully
 */
bool DbManager::addGroup(const QVariant &GrpID  , const QVariant &GrpAdmnId,
                         bool actStatus         , const QVariant &GrpName,
                         const QVariant &BlogID , const QVariant &GrpInfo)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO groups VALUES ( (:GrpID) , (:GrpAdmnId) , (:actStatus) , (:GrpName) , (:BlogID) )");
    query.bindValue(":GrpID",GrpID);
    query.bindValue(":GrpAdmnId",GrpAdmnId);
    query.bindValue(":actStatus",actStatus);
    query.bindValue(":GrpName",GrpName);
    query.bindValue(":BlogID",BlogID);
//    qDebug() << query.boundValue(0) << " " << query.boundValue(1) << " " << query.boundValue(2) <<
//                " " << query.boundValue(3) << " " << query.boundValue(4);
    if(query.exec()){
        success = true;
    }else{
        qDebug() << "Issue adding new Group"
                 << query.lastError();
    }
    return success;
}

/**
 * @brief DbManager::addChat Add a new chat object associated with a patrticular user
 * @param AccountID ID of the account that starting a new chat
 * @param ChatID ID of the newly created chat
 * @param sender Username of the user that the sender is starting a chat with.
 * @return Returns true if the add method works successfully
 */
bool DbManager::addChat(const QVariant &AccountID, const QVariant &ChatID, const QString &receiver){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO chats VALUES ((:ChatID), (:AccountID),  (:Reciever) )");
    query.bindValue(":AccountID", AccountID);
    query.bindValue(":ChatID", ChatID);
    query.bindValue(":Reciever", receiver);
    if(query.exec()){
        success = true;
    }
    else{
        qDebug() << "Error adding Chat: "<< query.lastError().text();
    }
    return success;
}


/**
 * @brief DbManager::addMessage Add message information to the database
 * @param ChatID ID of the chat that the newly created message belongs to.
 * @param MessageID ID of the newly created message.
 * @param DateTime Date that the newly  created message was sent at.
 * @param text  Text that is being sent as a message.
 * @param imageURL  URL directing the program to a directory containing the image it wants to load
 * @param receiver  Name of the user being sent the message
 * @return Returns true if the add method works successfully
 */
bool DbManager::addMessage(const QVariant &ChatID   , const QVariant &MessageID,
                           const QVariant &DateTime , const QVariant &text){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO chatMessages VALUES( (:MessageID), (:ChatID), (:dateTime), (:Text) )");
    query.bindValue(":MessageID",MessageID);
    query.bindValue(":ChatID", ChatID);
    query.bindValue(":dateTime",DateTime);
    query.bindValue(":Text",text);
    if(query.exec()){
        success = true;
    }
    else{
        qDebug() << "Issue adding new Message"
                 << query.lastError();
    }

    return success;
}

/**
 * @brief DbManager::addTweetPost Method used to add a new tweet post to the database.
 * @param TweetPostID ID of the newly created tweet post
 * @param TweetID ID of the tweet object this tweet belongs to
 * @param TimeDate Date that the tweet was posted on
 * @param Text Text being posted in the new tweet post
 * @return Returns true if the add method works successfully
 */
bool DbManager::addTweetPost(const QVariant &TweetPostID, const QVariant &TweetID,
                             const QVariant &TimeDate   , const QVariant &Text){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO tweetPosts VALUES( (:TweetPostID), (:TweetID), (:TimeDate), (:Text) ) ");
    query.bindValue(":TweetPostID",TweetPostID);
    query.bindValue(":TweetID",TweetID);
    query.bindValue(":TimeDate",TimeDate);
    query.bindValue(":Text",Text);
    if(query.exec()){
        success = true;
    }
    else{
        qDebug() << "Issue adding tweetPost: "
                 << query.lastError();
    }

    return success;
}

/**
 * @brief DbManager::addGroupUserPair Used to add a pair associating a user with a particular group.
 * @param GroupID ID of the group a particular user is associated with
 * @param UserID ID of the user that is assigned to a given group
 * @return Returns true if the add method works successfully
 */
bool DbManager::addGroupUserPair(const QVariant GroupID, const QVariant UserID){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO groupUsers VALUES( (:GrpID),(:AccountID) )");
    query.bindValue(":GrpID",GroupID);
    query.bindValue(":AccountID",UserID);
    if(query.exec() ){
        success = true;
    }
    else{
        qDebug() << "Issue adding Group-User pair "
                 << query.lastError();
    }
    return success;
}

///**
// * @brief DbManager::addFeedPost Method used to add new Feed posts to the database
// * @param FeedPostID ID of the newly created Feed post
// * @param FeedID ID of the Feed that the newly created Feed post belongs to
// * @param timeDate Date that the new Feed post was posted on
// * @param text Text being stored and displayed on the new Feed post
// * @return Returns true if the add method works successfully
// */
//bool DbManager::addFeedPost(const QVariant &FeedPostID, const QVariant &FeedID,
//                            const QVariant &timeDate, const QVariant &text){
//     QSqlQuery query;
//     query.prepare("INSERT INTO FeedPosts VALUES( (:FeedPostID), (:FeedID), (:timeDate), (:text) )" );
//     query.bindValue(":FeedPostID",FeedPostID);
//     query.bindValue(":FeedID", FeedID);
//     query.bindValue(":timeDate",timeDate);
//     query.bindValue(":text",text);
//     if(query.exec()){
//         std::cout << "DbManager::addFeedPost exec(): true\n";
//         return true;
//     }else{
//         qDebug() << query.lastError();
//         return false;
//     }
// }

/**
 * @brief DbManager::addBlogPost Method used to add new blog posts to the database
 * @param blogPostID ID of the newly created blog post
 * @param blogID ID of the blog that the newly created blog post belongs to
 * @param timeDate Date that the new blog post was posted on
 * @param text Text being stored and displayed on the new blog post
 * @return Returns true if the add method works successfully
 */
bool DbManager::addBlogPost(const QVariant &blogPostID, const QVariant &blogID,
                            const QVariant &timeDate, const QVariant &text){
     QSqlQuery query;
     query.prepare("INSERT INTO blogPosts VALUES( (:BlogPostID), (:blogID), (:timeDate), (:text) )" );
     query.bindValue(":BlogPostID",blogPostID);
     query.bindValue(":blogID", blogID);
     query.bindValue(":timeDate",timeDate);
     query.bindValue(":text",text);
     if(query.exec()){
//         std::cout << "DbManager::addBlogPost exec(): true\n";
         return true;
     }else{
         qDebug() << query.lastError();
         return false;
     }
 }



//////////////////////////////////////////////////////////////////////////
/// Methods used to modify the existing contents of the table
//////////////////////////////////////////////////////////////////////////

/**
 * @brief AccountDatabaseManager::addColumn Used to add a new column to the associated database file
 * @param name  Name of the new created column
 * @param type  Type of data stored in the new column
 * @return  Returns true if we're able to add a new column
 * THIS METHOD SHOULD NOT BE USED
 */
bool DbManager::addColumn(const QString name, const QString type){
    QSqlQuery query;
    const QString command = "ALTER TABLE accounts ADD COLUMN " + name + " " + type;
    query.prepare(command);
    return query.exec();
}

/**
 * @brief DbManager::find Method used to return a FirstName and LastName given their associated UserID
 * @param UsrID User ID of the account we are searching for.
 * @return  Returns true if the program is able to find the given information
 */
bool DbManager::find(const QVariant &UsrID, const QVariant &table){

    bool found = false;

    QSqlQuery query;
    const QString command = "SELECT firstName,lastName FROM " + table.toString() + " WHERE AccountId = (:UsrID)";
    query.prepare(command);
    query.bindValue(":UsrID",UsrID);

    if (query.exec()){
        if(query.next()){
            found = true;
            std::cout<< "Account has been found" << std::endl;
        }
        else{
            std::cout << "Account not found" << std::endl;
        }
    }
    return found;
}

/**
 * @brief DbManager::printAllRows Print all stored rows for a given column.
 * @param column Name of the chosen column for which the user wants to print all information
 * @return Returns true if the method is able to execute the given query
 */
bool DbManager::printAllRows(const QString &column){
    std::cout<< "Printing all elements" << std::endl;
    QSqlQuery query("SELECT * FROM accounts");
    QSqlRecord rec = query.record();
    qDebug() << "Number of columns: " << rec.count();
    int nameCol = rec.indexOf(column);
    while(query.next()){
        qDebug() << query.value(nameCol).toString();
    }
    return true;
}

/**
 * @brief DbManager::deleteName Remove a user and their associated information from the database
 * @param UsrID ID number used to designate user we want to remove from the system
 * @return Returns true if the query is able to execute
 */
bool DbManager::deleteName(const QVariant &UsrID){
    bool deleted = false;
    if(find(UsrID, "accounts") ){
        //Carry on with deleton process
        QSqlQuery query;
        query.prepare("DELETE FROM accounts WHERE name = (:UsrID)"); //Deletes every instance of the name
        query.bindValue(":UsrID",UsrID);
        bool success = query.exec();

        if(!success){
            qDebug() << "RemovePerson error: "
                     << query.lastError();
        }

        deleted = true;
    }
    else{
        std::cout << "Element to be deleted was not found" << std::endl; //Print message and do nothing
    }
    return deleted;
}


/**
 * @brief DbManager::rmAll Remove all information from the database.
 * @return Boolean signaling that the database has been deleted.
 */
bool DbManager::rmAllAccounts(){
    QSqlQuery query;
    query.prepare("DELETE FROM accounts");
    return query.exec();
}

/**
 * @brief DbManager::deleteTable Method used to clear all of the values in a particular table
 * @param tableName Name of the table the user wants to clear of values
 */
void DbManager::deleteTable(const QVariant tableName){
    QSqlQuery query;
    QString command = "delete from ";
    command += tableName.toString();
    query.prepare(command);
    query.exec();
}


//////////////////////////////////////////////////////////////////////////
/// Retrieve methods
//////////////////////////////////////////////////////////////////////////

/**
 * @brief DbManager::retrieveIntInfo
 * @param fieldName Name of the column we want the program to return
 * @param tableName Name of the table we want to access from the database
 * @param checkName Name of the field we want to use as a query
 * @param ID Value we want to use to return another field of information
 * @return Return one value from any of the 5 available integer fields
 */
int DbManager::retrieveIntInfo(const QString &fieldName, const QString &tableName, const QString &checkName, const QVariant &ID){
    QSqlQuery query;
    QString command = "SELECT " + fieldName + " FROM " + tableName + " WHERE " + checkName + "= :ID";
    query.prepare(command);
    query.bindValue(":ID", ID);

    if(query.exec() ){
        std::cout << "Query Executed Successfully" << std::endl;
        query.first();
    }
    else{
        qDebug() << "removePerson error: "
                 << query.lastError();
    }
    int i = query.value(0).toInt();
    return i;
}

/**
 * @brief DbManager::retrieveStringInfo Retrieve a particular string from the database
 * @param fieldName Name of the field we want to retrieve a value from
 * @param tableName Name of the table we want to access
 * @param checkname Name of the field used to specify which tuple we'll access
 * @param ID Value we're using to match with the checkName
 * @return Return the value of the field the user wants to retrieve
 */
QString DbManager::retrieveStringInfo(const QString &fieldName, const QString &tableName, const QString &checkName, const QVariant &ID){
    QSqlQuery query;
    QString command = "SELECT " + fieldName + " FROM " + tableName + " WHERE " + checkName + "= :ID";
    query.prepare(command);
    query.bindValue(":ID", ID);

    if(query.exec() ){
        std::cout << "Query Executed Successfully" << std::endl;
        query.first();
    }
    else{
        qDebug() << "removePerson error: "
                 << query.lastError();
    }
    QString rString = query.value(0).toString();
    return rString;
}

/**
 * @brief DbManager::retrieveAllBlogPosts Method used to attach each blog post in  the database to its associated blog
 * @param userBlog Blog pointer passed in to attach all blog posts matching the given blog pointer's blog ID
 */
void DbManager::retrieveAllBlogPosts(Blog *userBlog){
    QSqlQuery query;
    QString command = "SELECT * FROM blogPosts WHERE BlogID = ";
    QString valStr = QString::number(userBlog->getBlogID());
    command += valStr;
    query.prepare(command);
    query.exec();
    while(query.next()){
        // extract the info
        int postID = query.value(0).toInt();
        int blogID = query.value(1).toInt();
        QDateTime time = query.value(2).toDateTime();
        QString text = query.value(3).toString();

        // re-create post using special constructor use to reload blogPost with givin postID
        BlogPost *newBP = new BlogPost(postID, blogID, time, text);
        userBlog->addPost(newBP);
    }
}

/**
 * @brief DbManager::retrieveAllMessages Method used to attach every message associated with a user's chat to the chat.
 * @param userChat Pointer to a user's chat that we want to "fill" with associated messages.
 */
void DbManager::retrieveAllMessages(Chat *userChat){
    QSqlQuery query;
    QString command = "SELECT * FROM chatMessages WHERE ChatID= ";
    QString valStr = QString::number(userChat->getChatID());
    command += valStr;
    query.prepare(command);
    query.exec();
    while(query.next()){
        int messID = query.value(0).toInt();
        QDateTime time = query.value(2).toDateTime();
        QString text = query.value(3).toString();

        // re-create messages using special constructor
        Message *newMessage = new Message(messID, time, text);
        userChat->addMessage(newMessage);
    }

}

/**
 * @brief DbManager::retrieveAllTweets Method used to attach every tweet post associated with a user's Tweet to the Tweet.
 * @param userTweet Pointer to the user's tweet object
 */
void DbManager::retrieveAllTweets(Tweet *userTweet){
    QSqlQuery query;
    QString command = "SELECT * FROM tweetPosts WHERE TweetID = ";
    QString idValue = QString::number(userTweet->getTweetID() );
    command += idValue;
    query.prepare(command);
    query.exec();
    while(query.next()){
        TweetPost *newTP = new TweetPost;
        newTP->setText(query.value(3).toString());
        newTP->setTime(query.value(2).toDateTime());
        userTweet->addPost(newTP);
    }
}

///**
// * @brief DbManager::retrieveAllFeedPosts Method used to attach every feed post associated with a group's Feed.
// * @param groupTweet Pointer to the group's feed object
// */
//void DbManager::retrieveAllFeedPosts(Feed *groupFeed){
//    QSqlQuery query;
//    QString command = "SELECT * FROM feedPosts WHERE FeedID = ";
//    QString valStr = QString::number(groupFeed->getFeedID());
//    command += valStr;
//    query.prepare(command);
//    query.exec();
//    while(query.next()){
//        // extract the info
//        int postID = query.value(0).toInt();
//        int feedID = query.value(1).toInt();
//        QDateTime time = query.value(2).toDateTime();
//        QString text = query.value(3).toString();

//        // using blogPost object for feed
//        // re-create post using special constructor use to reload feedPost with givin postID
//        FeedPost *newBP = new FeedPost(postID, feedID, time, text);
//        groupFeed->addPost(newBP);
//    }
//}

/**
  * @brief DbManager::retrieveAllScbkPosts Method used to attach every scrapbook post associated with a user's scrapbook to the scrapbook.
  * @param userScBook Pointer to the user's scrapbook used to retrieve associated information
  */
 void DbManager::retrieveAllScbkPosts(Scrapbook *userScBook){
     QSqlQuery query;
     QString command = "SELECT * FROM tweetPosts WHERE TweetID = ";
     QString idValue = QString::number(userScBook->getScrpbkID() );
     command += idValue;
     query.prepare(command);
     query.exec();
 }

 /**
  * @brief DbManager::retrieveAllChats Method used to attach every chat associated with a user.
  * @param user Pointer to the account we want to add a list of chats to from the database
  */
 void DbManager::retrieveAllChats(Account *user){
    QSqlQuery query;
    QString command = "SELECT * FROM chats WHERE AccountID = ";
    QString idValue = QString::number(user->getAccountID() );
    command += idValue;
    query.prepare(command);
    bool check = query.exec();
    while(query.next() ){
        int chatID = query.value(0).toInt();
        QString partner = query.value(2).toString();
        Chat *newChat = new Chat(chatID, partner, this);

        user->insertChat(newChat); // special method for loading existing chat from the database
    }
 }

/**
 * @brief DbManager::retrieveAllAccounts This method will
 * be used to add every available Account to the given map
 * @param map
 */
void DbManager::retrieveAllAccounts(std::map<QString, Account*> &accounts){
    QSqlQuery query;
    if(query.prepare("SELECT * FROM accounts")){ //Choose all elements from the table
        if(query.exec()){
            while(query.next() ){
                // get the neccessary info
                int accountID = query.value(0).toInt();
                QString username = query.value(1).toString();
                QString password = query.value(2).toString();
                int scrpBkID = query.value(3).toInt();
                int blogID = query.value(4).toInt();
                int tweetID = query.value(5).toInt();
                QString firstname = query.value(6).toString();
                QString lastname = query.value(7).toString();

                // rebuild an account based on the info
                Account * rebuilt_account = new Account(accountID, username, password,
                                                        scrpBkID, blogID, tweetID,
                                                        firstname, lastname, this);

                // add accoun to the accounts map
                accounts[username] = rebuilt_account;
            }
        }else{ qDebug() << query.lastError(); }
    }else{ qDebug() << query.lastError(); }
}

/**
 * @brief DbManager::retrieveAllGroups Method used to attach each group from the database to a given system object
 * @param newSystem Pointer to a system object that we want to add groups to.
 */
void DbManager::retrieveAllGroups(System *newSystem){
    QSqlQuery query;
    query.prepare("SELECT * FROM groups");
    if(query.exec()){
       while(query.next() ){
           int dbGrpID = query.value(0).toInt();
           int dbGrpAdmin = query.value(1).toInt();
           bool dbStatus = query.value(2).toBool();
           QString dbGrpname = query.value(3).toString();
           int dbBlogID = query.value(4).toInt();
           Group *newGroup = new Group(dbGrpID,dbGrpAdmin,dbGrpname,dbStatus,dbBlogID,this);
           newSystem->insertGroup(newGroup);
       }
    }
    else{
        qDebug() << "Issue retrieving all groups: "
                 << query.lastError();
    }
}
/**
 * @brief DbManager::retrieveAllUsersInGroup Method used to attach each user ID associated with a group to that group.
 * @param group Pointer to a group object that we want to add a list of account IDs
 */
void DbManager::retrieveAllUsersInGroup(Group *group){
    QSqlQuery query;
    QString command = "SELECT * FROM groupUsers WHERE GrpID= ";
    command += QString::number(group->getID());

    query.prepare(command);
    if(query.exec()){
        while(query.next() ){ //Pair each account to the chat
             group->addGroupMemberID(query.value(1).toInt() );
        }
    }
    else{
        qDebug() << "Issue pairing users with groups"
                 << query.lastError();
    }
}

bool DbManager::updateTable(const QVariant tableName, const QVariant columnToChange, const QVariant newColumnValue,
                            const QVariant checkField, const QVariant checkFieldValue){
    bool success = false;
    QSqlQuery query;
    QString command = "update ";
    command += tableName.toString();
    command += "set ";
    command += columnToChange.toString();
    command += "= ";
    command += newColumnValue.toString();
    command += " where ";
    command += checkField.toString();
    command += " = ";
    command+= checkFieldValue.toString();
    query.prepare(command);
    if(query.exec()){
        success = true;
    }
    else{
        qDebug() << "Issue modifying table"
                 << query.lastError();
    }
    return success;
}
