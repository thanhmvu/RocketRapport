#include "gtest/gtest.h"
#include "../model/tweet.h"
#include "../model/tweetpost.h"
#include "../model/dbmanager.h"
#include "../model/account.h"
#include <qdatetime.h>
#include <vector>


TEST(TweetTest, testAddTweetPost){
    DbManager dbmTest("./gProjectDB.db");
    dbmTest.deleteTable("tweetPosts");
    Tweet testB(&dbmTest);

    QDateTime *newDateTime = new QDateTime;
    QDate newDate(2016,5,23);
    newDateTime->setDate(newDate);

    TweetPost *newBP1 = new TweetPost(3,*newDateTime,"MOM'S SPAGHETTI");
    TweetPost *newBP2 = new TweetPost(4,*newDateTime,"Test1");
    TweetPost *newBP3 = new TweetPost(5,*newDateTime,"Test2");
    testB.addPost(newBP1);
    testB.addPost(newBP2);
    testB.addPost(newBP3);
}

TEST(TweetTest,testRetrieveAllTweetPosts){
    DbManager newDBM("./gProjectDB.db");
    newDBM.deleteTable("tweetPosts"); //Start with a fresh table
    newDBM.addTweetPost(0,3,2016,"One");
    newDBM.addTweetPost(1,3,2016,"Two");
    newDBM.addTweetPost(2,3,2016,"Three");
    Tweet one(&newDBM);
   // newDBM.retrieveAllTweetPosts(&one);

    std::vector<TweetPost*> list = one.getMyPosts();
    qDebug() << "Tweet ID: " << one.getTweetID();
    qDebug() << "Number of Tweet posts inside the user's Tweet" << list.size();

    for(int i=0; i<list.size(); i++){
        TweetPost *look = list.at(i);
        qDebug() << look->getID() << ": " << look->getText();
    }
    newDBM.deleteTable("tweetPosts"); //Clean up the table
}

TEST(TweetTest, testDeleteAllPost){
    DbManager newDBM("./gProjectDB.db");
    newDBM.deleteTable("tweets");
    newDBM.deleteTable("tweetPosts");
    Tweet testTweet(0,&newDBM);
    TweetPost *insert1 = new TweetPost(0,QDateTime::currentDateTime(),"Test1");
    TweetPost *insert2 = new TweetPost(1,QDateTime::currentDateTime(),"Test2");
    TweetPost *insert3 = new TweetPost(2,QDateTime::currentDateTime(),"Test3");
    testTweet.addPost(insert1);
    testTweet.addPost(insert2);
    testTweet.addPost(insert3);
    ASSERT_EQ(testTweet.getMyPosts().size(),3);
//    testTweet.deleteAllPosts();
//    ASSERT_EQ(testTweet.getMyPosts().size(),0);
}

TEST(TweetTest, deletePost){
    DbManager dbmTest("./gProjectDB.db");
    dbmTest.deleteTable("tweetPosts");
    Tweet testB(&dbmTest);

    QDateTime *newDateTime = new QDateTime;
    QDate newDate(2016,5,23);
    newDateTime->setDate(newDate);

    TweetPost *newBP1 = new TweetPost(3,*newDateTime,"MOM'S SPAGHETTI");
    testB.addPost(newBP1);
//    testB.deletePost(newBP1);

//    ASSERT_EQ(testB.getMyPosts().size(),0);
}

TEST(TweetTest, getIdCnt){
    Tweet b1(nullptr);
    ASSERT_EQ(b1.getTweetID() + 1 , b1.getIdCnt());
    Tweet b2(nullptr);
    Tweet b3(nullptr);
    ASSERT_EQ(b1.getTweetID() + 3 , b1.getIdCnt());
    ASSERT_EQ(b3.getTweetID() + 1 , b1.getIdCnt());
}


TEST(TweetTest, setTweetID){
    Tweet b1(nullptr);
    b1.setID(100);
    ASSERT_EQ(b1.getTweetID(),100);
    b1.setID(200);
    ASSERT_EQ(b1.getTweetID(),200);
    b1.setID(300);
    b1.setID(400);
    ASSERT_EQ(b1.getTweetID(),400);

    Tweet b2(nullptr);
    b2.setID(100);
    ASSERT_EQ(b2.getTweetID(),100);
    b2.setID(200);
    ASSERT_EQ(b2.getTweetID(),200);
}
