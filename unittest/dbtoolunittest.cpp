#include "gtest/gtest.h"
#include "../model/dbtool.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * @brief TEST This test is used to see if the tool can close a designated
 */
TEST(dbToolTest, testOpenExistingDataBase){
    DBTool dtool("testDBInfo","testDB");
    ASSERT_TRUE(dtool.getAcessState());
}

