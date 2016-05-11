#ifndef SYSTEMADMIN_H
#define SYSTEMADMIN_H
#include "currentguest.h"
#include "system.h"


class SystemAdmin : public CurrentGuest
{

    System* theSystem;

public:
    SystemAdmin();

    void addGroup(Group* newGroup);
    void deleteGroup(Group* oldGroup);
    void addAccount(Account* newAccount, std::string username, std::string firstName, std::string lastName);
    void deleteAccount(Account* oldAccount);
    void deleteBlogPost(Blog* targetBlog, BlogPost* badPost);
    void deleteTweetPost(Tweet* targetTweet, TweetPost* badPost);
    void deleteScrapbookPost(Scrapbook* targetScrapbook, ScrapbookPost* badPost);

    System* getSystem();
    void setSystem(System* newSystem);
};

#endif // SYSTEMADMIN_H
