#include "gtest/gtest.h"
#include <QDateTime>
#include "../model/chat.h"
#include "../model/message.h"

TEST(ChatTest,testSendMessage){
    DbManager testDb("../gProjectDB.db.r161");
    Chat test(&testDb);
    Message *one = new Message;
    one->setText("Hey Amrit, I generally dislike you");
    one->setReceiver("Amrit");
    QDateTime *newDateTime = new QDateTime;
    QDate newDate(2016,5,23);
    newDateTime->setDate(newDate);
    one->setDateTime(*newDateTime);
    qDebug() << one->getID() << " " << one->getText() << " " << one->getReceiver();
    test.sendMessage(one);
//    qDebug() << "testing DbManager functionality";
//    testDb.addMessage(test.getChatID(),one->getID(),one->getTimeSent(),one->getText(),one->getReceiver());
}
