#include "gtest/gtest.h"
#include "../model/group.h"
#include "../model/account.h"
#include "../model/dbmanager.h"

TEST(GroupTest, TestAddGroupMember){
    DbManager dbm("./gProjectDB.db");
    Group g("The flying sex snakes",&dbm);
    Account *user = new Account(&dbm);
    g.addGroupMember(user);

    EXPECT_EQ(g.getGroupMembers()[0]->getAccountID(), user->getAccountID());

}

TEST(GroupTest, TestAddGroupMemberID){
    DbManager dbm("./gProjectDB.db");
    Group g("The flying sex snakes",&dbm);
    g.addGroupMemberID(123);

    EXPECT_EQ(g.getGroupMemberIDs()[0], 123);


    g.addGroupMemberID(321);

    EXPECT_EQ(g.getGroupMemberIDs()[0], 123);
    EXPECT_EQ(g.getGroupMemberIDs()[1], 321);
}

TEST(GroupTest, TestSetGroupName){
    DbManager dbm("./gProjectDB.db");
    Group g("The flying sex snakes",&dbm);
    QString name = "above average";
    g.setGroupName(name);

    EXPECT_EQ(g.getGroupName().compare("above average"), 0);

    name = "below average";
    g.setGroupName(name);

    EXPECT_EQ(g.getGroupName().compare("below average"), 0);
}

TEST(GroupTest, TestSetAboutGroup){
    DbManager dbm("./gProjectDB.db");
    Group g("The flying sex snakes",&dbm);
    QString name = "above average";
    g.setAboutGroup(name);

    EXPECT_EQ(g.getAboutGroup().compare("above average"), 0);

    name = "below average";
    g.setAboutGroup(name);

    EXPECT_EQ(g.getAboutGroup().compare("below average"), 0);
}

TEST(GroupTest, getIdCnt){
    DbManager dbm("./gProjectDB.db");
    Group b1("1",&dbm);
    ASSERT_EQ(b1.getID() + 1 , b1.getIdCnt());
    Group b2("2",&dbm);
    Group b3("3",&dbm);
    ASSERT_EQ(b1.getID() + 3 , b1.getIdCnt());
    ASSERT_EQ(b3.getID() + 1 , b1.getIdCnt());
}

