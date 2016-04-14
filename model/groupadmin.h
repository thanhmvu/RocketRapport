#ifndef GROUPADMIN_H
#define GROUPADMIN_H
//#include "currentguest.h"
#include "group.h"

class Group;

class GroupAdmin
//        : public CurrentGuest
{

    Group* myGroup;

public:
    GroupAdmin();

    Group* getGroup();
//    void addMember(Account* newMember);
//    void removeMember(Account* oldMember);
    void editGroupName(std::string name);
};

#endif // GROUPADMIN_H
