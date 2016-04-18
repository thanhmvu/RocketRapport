#include "gtest/gtest.h"
#include <stdio.h>
#include "../model/system.h"

TEST(DbManagerTest, testConstructor){
    DbManager *test = new DbManager("./testDb.db");
    system("pwd");
    test->addUser(1,"Jeff","Pfaffmann",1,1,1,1,"JSwizzle","IamTheWalrus");
    test->addUser(2,"Chun Wai","Liew",2,2,2,2,"ChunnieMathews","GreenTea");
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
}

TEST(DbManagerTest, )

TEST(DbManagerTest, testRemoveAllMethod){
    DbManager *test1 = new DbManager("./testDb.db");
    test1->printAllRows("FirstName");
    test1->rmAll();
    test1->printAllRows("FirstName"); //Should show an empty set
    delete test1;
    qDebug() << "Deleted first DbManager";
    DbManager *test2 = new DbManager("./testDb.db"); //Recreating the database manager and printing its contents should show an empty list
    test2->printAllRows("FirstName");
}
