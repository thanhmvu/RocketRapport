#ifndef FEED_H
#define FEED_H
#include <vector>
#include "tweetpost.h"


class Feed
{
private:
    static int id_cnt;
    int feedID;
    std::vector<TweetPost*> feedPosts;
    std::string feedText;

public:
    Feed();

    void displayFeed();
    void addPost(TweetPost* newPost);
    void removePost(TweetPost* oldPost);

    std::vector<TweetPost*> getFeedPosts();
    std::string getFeedText();
    void setFeedText(std::string text);
};

#endif // FEED_H
