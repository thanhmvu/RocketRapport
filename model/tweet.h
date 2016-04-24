#ifndef TWEET_H
#define TWEET_H
#include "tweetpost.h"


class Tweet
{
private:
    static int id_cnt;
    int tweetID;
    std::vector<TweetPost*> myPosts;
    std::string tweetText;

public:
    Tweet();
    void setID(int newID);
    void addPost(TweetPost* newPost);
    void deletePost(TweetPost* oldPost);

    std::vector<TweetPost*> getMyPosts();

    int getTweetID();
};

#endif // TWEET_H
