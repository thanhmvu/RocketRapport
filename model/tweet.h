#ifndef TWEET_H
#define TWEET_H
#include "tweetpost.h"
#include <string>
#include "dbmanager.h"
class DbManager;


class Tweet
{
private:
    static int id_cnt;
    int tweetID;
    std::vector<TweetPost*> myPosts;
    QString tweetText;

    DbManager *dbm;

public:
    Tweet(DbManager *newDbm);
    Tweet(int TweetID, DbManager *newDbm);
    ~Tweet();
    void setID(int newID);
    void addPost(TweetPost* newPost);
    void createPost(TweetPost* newPost);
    void deletePost(TweetPost* oldPost);
    void deleteAllPosts();

    std::vector<TweetPost*> getMyPosts();

    int getTweetID();

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // TWEET_H
