#include <iostream>
#include "gtest/gtest.h"
#include "../model/system.h"

using namespace std;

TEST(TestSystem, usernameExist) {
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



int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
