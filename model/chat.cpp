#include "chat.h"

int Chat::id_cnt = 0;

Chat::Chat(DbManager *newdbm)
{
    dbm = newdbm; //Start by setting the local dbm object to the parameter dbm pointer
    chatID = id_cnt;
    id_cnt++;
}

Chat::Chat(QString partner, DbManager *newdbm)
{
    chatID = id_cnt;
    id_cnt++;

    talkingToUser = partner;
    dbm = newdbm;
}

/**
 * @brief special constructor used for loading from the database
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
