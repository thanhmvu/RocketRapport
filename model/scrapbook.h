#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H
#include "scrapbookpost.h"
#include <vector>

class Scrapbook
{

    std::vector<ScrapbookPost*> myPosts;
    std::string tweetText;

public:
    Scrapbook();

    void addPost(ScrapbookPost* newPost);
    void deletePost(ScrapbookPost* oldPost);
    //  NEEDS TO BE IMPLEMENTED
    void concastPosts();

    std::vector<ScrapbookPost*> getMyPosts();
};

#endif // SCRAPBOOK_H
