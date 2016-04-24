#include "gtest/gtest.h"
#include <QDateTime>
#include "../model/chat.h"
#include "../model/message.h"

//This test works, but it can only be run once unless you change the value of the messageID
//TEST(ChatTest,testSendMessage){
//    DbManager testDb("../gProjectDB.db");
//    Chat test(&testDb);
//    Message *one = new Message;
//    one->setText("Hey Amrit, I generally dislike you");
//    one->setReceiver("Amrit");
//    QDateTime *newDateTime = new QDateTime;
//    QDate newDate(2016,5,23);
//    newDateTime->setDate(newDate);
//    one->setDateTime(*newDateTime);
//    qDebug() << one->getID() << " " << one->getText() << " " << one->getReceiver();
//    test.sendMessage(one);
////    qDebug() << "testing DbManager functionality";
////    testDb.addMessage(test.getChatID(),one->getID(),one->getTimeSent(),one->getText(),one->getReceiver());
//}
