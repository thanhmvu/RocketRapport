#include "gtest/gtest.h"
#include <QDateTime>
#include <QVariant>
#include "../model/chat.h"
#include "../model/message.h"

//This test works, but it can only be run once unless you change the value of the messageID
TEST(ChatTest,testSendMessage){
    DbManager testDb("./gProjectDB.db");
    testDb.deleteTable("chatMessages");
    Chat test(&testDb);
    Message *one = new Message;
    one->setText("Hi Thanh");
    test.setTalkingToUser("Mike");

    QDateTime *newDateTime = new QDateTime;
    QDate newDate(2016,5,23);
    newDateTime->setDate(newDate);
    one->setDateTime(*newDateTime);
    test.sendMessage(one);
}

TEST(ChatTest, testRetrieveAllMessages){
    DbManager testDb("./gProjectDB.db");
    testDb.deleteTable("chats");
    testDb.addChat(0,1,"Mike");
    testDb.addChat(0,2,"Vut");

    Chat *testChat = new Chat(&testDb);
    std::vector<Message*> listOfMessages = testChat->getMessages();
    qDebug() << "Chat Id: " << testChat->getChatID() << " Number of messages in this chat: " << listOfMessages.size();
    for(int i=0; i< listOfMessages.size(); i++){
        Message *look = listOfMessages.at(i);
        qDebug() << look->getID() << ": " << look->getText();
    }
}

TEST(ChatTest, testGetIdCnt){
    Chat b1(nullptr);
    ASSERT_EQ(b1.getChatID() + 1 , b1.getIdCnt());
    Chat b2(nullptr);
    Chat b3(nullptr);
    ASSERT_EQ(b1.getChatID() + 3 , b1.getIdCnt());
    ASSERT_EQ(b3.getChatID() + 1 , b1.getIdCnt());
}

TEST(ChatTest, testSetTalkingToUser){
    Chat b1(nullptr);
    b1.setTalkingToUser("abc");
    ASSERT_EQ(b1.getTalkingToUser().compare("abc") , 0);
    b1.setTalkingToUser("abc123");
    ASSERT_EQ(b1.getTalkingToUser().compare("abc123") , 0);
    b1.setTalkingToUser("abc456");
    ASSERT_EQ(b1.getTalkingToUser().compare("abc456") , 0);
}

TEST(ChatTest, testAddMessage){
    Chat b1(nullptr);
    Message *m = new Message;
    Message *m1 = new Message;
    Message *m2 = new Message;

    b1.addMessage(m);
    ASSERT_EQ(b1.getMessageVector()[0]->getID(), m->getID());
    b1.addMessage(m1);
    b1.addMessage(m2);
    ASSERT_EQ(b1.getMessageVector()[0]->getID(), m->getID());
    ASSERT_EQ(b1.getMessageVector()[1]->getID(), m1->getID());
    ASSERT_EQ(b1.getMessageVector()[2]->getID(), m2->getID());
}


