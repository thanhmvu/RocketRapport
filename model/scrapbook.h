#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H
#include "scrapbookpost.h"
#include <vector>

class Scrapbook
{
private:
    static int id_cnt;
    int scrpBookID;
    std::vector<ScrapbookPost*> myPosts;
    std::string tweetText;

public:
    Scrapbook();

    void addPost(ScrapbookPost* newPost);
    void deletePost(ScrapbookPost* oldPost);
    //  NEEDS TO BE IMPLEMENTED
    void concastPosts();

    std::vector<ScrapbookPost*> getMyPosts();
    int getScrpbkID();
};

#endif // SCRAPBOOK_H
