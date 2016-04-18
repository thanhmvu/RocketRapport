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

}
