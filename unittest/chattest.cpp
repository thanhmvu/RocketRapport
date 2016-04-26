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

    qDebug() << one->getID() << " " << one->getText() << " " << one->getReceiver();
    test.sendMessage(one);
}

//TEST(ChatTest, testRetrieveAllMessages){
//    DbManager testDb("./gProjectDB.db");
//    testDb.deleteTable("chats");
//    testDb.addChat(0,1,"Mike");
//    testDb.addChat(0,2,"Vut");

//    Chat *testChat = new Chat(&testDb);
//    std::vector<Message*> listOfMessages = testChat->getMessages();
//    qDebug() << "Chat Id: " << testChat->getChatID() << " Number of messages in this chat: " << listOfMessages.size();
//    for(int i=0; i< listOfMessages.size(); i++){
//        Message *look = listOfMessages.at(i);
//        qDebug() << look->getID() << ": " << look->getText() << " (Sent to " << look->getReceiver() << ")";
//    }
//}
