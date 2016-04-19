#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include "feed.h"
#include "tweetpost.h"
#include "account.h"

class Account;

class Group
{
private:
    static int id_cnt;
    int groupID;
    Feed* groupFeed;
    Account* admin;

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
    Account* getAdmin();
    void changeAdmin(Account* newAdmin);
    std::string getGroupName();
    void setGroupName(std::string name);
    std::string getCurrentProject();
    void setCurrentProject(std::string project);
    void newProject(std::string project);
    std::vector<std::string> getPastProjects();

    int getID();

};

#endif // GROUP_H
