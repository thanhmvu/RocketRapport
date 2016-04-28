#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H
#include "scrapbookpost.h"
#include <vector>
#include <QString>
#include "account.h"

class Account;

// scrapbook should not have to touch database.
// just simply print out the info pulled from thw owner's account
class Scrapbook
{
private:
    static int id_cnt;
    int scrpBookID;
    std::vector<ScrapbookPost*> myPosts;
    QString tweetText;
    Account * owner;

public:
    Scrapbook(Account* sb_owner);
    Scrapbook(int newID, Account* sb_owner);
    ~Scrapbook();

    void setID(int newID);
    void addPost(ScrapbookPost* newPost);
    void deletePost(ScrapbookPost* oldPost);
    //  NEEDS TO BE IMPLEMENTED
    void concastPosts();

    std::vector<ScrapbookPost*> getMyPosts();
    int getScrpbkID();

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // SCRAPBOOK_H
