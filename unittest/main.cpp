#include <iostream>
#include "gtest/gtest.h"

using namespace std;

TEST(FUNNYTEST, FORNUMBERS) {

  ASSERT_EQ(1, 2) << "1 and 2 are not equal!!!";

}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
