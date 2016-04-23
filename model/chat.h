#ifndef CHAT_H
#define CHAT_H
#include <stdio.h>
#include <vector>
#include "message.h"

class Chat
{
private:
    static int id_cnt;
    int chatID;
    std::vector<Message*> messages;
public:
    Chat();
    int getChatID();
    void addMessage(Message *newMessage);
    std::vector<Message *> getMessages();
};

#endif // CHAT_H
