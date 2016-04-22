#ifndef TWEETPOST_H
#define TWEETPOST_H
#include "post.h"
#include "comment.h"
#include <vector>
#include <QDateTime>
#include <string.h>

class TweetPost: public Post
{
private:
    static int id_cnt;
    int id;

    std::vector<Comment> comments;
    int findComment(int cmt_id);
    QDateTime timePosted;

    std::string text;
public:
    TweetPost();
    int getID();
    std::vector<Comment> getComments();
    bool addComment(Comment cmt);
    bool deleteComment(int id);

    void setTime(QDateTime newTime);
    void setText(std::string newText);
};

#endif // TWEETPOST_H
