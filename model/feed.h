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
    QString feedText;

public:
    Feed();
    ~Feed();

    void displayFeed();
    void addPost(TweetPost* newPost);
    void removePost(TweetPost* oldPost);

    std::vector<TweetPost*> getFeedPosts();
    QString getFeedText();
    void setFeedText(QString text);

    int getFeedID();

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // FEED_H
