#include "dbmanager.h"

/**
 * @brief DbManager::DbManager Class used to "communicate" between the program and the database.
 * @param path String used to specify where the program will be accessing a database file.
 * For now, I'm going to go with the approach where we create 10 different add methods with different sets of parameters
 */
DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);


    if (!m_db.open()){
        std::cout << "Error: Connection with database failure" << std::endl;
    }
    else{
        std::cout << "Database: Connection is A-Ok" << std::endl;
    }
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
                        const QVariant &LstName, const QVariant &GrpID, const
                        QVariant &ScrpBkID, const QVariant &BlogID, const QVariant &TweetID,
                        const QVariant &UserName, const QVariant &passWord){
    bool success = false;
    QSqlQuery query(m_db); //Prepares a new QSqlQuery

    if(!find(AcntID, "accounts") ){
        std::cout << "Value not found" << std::endl;
        query.prepare("INSERT INTO accounts VALUES ( (:AcntID),(:FrstName),(:LstName),(:GrpID),(:ScrpBkID),(:BlogID),(:TweetID),(:UserName),(:PassWord) )");
        query.bindValue(":AcntID", AcntID);
        query.bindValue(":FrstName", FrstName);
        query.bindValue(":LstName", LstName);
        query.bindValue(":GrpID", GrpID);
        query.bindValue(":ScrpBkID", ScrpBkID);
        query.bindValue(":BlogID", BlogID);
        query.bindValue(":TweetID", TweetID);
        query.bindValue(":UserName",UserName);
        query.bindValue(":PassWord",passWord);
        qDebug() << query.boundValue(0) << query.boundValue(1) << query.boundValue(2) << query.boundValue(3) << query.boundValue(4) <<
                            query.boundValue(5) << query.boundValue(6) << query.boundValue(7) << query.boundValue(8);

        if(query.exec()){
            success = true;
        }
        else{
            qDebug() << "removePerson error: "
                     << query.lastError();
        }
    }
    else{
        std::cout << "Element already contained in database" << std::endl;
        return success;
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
                         bool actStatus, const QVariant GrpName, const QVariant FeedID){
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
    }
    else{
        //Need some kind of print statement to signify that the method didn't work
    }
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
    query.prepare("INSERT INTO TABLE chats VALUES(:AccountID, :ChatID, :sender)");
    query.bindValue(":AccountID", AccountID);
    query.bindValue(":ChatID", ChatID);
    query.bindValue(":sender", sender);
    if(query.exec()){
        success = true;
    }
    else{
        //Print statement
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
                           const QVariant text, const QVariant imageURL, const QVariant receiver){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO messages VALUES(:ChatID, :MessageID, :DateTime, :text, :imageURL, :receiver");
    query.bindValue(":ChatID", ChatID);
    query.bindValue(":MessageID",MessageID);
    query.bindValue(":DateTime",DateTime);
    query.bindValue(":text",text);
    query.bindValue(":imageURL",imageURL);
    query.bindValue(":receiver",receiver);
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
    query.exec();
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
            std::cout<< "Value has been found" << std::endl;
        }
        else{
            std::cout << "Value has not been found" << std::endl;
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
 * @brief DbManager::retrieveIntInfo Supposed to work as a generic method that can retrieve any integer value stored in any table and any field
 * @param ID    The value we use to find an associated integer value in the given table
 * @param location
 * @param fieldName
 * @param checkName
 * @return
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
std::string DbManager::retrieveStringInfo(QString location, QVariant &field){

}



/**
 * @brief DbManager::rmAll Remove all information from the database.
 * @return Boolean signaling that the database has been deleted.
 */
bool DbManager::rmAll(){
    QSqlQuery query;
    query.prepare("DELETE FROM accounts");
    query.exec();
}

/**
 * @brief DbManager::retrieveAllAccounts This method will be used to add every available Account to the given map
 * @param list
 * Note to self: test this in the qSqlTest classes (The ones for experimentation)
 */
void DbManager::retrieveAllAccounts(std::map<int, std::string> *one){
    QSqlQuery query;
    query.prepare("SELECT * FROM accounts");        //Choose all elements from the table
    query.exec();
    if( query.first() ){

        QString name1 = query.value(1).toString();
        std::pair<int, std::string> insert0 = {query.value(0).toInt(),name1.toStdString()};
        //std::cout << insert0.first << " " << insert0.second << std::endl;
        one->insert(insert0);
        while(query.next() ){
            qDebug() << "Found another row";
            QString name = query.value(1).toString();
            std::pair<int, std::string> insert1 = {query.value(0).toInt(),name.toStdString()};
            //std::cout << insert1.first << " " << insert1.second << std::endl;
            one->insert(insert1);
        }
        std::cout << "All rows of table exhausted " << std::endl;

    }
    else{
        qDebug() << "No first row found";
    }
}
