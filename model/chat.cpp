#include "chat.h"

int Chat::id_cnt = 0;

Chat::Chat(DbManager *newdbm)
{
    dbm = newdbm; //Start by setting the local dbm object to the parameter dbm pointer
    chatID = id_cnt;
    id_cnt++;
    dbm->retrieveAllMessages(this); //Retrieve all messages associated with this chat
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
 * Remember that each of the messageIDs must be unique.
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
    //Retrieve all messages from the database
    messages.clear(); //Delete all messages from the local memory
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
