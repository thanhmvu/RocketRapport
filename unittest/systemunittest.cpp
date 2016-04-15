#include "gtest/gtest.h"
#include "../model/system.h"
//I want to test that the different methods in the system class can call their respective scripts

/**
 * @brief TEST This test should be able to store the Accounts into the database, which can be retrieved in another session.
 */
TEST(SystemTest, testDestructor){
    System *one = new System();
    Account Harvey("hSwizzle79");
    one->addAccount(&Harvey);

}
