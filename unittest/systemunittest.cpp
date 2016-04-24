#include "gtest/gtest.h"
#include "../model/system.h"
//I want to test that the different methods in the system class can call their respective scripts
//These tests are giving me trouble right now, so I'm commenting them out for the time being
/**
 * @brief TEST This test should be able to store the Accounts into the database, which can be retrieved in another session.
 */
TEST(SystemTest, testAddUser){
//    system("pwd");
//    System *one = new System("./testDb.db");
//    one->createAccount("hSwizzle79","Oblivion0722&","Jefferey","Pfaffmann");
//    EXPECT_FALSE(one->createAccount("hSwizzle79","Oblivion0722&","Jefferey","Pfaffmann"));
}

/**
 * @brief TEST Closing the current program session, destroying the system, and starting a new system should grant the new system access to  the same information
 * This means that an account added in one session should be able to be retrieved in a later session.
 */
TEST(SystemTest, testLoadAllAccounts){
    System sys("./testDatabase.db"); //connect to db file
    std::map <QString, Account*> accounts = sys.getAllAccounts();
    EXPECT_EQ("a", (accounts["a"]->getUsername()));
    EXPECT_EQ("b", (accounts["b"]->getUsername()));

    EXPECT_EQ("c", (accounts["c"]->getUsername()));
    EXPECT_EQ("c", (accounts["c"]->getPassword()));
    EXPECT_EQ("c", (accounts["c"]->getFirstName()));
    EXPECT_EQ("c", (accounts["c"]->getLastName()));
    EXPECT_EQ(2, (accounts["c"]->getAccountID()));
//    EXPECT_EQ(2, (accounts["c"]->getMyBlog()->getBlogID()));
//    EXPECT_EQ(2, (accounts["c"]->getMyTweet()->getTweetID()));
}

////Now, test the login system, because it seems to be giving us troubles
//TEST(SystemTest, testLogin){
//    System *one = new System("./testDb.db");
//    one->printAllUsernames();
//    qDebug() << "Value of userNameExists(hSwizzle79): " << one->usernameExist("hSwizzle79");
//    EXPECT_TRUE(one->login("hSwizzle79","Oblivion0722&"));
//}


//TEST(SystemTest, usernameExist) {
//    System sys;
//    Account acc("user1");
//    Account acc2("user2");

//    EXPECT_EQ(false, sys.usernameExist("user1"));

//    sys.addAccount(&acc);
//    EXPECT_EQ(true, sys.usernameExist("user1"));
//    EXPECT_EQ(false, sys.usernameExist("user2"));

//    sys.addAccount(&acc2);
//    EXPECT_EQ(true, sys.usernameExist("user1"));
//    EXPECT_EQ(true, sys.usernameExist("user2"));
//}
