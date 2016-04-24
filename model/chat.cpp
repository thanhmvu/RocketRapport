#include "chat.h"

int Chat::id_cnt = 0;

Chat::Chat()
{
    chatID = id_cnt;
    id_cnt++;
}


/**
 * @brief Gets ID of this chat object.
 */
int Chat::getChatID(){
    return chatID;
}


/**
 * @brief "Sends" a message to the database.
 */
void Chat::addMessage(Message *newMessage){
    messages.push_back(newMessage);
}


/**
 * @brief Gets the vector of messages.
 */
std::vector<Message*> Chat::getMessages(){
    return messages;
}


/**
 * @brief Gets the username of the user that this account is talking to.
 */
std::string Chat::getTalkingToUser() {
    return this->talkingToUser;
}


/**
 * @brief Sets the user that is being talked to.
 */
void Chat::setTalkingToUser(std::string name) {
    this->talkingToUser = name;
}
