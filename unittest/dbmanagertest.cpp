#include "gtest/gtest.h"
#include "../model/system.h"

TEST(DbManagerTest, test){
    DbManager *test = new DbManager("./testDb.db");
    test->addUser(1,"Jeff","Pfaffmann",1,1,1,1,"JSwizzle101","IamTheWalrus65&");
}
