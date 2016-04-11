#include "group.h"

Group::Group()
{

}


/**
 * @brief Adds a new account/user to the group.
 */
void Group::addGroupMember(Account* newMember) {
    this->getGroupMembers().push_back(newMember);
}


/**
 * @brief Removes an account/user from the group.
 */
void Group::removeGroupMember(Account* oldMember) {
    for (int i = 0; i < this->getGroupMembers().size(); i++) {
        if (&(*oldMember) == &(*(this->getGroupMembers()[i]))) {
            this->getGroupMembers().erase(this->getGroupMembers().begin() + i);
            break;
        }
    }
}


/**
 * @brief Getter that returns the list of members in this group.
 */
std::vector<Account*> Group::getGroupMembers() {
    return this->groupMembers;
}


/**
 * @brief Getter that returns the name of the group.
 */
std::string Group::getGroupName() {
    return this->groupName;
}


/**
 * @brief Setter that sets the name of this group.
 */
void Group::setGroupName(std::string name) {
    this->groupName = name;
}
