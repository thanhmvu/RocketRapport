#include "chat.h"

int Chat::id_cnt = 0;

/**
 * @brief Chat::Chat Constructor for a new Chat object
 * @param newdbm Pointer to a database manager object that will be used for data storage and retrieval
 */
Chat::Chat(DbManager *newdbm)
{
    dbm = newdbm; //Start by setting the local dbm object to the parameter dbm pointer
    chatID = id_cnt;
    id_cnt++;
}

/**
 * @brief Chat::Chat Constructor for a new Chat object
 * @param partner Name of the user that the current user sends a message to
 * @param newdbm Pointer to a dbm object that will be used for data storage and retrieval
 */
Chat::Chat(QString partner, DbManager *newdbm)
{
    chatID = id_cnt;
    id_cnt++;

    talkingToUser = partner;
    dbm = newdbm;
}

/**
 * @brief special constructor used for loading from the database
 * @param newID ID for this chat object that is pulled from the database
 * @param partner Name of the account the current user is sending a message to
 * @param newdbm Pointer to a database manager object that will be used for data storage and retrieval
 */
Chat::Chat(int newID, QString partner, DbManager *newdbm)
{
    chatID = newID;
    // update id_cnt if needed
    if(newID >= id_cnt){
        id_cnt = newID + 1;
    }

    talkingToUser = partner;
    dbm = newdbm;
}

/**
 * @brief Chat::~Chat Destructor for the chat object
 */
Chat::~Chat(){
    while(!messages.empty()){
        delete messages.back();
        messages.pop_back();
    }
}


/**
 * @brief Gets ID of this chat object.
 */
int Chat::getChatID(){
    return chatID;
}


/**
 * @brief Adds a message to the vector of messages.
 */
void Chat::addMessage(Message *newMessage){
    messages.push_back(newMessage);

}

/**
 * @brief "Sends" a message to the database.
 */
void Chat::sendMessage(Message *newMessage) {
    this->addMessage(newMessage);
    dbm->addMessage(chatID,newMessage->getID(),newMessage->getTimeSent(),
                    newMessage->getText());
}

/**
 * @brief Gets the vector of messages.
 */
std::vector<Message*> Chat::getMessages(){
    //Delete all messages from the local memory
    while(!messages.empty()){
        delete messages.back();
        messages.pop_back();
    }
    //Retrieve all messages from the database
    dbm->retrieveAllMessages(this);
    return messages;
}


/**
 * @brief Gets the username of the user that this account is talking to.
 */
QString Chat::getTalkingToUser() {
    return this->talkingToUser;
}


/**
 * @brief Sets the user that is being talked to.
 */
void Chat::setTalkingToUser(QString name) {
    this->talkingToUser = name;
}

//void Chat::setChatID(int newID){
//    chatID = newID;
//    // update id_cnt if needed
//    if(newID >= id_cnt){
//        id_cnt = newID + 1;
//    }
//}
