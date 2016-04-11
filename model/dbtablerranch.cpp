#include "dbtablerranch.h"

DBTableRRanch::DBTableRRanch()
{

}

/**
 * @brief DBTableRRanch::DBTableRRanch
 * @param db
 * @param model
 * I decided to remove the std::string parameter called "name" because it did not appear to serve a function.
 */
DBTableRRanch::DBTableRRanch(DBTool *db, int model){
    model_id = model;
    dtool = db;

}

DBTableRRanch::~DBTableRRanch(){

}

/**
 * @brief DBTableRRanch::store_create_sql
 * @param scriptName Designates which script we want to utilize. Each script will be used to create a different
 * type of table
 */
void DBTableRRanch::store_create_sql(std::string scriptName){

}

/**
 * @brief DBTableRRanch::store_template_sql Use this method to store different rows of information
 * Either this method needs to work with all kinds of databases, or I need to create multiple methods
 * @param scriptName Designates which script we want to utilize from a directory full of scripts. Each script will be used to
 * add a different row of data.
 * @param A string containing the different data fields we want to place inside the table.
 * This method will also give the system permission to access the given script.
 */
void DBTableRRanch::store_template_sql(std::string location, std::string scriptName,std::string dataEntered){
    std::string command = location + scriptName + " " + dataEntered;
    std::cout << "Command entered: " << command << std::endl;
    std::string permission = "chmod +x " + location + scriptName;
    system(permission.c_str() );                                    //Gives the system permission to access a given script
    system(command.c_str() );
}


