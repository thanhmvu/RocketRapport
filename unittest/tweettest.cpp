#include "gtest/gtest.h"
#include "../model/tweet.h"
#include "../model/tweetpost.h"
#include "../model/dbmanager.h"

TEST(TweetTest, testAddTweet){
    DbManager testDBM("./gProjectDB.db");
    testDBM.deleteTable("tweetPosts");
    Tweet newT(&testDBM);
    qDebug() << "New Tweet ID: " << newT.getTweetID(); //Tweet ID is 2

    QDateTime *newDateTime = new QDateTime;
    QDate newDate(2016,5,23);
    newDateTime->setDate(newDate);

    TweetPost new1; new1.setText("#BilboBaggins"); new1.setTime(*newDateTime);
    TweetPost new2; new2.setText("I read a pretty great book today"); new2.setTime(*newDateTime);
    newT.addPost(&new1); newT.addPost(&new2);

}
