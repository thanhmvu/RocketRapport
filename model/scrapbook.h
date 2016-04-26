#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H
#include "scrapbookpost.h"
#include <vector>
#include <QString>

class Scrapbook
{
private:
    static int id_cnt;
    int scrpBookID;
    std::vector<ScrapbookPost*> myPosts;
    QString tweetText;

public:
    Scrapbook();
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
