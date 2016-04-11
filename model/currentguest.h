#ifndef CURRENTGUEST_H
#define CURRENTGUEST_H
#include "account.h"
#include "blog.h"
#include "tweet.h"


class CurrentGuest : public Account
{

    Blog* myBlog;
    Tweet* myTweet;

    bool depart;

public:
    CurrentGuest();

    void departRanch();

    Blog* getMyBlog();
    void setMyBlog(Blog* myBlog);
    Tweet* getMyTweet();
    void setMyTweet(Tweet* myTweet);
    bool getDepart();
    void setDepart(bool depart);
};

#endif // CURRENTGUEST_H
