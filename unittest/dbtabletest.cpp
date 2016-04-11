#include "gtest/gtest.h"
#include <iostream>
#include "../model/dbtool.h"
#include "../model/dbtable.h"
#include "../model/dbtablerranch.h"
using namespace std;

/**
 * @brief TEST will be used to test both the base DBTable class and the derived DBTableRRanch class
 */

TEST(DBTableTest, testDBTableCreation){
    DBTool *dtool = new DBTool("testDBInfo","testDB");
    DBTable dbtable(dtool,"testDB");
    //Terminal should print out "Opened Database successfully"
}

TEST(DBTableTest, testBuildTableMethod){
    DBTool *dtool = new DBTool("testDBInfo","testDB");
    DBTable dbtable(dtool,"testDB");
    dbtable.build_table(); //Used to determine if a table already exists in the given database
    //Note that the build_table method uses two different sets of SQL calls
}

TEST(DBTableTest, testStoreMethod){
    DBTool *dtool = new DBTool("testDBInfo","testDB");
    DBTableRRanch dbtable(dtool,0);
    dbtable.store_template_sql("./","testScript.sql","One Two Three Four");
}
