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
    /**
     * @brief Chat::Chat Constructor for a new Chat object
     * @param newdbm Pointer to a database manager object that will be used for data storage and retrieval
     */
    Chat(DbManager *newdbm);
    /**
     * @brief Chat::Chat Constructor for a new Chat object
     * @param partner Name of the user that the current user sends a message to
     * @param newdbm Pointer to a dbm object that will be used for data storage and retrieval
     */
    Chat(QString partner, DbManager *newdbm);
    /**
     * @brief special constructor used for loading from the database
     * @param newID ID for this chat object that is pulled from the database
     * @param partner Name of the account the current user is sending a message to
     * @param newdbm Pointer to a database manager object that will be used for data storage and retrieval
     */
    Chat(int newID, QString partner, DbManager *newdbm);
    /**
     * @brief Chat::~Chat Destructor for the chat object
     */
    ~Chat();
    /**
     * @brief Gets ID of this chat object.
     */
    int getChatID();
    /**
     * @brief Adds a message to the vector of messages.
     */
    void addMessage(Message *newMessage);
    void sendMessage(Message * newMessage);
    std::vector<Message *> getMessages();
    QString getTalkingToUser();
    void setTalkingToUser(QString name);
//    void setChatID(int newID);

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // CHAT_H
