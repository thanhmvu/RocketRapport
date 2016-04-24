#include "dbmanager.h"

int DbManager::id_cnt =0;

/**
 * @brief DbManager::DbManager Class used to "communicate" between the program and the database.
 * @param path String used to specify where the program will be accessing a database file.
 * For now, I'm going to go with the approach where we create 10 different add methods with different sets of parameters
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

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
    qDebug() << "Delete DbManager object";
}

/**
 * @brief DbManager::addUser Method used to add user objects with associated object IDs to
 * @param AcntID   ID number used to associate a User object with a name and a series of other ID's
 * @param FrstName
 * @param LstName
 * @param GrpID
 * @param ScrpBkID
 * @param BlogID
 * @param TweetID
 * @return
 */
bool DbManager::addUser(const QVariant &AcntID, const QVariant &FrstName,
                        const QVariant &LstName, const
                        QVariant &ScrpBkID, const QVariant &BlogID, const QVariant &TweetID,
                        const QVariant &UserName, const QVariant &passWord){
//    std::cout << "Now entering Add User method in DatabaseManager" << std::endl;
    bool success = false;
    QSqlQuery query; //Prepares a new QSqlQuery

    ////////////////////////////////////////////////////////////////////
    /// Need to check if input strings are empty?
    /// If they are empty, will the QGLite command be incorrect?
    //////////////////////////////////////////////////////////////////
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
 * @param GrpID
 * @param GrpAdmnId
 * @param actStatus Boolean signifying if a group is active or not.
 * @param GrpName
 * @param FeedID
 * @return
 */
bool DbManager::addGroup(const QVariant &GrpID, const QVariant &GrpAdmnId, \
                         bool actStatus, const QVariant &GrpName, const QVariant &FeedID){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO TABLE groups VALUES(:GrpID, :GrpAdmnId, :actStatus, :GrpName, :FeedID");
    query.bindValue(":GrpID",GrpID);
    query.bindValue(":GrpAdmnId",GrpAdmnId);
    query.bindValue(":actStatus",actStatus);
    query.bindValue(":GrpName",GrpName);
    query.bindValue(":FeedID",FeedID);
    if(query.exec()){
        success = true;
    }else{
        //Need some kind of print statement to signify that the method didn't work
    }
    return success;
}

/**
 * @brief DbManager::addChat Add a new chat object associated with a patrticular user
 * @param AccountID
 * @param ChatID
 * @param sender
 * @return
 */
bool DbManager::addChat(const QVariant &AccountID, const QVariant &ChatID, const QVariant &sender){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO chats VALUES((:AccountID), (:ChatID), (:Sender)");
    query.bindValue(":AccountID", AccountID);
    query.bindValue(":ChatID", ChatID);
    query.bindValue(":sender", sender);
    if(query.exec()){
        success = true;
    }
    else{
        qDebug() << "Error adding Chat"
                 << query.lastError();
    }
    return success;
}

/**
 * @brief DbManager::addMessage Add messae information to the database
 * @param ChatID
 * @param MessageID
 * @param DateTime
 * @param text
 * @param imageURL  URL directing the program to a directory containing the image it wants to load
 * @param receiver  Name of the user being sent the message
 * @return
 */
bool DbManager::addMessage(const QVariant &ChatID, const QVariant &MessageID, const QVariant &DateTime,
                           const QVariant &text){
    system("pwd");
    bool success = false;
    QSqlQuery query;
    qDebug() << "Status of prepare statement" << query.prepare("INSERT INTO chatMessages VALUES(:ChatID,:MessageID,:dateTime,:Text)");
    query.bindValue(":ChatID", ChatID);
    query.bindValue(":MessageID",MessageID);
    query.bindValue(":dateTime",DateTime);
    query.bindValue(":Text",text);
    qDebug() << "All bound values: " << query.boundValue(0) << " " << query.boundValue(1) << " " << query.boundValue(2) << " " <<
                query.boundValue(3) ;
    if(query.exec()){
        success = true;
    }
    else{
        //Print Statement
    }

    return success;
}

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
 * @return
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
 * @return
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
 * @brief DbManager::retrieveStringInfo
 * @param field
 * @return
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
 * @brief DbManager::rmAll Remove all information from the database.
 * @return Boolean signaling that the database has been deleted.
 */
bool DbManager::rmAllAccounts(){
    QSqlQuery query;
    query.prepare("DELETE FROM accounts");
    return query.exec();
}

///**
// * @brief DbManager::retrieveAllAccounts This method will be used to add every available Account to the given map
// * @param list
// * Note to self: test this in the qSqlTest classes (The ones for experimentation)
// * Refactor this class to work with the accounts map instead of the username list map
// */
//void DbManager::retrieveAllAccounts(std::map<int, QString> *one){
//    QSqlQuery query;
//    query.prepare("SELECT * FROM accounts"); //Choose all elements from the table
//    query.exec();
//    while(query.next() ){
//        QString name = query.value(1).toString();
//        std::pair<int, QString> insert1 = {query.value(0).toInt(),name.toStdString()};
//        std::cout << insert1.first << " " << insert1.second << std::endl;
//        one->insert(insert1);
//    }
//}


void DbManager::retrieveAllBlogPosts(Blog *userBlog){
    QSqlQuery query;
    QString command = "SELECT * FROM blogPosts WHERE BlogID = ";
    QString valStr = QString::number(userBlog->getBlogID());
    command += valStr;
    query.prepare(command);
    query.exec();
    while(query.next()){
        BlogPost *newBP = new BlogPost;
        QString newText1 = query.value(3).toString();
        newBP->setText(newText1);
        newBP->setTime(2); //Should I add a method to blog post that manually sets the blog post ID?
        userBlog->addPost(newBP);
    }
}

void DbManager::retrieveAllMessages(Chat *userChat){
    QSqlQuery query;
    QString command = "SELECT * FROM chatMessages WHERE ChatID= ";
    QString valStr = QString::number(userChat->getChatID());
    command += valStr;
    query.prepare(command);
    query.exec();
    while(query.next()){
        Message *newMessage = new Message;
        newMessage->setDateTime(query.value(2).toDateTime() );
        newMessage->setReceiver( query.value(4).toString() );
        newMessage->setText( query.value(3).toString() );
        userChat->addMessage(newMessage);
    }

}

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

 void DbManager::retrieveAllScbkPosts(Scrapbook *userScBook){
     QSqlQuery query;
     QString command = "SELECT * FROM tweetPosts WHERE TweetID = ";
     QString idValue = QString::number(userScBook->getScrpbkID() );
     command += idValue;
     query.prepare(command);
     query.exec();
 }

/**
 * @brief DbManager::retrieveAllAccounts This method will
 * be used to add every available Account to the given map
 * @param map
 */
void DbManager::retrieveAllAccounts(std::map<QString, Account*> &accounts){
    QSqlQuery query;
//    std::cout <<"Hello from DbManager::retrieveAllAccounts " <<std::endl;
//    std::cout << query.next() << std::endl;
//    std::cout << query.isActive() << std::endl;
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




bool DbManager::addBlogPost(const QVariant &blogPostID, const QVariant &blogID, const QVariant &timeDate, const QVariant &text){
     QSqlQuery query;
     query.prepare("INSERT INTO blogPosts VALUES(::blogPostID, blogID, :timeDate, :text");
     query.bindValue(":blogPostID",blogPostID);
     query.bindValue(":blogID", blogID);
     query.bindValue(":timeDate",timeDate);
     query.bindValue(":text",text);
     if(query.exec()){
         return true;
     }else{
         qDebug() << query.lastError();
         return false;
     }
 }
