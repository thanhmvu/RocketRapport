#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include "groupadmin.h"
#include "feed.h"
#include "tweetpost.h"
#include "account.h"

class GroupAdmin;
class Account;

class Group
{

    Feed* groupFeed;
    GroupAdmin* admin;

    std::vector<Account*> groupMembers;
    std::vector<std::string> pastProjects;

    bool isActive;
    std::string groupName;
    std::string currentProject;

public:
    Group();

    void updateFeed(Account* userPosted, TweetPost* latestPost);
    void addGroupMember(Account* newMember);
    void removeGroupMember(Account* oldMember);
    void addToPastProjects(std::string project);

    Feed* getFeed();
    bool getIsActive();
    void setIsActive(bool active);
    std::vector<Account*> getGroupMembers();
    GroupAdmin* getAdmin();
    void changeAdmin(GroupAdmin* newAdmin);
    std::string getGroupName();
    void setGroupName(std::string name);
    std::string getCurrentProject();
    void setCurrentProject(std::string project);
    void newProject(std::string project);
    std::vector<std::string> getPastProjects();
};

#endif // GROUP_H
