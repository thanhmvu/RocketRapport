#include "gtest/gtest.h"
#include "../model/system.h"
//I want to test that the different methods in the system class can call their respective scripts

/**
 * @brief TEST This test should be able to store the Accounts into the database, which can be retrieved in another session.
 */
TEST(SystemTest, testAddUser){
    System *one = new System();
    Account Harvey("hSwizzle79");
    one->addAccount(&Harvey);
    one->printAllUsernames();
}


TEST(SystemTest, usernameExist) {
    System sys;
    Account acc("user1");
    Account acc2("user2");

    EXPECT_EQ(false, sys.usernameExist("user1"));

    sys.addAccount(&acc);
    EXPECT_EQ(true, sys.usernameExist("user1"));
    EXPECT_EQ(false, sys.usernameExist("user2"));

    sys.addAccount(&acc2);
    EXPECT_EQ(true, sys.usernameExist("user1"));
    EXPECT_EQ(true, sys.usernameExist("user2"));
}
