#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include "feed.h"
#include "tweetpost.h"
#include "account.h"
#include "dbmanager.h"

class Account;
class DbManager;

class Group
{
private:
    static int id_cnt;
    int groupID;
    Feed* groupFeed;
    int adminID;
    Account* admin;

    std::vector<int> groupMemberIDs;
    std::vector<Account*> groupMembers;
    std::vector<QString> pastProjects;

    bool isActive;
    QString groupName;
    QString currentProject;

public:
    Group();
    Group(int gID, int GrpAdminID, QString gName, bool newStatus, int newFeedID);
    ~Group();

    ////////////////////////////////////////////////////////////////////
    /// Some methods may need to check:
    ///     if an account is member of the group
    ///     if an account is group admin
    ///     if an account is system admin
    //////////////////////////////////////////////////////////////////

//    bool isMember(Account * caller);

//    void updateFeed(Account* userPosted, TweetPost* latestPost);
    void addGroupMember(Account* newMember);
    void addGroupMemberID(int newID);
//    void removeGroupMember(Account* oldMember);
//    void addToPastProjects(QString project);

//    Feed* Feed();
    bool getIsActive();
//    void setIsActive(bool active);
    std::vector<Account*> getGroupMembers();
    std::vector<int> getGroupMemberIDs();
    Account* getAdmin();
//    void changeAdmin(Account* newAdmin);
    QString getGroupName();
    void setGroupName(QString name);

//    QString getCurrentProject();
//    void setCurrentProject(QString project);
//    void newProject(QString project);
//    std::vector<QString> getPastProjects();
    Feed* getFeed();
    int getID();
    int getAdminID();
    bool setStatus(bool activeState);

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // GROUP_H
