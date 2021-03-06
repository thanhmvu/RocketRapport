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
    std::vector<Message*> messages; // owns this

    DbManager *dbm;
public:

    Chat(DbManager *newdbm);
    Chat(QString partner, DbManager *newdbm);
    Chat(int newID, QString partner, DbManager *newdbm);
    ~Chat();
    int getChatID();
    void addMessage(Message *newMessage);
    void sendMessage(Message * newMessage);
    std::vector<Message *> getMessages();
    std::vector<Message *> getMessageVector();
    QString getTalkingToUser();
    void setTalkingToUser(QString name);
//    void setChatID(int newID);

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // CHAT_H
