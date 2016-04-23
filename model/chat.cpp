#include "chat.h"

int Chat::id_cnt = 0;

Chat::Chat()
{
    chatID = id_cnt;
    id_cnt++;
}

int Chat::getChatID(){
    return chatID;
}

void Chat::addMessage(Message *newMessage){
    messages.push_back(newMessage);
}

std::vector<Message*> Chat::getMessages(){
    return messages;
}
