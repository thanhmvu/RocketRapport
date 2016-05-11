#include "groupadmin.h"


GroupAdmin::GroupAdmin()
{

}

/**
 * @brief Getter that returns the group that this group admin is in charge of.
 */
Group* GroupAdmin::getGroup() {
    return this->myGroup;
}


///**
// * @brief Adds a new account/user to the group that this admin is in charge of.
// */
//void GroupAdmin::addMember(Account* newMember) {
//    this->getGroup()->addGroupMember(newMember);
//}


///**
// * @brief Removes an account/user from the group that this admin is in charge of.
// */
//void GroupAdmin::removeMember(Account* oldMember) {
//    this->getGroup()->removeGroupMember(oldMember);
//}


/**
 * @brief Changes the name of the group that this admin is in charge of.
 */
void GroupAdmin::editGroupName(std::string name) {
    this->getGroup()->setGroupName(name);
}
