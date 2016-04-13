#include "dbmanager.h"

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
 * @param AcntID       ID number used to associate a User object with a name and a series of other ID's
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
                        QVariant &ScrpBkID, const QVariant &BlogID, const QVariant &TweetID){


    bool success = false;
    if(!find(AcntID)){

        QSqlQuery query; //Prepares a new QSqlQuery
        query.prepare("INSERT INTO accounts VALUES (:AcntID, :FrstName, :LstName, :GrpID, :ScrpBkID, :BlogID, :TweetID)");
        query.bindValue(":AcntID", AcntID);
        query.bindValue(":FrstName", FrstName);
        query.bindValue(":LstName", LstName);
        query.bindValue(":GrpID", GrpID);
        query.bindValue(":ScrpBkID", ScrpBkID);
        query.bindValue(":BlogID", BlogID);
        query.bindValue(":TweetID", TweetID);

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

}

/**
 * @brief AccountDatabaseManager::addColumn Used to add a new column to the associated database file
 * @param name  Name of the new created column
 * @param type  Type of data stored in the new column
 * @return  Returns true if we're able to add a new column
 */
bool AccountDatabaseManager::addColumn(const QString name, const QString type){
    QSqlQuery query;
    const QString command = "ALTER TABLE accounts ADD COLUMN " + name + " " + type;
    query.prepare(command);
    query.exec();
}

/**
 * @brief DbManager::find Method used to return a FirstName and LastName given their associated UserID
 * @param UsrID User ID of the account we are searching for.
 * @return
 */
bool DbManager::find(const QVariant &UsrID){
    bool found = false;
    QSqlQuery query;
    query.prepare("SELECT firstName,lastName FROM accounts WHERE AccountId = (:UsrID)");
    query.bindValue(":UsrID",UsrID);
    if (query.exec()){
        if(query.next()){
            found = true;
            std::cout<< "Account has been found" << std::endl;
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
    if(find(UsrID) ){
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
bool DbManager::rmAll(){
    QSqlQuery query;
    query.prepare("DELETE FROM accounts");
    query.exec();
}
