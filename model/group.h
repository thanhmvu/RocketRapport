#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include "blog.h"
#include "account.h"
#include "dbmanager.h"

class Account;
class DbManager;
class Blog;

class Group
{
private:
    static int id_cnt;
    int groupID;
    Blog* groupBlog;
    int adminID;
    Account* admin;

    std::vector<int> groupMemberIDs;
    std::vector<Account*> groupMembers;
    std::vector<QString> pastProjects;

    bool isActive;
    QString groupName;
    QString aboutGroup;
    QString currentProject;

    DbManager* dbm;

public:
    Group(QString gName, DbManager *newdbm);
    Group(int gID       , int GrpAdminID    , QString gName,
          bool newStatus, int newBlogID     , DbManager *newdbm, QString groupDescription);
    ~Group();

    bool isMember(QString user);

//    void updateBlog(Account* userPosted, TweetPost* latestPost);
    bool addGroupMember(Account* newMember);
    void addGroupMemberID(int newID);
//    void removeGroupMember(Account* oldMember);
//    void addToPastProjects(QString project);

//    Blog* Blog();
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
    Blog* getBlog();
    int getID();
    int getAdminID();
    bool setStatus(bool activeState);

    bool setAboutGroup(QString aboutUs);
    QString getAboutGroup();

    void retrieveAllPosts();

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // GROUP_H
