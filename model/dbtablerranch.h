#ifndef DBTABLERRANCH_H
#define DBTABLERRANCH_H
#include <iostream>
#include <string.h>
#include <sqlite3.h>

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbtable.h"
#include "dbtool.h"
#include "account.h"
class DBTable;

/**
 * @brief The DBTableRRanch class is modeled after the overloaded DBTableGame class in the lab, and will work in similar fashion.
 * NOTE: You can incure the wrath of the vtable if you don't include virtual methods stated in the header file.
 */
class DBTableRRanch
{
    DBTool *dtool;

protected:

    int model_id;
    std::string sql_create;
    std::string sql_add_row;
    std::string sql_select_all;

public:
    DBTableRRanch();
    DBTableRRanch(DBTool *db, int model);

    ~DBTableRRanch(); //Destructor

//    // An overloaded method to generate a new
//    // create command for your child class.
    virtual void store_create_sql(std::__cxx11::string scriptName);

//    // An overloaded method to generate a new
//    // insert command for your child class.
    virtual void store_template_sql(std::__cxx11::string location, std::__cxx11::string scriptName, std::__cxx11::string dataEntered);

};

#endif // DBTABLERRANCH_H
