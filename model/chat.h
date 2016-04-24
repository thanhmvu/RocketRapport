#ifndef CHAT_H
#define CHAT_H
#include <stdio.h>
#include <vector>
#include "message.h"
#include "dbmanager.h"

class Chat
{
private:
    static int id_cnt;
    int chatID;

    std::string talkingToUser;
    std::vector<Message*> messages;
public:
    Chat();
    int getChatID();
    void addMessage(Message *newMessage);
    void sendMessage(Message * newMessage);
    std::vector<Message *> getMessages();
    std::string getTalkingToUser();
    void setTalkingToUser(std::string name);
};

#endif // CHAT_H
