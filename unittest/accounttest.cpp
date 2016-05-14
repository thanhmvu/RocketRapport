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
 * Add/Delete Account
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

TEST(AccountTest, testInsertChat){
    DbManager testDbm("./gProjectDB.db");
    Account testAccount(&testDbm);

    Chat* newChat = new Chat(1,"Beth",&testDbm);
    testAccount.insertChat(newChat);

    EXPECT_EQ(testAccount.getChatVector()[0]->getChatID(), newChat->getChatID());

    Chat* newChat2 = new Chat(2,"Tom",&testDbm);
    testAccount.insertChat(newChat2);

    EXPECT_EQ(testAccount.getChatVector()[1]->getChatID(), newChat2->getChatID());
}


TEST(AccountTest, removeChat){
    DbManager testDbm("./gProjectDB.db");
    Account testAccount(&testDbm);

    Chat* newChat = new Chat(1,"Beth",&testDbm);
    testAccount.insertChat(newChat);
    EXPECT_EQ(testAccount.getChatVector()[0]->getChatID(), newChat->getChatID());

    Chat* newChat2 = new Chat(2,"Tom",&testDbm);
    testAccount.insertChat(newChat2);
    EXPECT_EQ(testAccount.getChatVector().size(), 2);

    testAccount.removeChat(newChat);
    EXPECT_EQ(testAccount.getChatVector().size(), 1);
}


TEST(AccountTest, getChatByPartnerName){
    DbManager testDbm("./gProjectDB.db");
    Account testAccount(&testDbm);

    Chat* newChat = new Chat(1,"Beth",&testDbm);
    testAccount.insertChat(newChat);

    EXPECT_EQ(testAccount.getChatByPartnerName("Beth")->getChatID(), newChat->getChatID());

    Chat* newChat2 = new Chat(2,"Tom",&testDbm);
    testAccount.insertChat(newChat2);

    EXPECT_EQ(testAccount.getChatByPartnerName("Tom")->getChatID(), newChat2->getChatID());
}

TEST(AccountTest, joinGroup){
    DbManager testDbm("./gProjectDB.db");
    Account testAccount(&testDbm);

    Group * g = new Group("Group A", &testDbm);
    testAccount.joinGroup(g);
    EXPECT_EQ(testAccount.getGroups()[0]->getID(), g->getID());

    Group * g2 = new Group("Group B", &testDbm);
    testAccount.joinGroup(g2);
    EXPECT_EQ(testAccount.getGroups()[1]->getID(), g2->getID());
}

TEST(AccountTest, leaveGroup){
    DbManager testDbm("./gProjectDB.db");
    Account testAccount(&testDbm);

    Group * g = new Group("Group A", &testDbm);
    testAccount.joinGroup(g);
    Group * g2 = new Group("Group B", &testDbm);
    testAccount.joinGroup(g2);

    EXPECT_EQ(testAccount.getGroups()[0]->getID(), g->getID());
    EXPECT_EQ(testAccount.getGroups()[1]->getID(), g2->getID());

    testAccount.leaveGroup(g);
    EXPECT_EQ(testAccount.getGroups().size(),1);
    testAccount.leaveGroup(g2);
    EXPECT_EQ(testAccount.getGroups().size(),0);
}

TEST(AccountTest, getIdCnt){
    Account b1(nullptr);
    ASSERT_EQ(b1.getAccountID() + 1 , b1.getIdCnt());
    Account b2(nullptr);
    Account b3(nullptr);
    ASSERT_EQ(b1.getAccountID() + 3 , b1.getIdCnt());
    ASSERT_EQ(b3.getAccountID() + 1 , b1.getIdCnt());
}
