#include "gtest/gtest.h"
#include <stdio.h>
#include <vector>
#include "../model/blog.h"
#include "../model/blogpost.h"
#include "../model/chat.h"
#include "../model/message.h"
#include "../model/tweet.h"
#include "../model/tweetpost.h"
#include "../model/system.h"
#include "../model/dbmanager.h"

TEST(DbManagerTest, testRetrieveAllBlogs){
    DbManager one("../gProjectDB.db");
    Blog *b1 = new Blog(&one);
    qDebug() << b1->getBlogID();
    one.retrieveAllBlogPosts(b1);
    std::vector<BlogPost*> bPosts = b1->getMyPosts();

    std::cout<< "Number of blog posts inside the blog: " << bPosts.size() << std::endl;

    for(unsigned i=0; i<bPosts.size(); i++){
        BlogPost *look = bPosts.at(i);
        std::cout<< look->getID() << ": " << look->getText().toStdString() << std::endl;
    }
}

TEST(DbManagerTest, testRetrieveAllMessages){
    DbManager one("../gProjectDB.db");
    Chat *uChat = new Chat(&one);
    qDebug() << "Chat ID: " << uChat->getChatID();
    one.retrieveAllMessages(uChat);
    std::vector<Message*> chatMessages = uChat->getMessages();
    std::cout<< "Number of messages inside the chat: " << chatMessages.size() << std::endl;

    for(unsigned i=0; i<chatMessages.size() ; i++){
        Message *look = chatMessages.at(i);
        std::cout << look->getID() << ": " << look->getText().toStdString() << std::endl;
    }

}

//TEST(DbManagerTest, testRetrieveAllTweets){
//    DbManager one("./gProjectDB.db");
//    Tweet *uTweet = new Tweet(&one);
//    TweetPost newTP; newTP.setText("Now I am become death");
//    uTweet->addPost(&newTP);
//    one.retrieveAllTweets(uTweet);
//    std::vector<TweetPost*> tweetPosts = uTweet->getMyPosts();

//    for(int i=0; i<tweetPosts.size(); i++){
//        TweetPost *look = tweetPosts.at(i);
//        qDebug() << look->getID() << ": " << look->getText();
//    }
//    one.deleteTable("tweets");
//}

TEST(DbManager, testAddChat){
    DbManager one("./gProjectDB.db");
    one.addChat(4,0,"Chun Wai");
}


TEST(DbManagerTest, testConstructor){
    DbManager *test = new DbManager("./testDb.db");
    system("pwd"); // call command "pwd" in the terminal
    test->addUser(1,"Jeff","Pfaffmann",1,1,1,"JSwizzle","IamTheWalrus");
    test->addUser(2,"Chun Wai","Liew",2,2,2,"ChunnieMathews","GreenTea");
    test->printAllRows("FirstName");
    qDebug() << "Now deleting first test object";
    //Destroy, then recreate the database. Call print all rows. Jeff Should still be in the database
    delete test;
    DbManager *test2 = new DbManager("./testDb.db");
    test2->printAllRows("FirstName");
    //It works!
}

TEST(DbManagerTest, testIntRetrieve){
    DbManager *test1 = new DbManager("./testDb.db");
    EXPECT_TRUE( test1->retrieveIntInfo("AccountID","accounts","FirstName","Chun Wai") == 2) ;
    EXPECT_TRUE( test1->retrieveIntInfo("GrpID","accounts","FirstName","Chun Wai") == 2);
    EXPECT_TRUE( test1->retrieveIntInfo("ScrpBkID","accounts","FirstName","Chun Wai") == 2);
    EXPECT_TRUE( test1->retrieveIntInfo("BlogID","accounts","FirstName","Chun Wai") == 2);
    EXPECT_TRUE( test1->retrieveIntInfo("TweetID","accounts","FirstName","Chun Wai") == 2);
}

TEST(DbManagerTest, testStringRetrieve){
    DbManager *test1 = new DbManager("./testDb.db");
    EXPECT_TRUE(test1->retrieveStringInfo("UserName","accounts","AccountID",1) == "JSwizzle");
}

//The remove all method works, but I decided to comment it out in the interest of getting a working .db file
TEST(DbManagerTest, testRemoveAllMethod){
    DbManager *test1 = new DbManager("./testDb.db");
    test1->printAllRows("FirstName");
    test1->rmAllAccounts();
    test1->printAllRows("FirstName"); //Should show an empty set
    delete test1;
    qDebug() << "Deleted first DbManager";
    DbManager *test2 = new DbManager("./testDb.db"); //Recreating the database manager and printing its contents should show an empty list
    test2->printAllRows("FirstName");
}

