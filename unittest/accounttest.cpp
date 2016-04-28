#include "gtest/gtest.h"
#include "../model/account.h"
#include "../model/chat.h"
#include "../model/dbmanager.h"
#include "../model/message.h"

#include <vector>


/* Test List:
 *
 * Add/Remove Chat
 * Add/Remove Friend
 * Join/Leave Group
 *
 * Depart Ranch
 *
 * Add/Remove Project
 *
 * Add/Delete Account
 *
 * Add/Remove Member
 *
 * */


/**
 * @brief TEST This test is used to to test the various functions of an account.
 * This works!
 */
TEST (AccountTest, addChat) {
    DbManager testDbm("./gProjectDB.db");
    testDbm.deleteTable("chats"); //Start with an empty table
    Account testAccount(&testDbm);
    Chat *testChat = new Chat(0,"Vut",&testDbm);
    qDebug() << "Chat ID: " << testChat->getChatID() << " New User ID: " << testAccount.getAccountID();
    testAccount.addChat(testChat);
}

TEST(AccountTest, testLoadAllMessages){
    DbManager testDbm("./gProjectDB.db");
    Account testAccount(&testDbm);
    std::vector<Chat*> look = testAccount.getMyChats();
    qDebug() << look.size();

    for(int i=0; i<look.size(); i++){
        Chat* check = look[i];
        qDebug() << "Chat ID: " << check->getChatID() << " Sent to: " << check->getTalkingToUser();
        std::vector<Message*> messageList = check->getMessages();
        qDebug() << "Number of messages in this chat: " << messageList.size();

        for(int j =0; j< messageList.size(); j++){
            Message* lookMessage = messageList.at(j);
            qDebug() << lookMessage->getText();
        }

    }

}

//Method works - I wanted to show that we could add new chats
//Test is crashing the system
TEST(AccountTest, testAddChats){
    DbManager testDbm("./gProjectDB.db");
    testDbm.deleteTable("chats");
    Account testAccount(&testDbm);
    Chat* newChat = new Chat(1,"Beth",&testDbm);
    testAccount.addChat(newChat);

    std::vector<Chat*> look = testAccount.getMyChats();
    for(int i=0; i<look.size(); i++){
        Chat* check = look[i];
        qDebug() << "Chat ID: " << check->getChatID() << " Sent to: " << check->getTalkingToUser();
        std::vector<Message*> messageList = check->getMessages();
        qDebug() << "Number of messages in this chat: " << messageList.size();

        for(int j =0; j< messageList.size(); j++){
            Message* lookMessage = messageList.at(j);
            qDebug() << lookMessage->getText();
        }

    }
}


