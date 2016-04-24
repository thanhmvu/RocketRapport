#ifndef CHAT_H
#define CHAT_H
#include <stdio.h>
#include <vector>
#include "message.h"
#include "dbmanager.h"
class DbManager;

class Chat
{
private:
    static int id_cnt;
    int chatID;

    QString talkingToUser;
    std::vector<Message*> messages;

    DbManager *dbm;
public:
    Chat(DbManager *newdbm); //Pass in pointer to dbm object that the chat can use for data storage
    int getChatID();
    void addMessage(Message *newMessage);
    void sendMessage(Message * newMessage);
    std::vector<Message *> getMessages();
    QString getTalkingToUser();
    void setTalkingToUser(QString name);
};

#endif // CHAT_H
