#include "gtest/gtest.h"
#include "../model/group.h"
#include "../model/account.h"
#include "../model/dbmanager.h"

TEST(GroupTest, TestAddMember){
    DbManager dbm("./gProjectDB.db");
    Group testGroup("The flying sex snakes",&dbm);
    //Account *user = new Account("")
    //Group.addGroupMemberID();
}
