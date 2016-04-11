#ifndef TWEET_H
#define TWEET_H
#include "tweetpost.h"


class Tweet
{

    std::vector<TweetPost*> myPosts;
    std::string tweetText;

public:
    Tweet();

    void addPost(TweetPost* newPost);
    void deletePost(TweetPost* oldPost);
    //  NEEDS TO BE IMPLEMENTED
    void concastPosts();

    std::vector<TweetPost*> getMyPosts();
};

#endif // TWEET_H
