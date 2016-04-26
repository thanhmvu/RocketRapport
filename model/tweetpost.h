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

    QString text;
public:
    TweetPost();
    int getID();
    std::vector<Comment> getComments();
    bool addComment(Comment cmt);
    bool deleteComment(int id);

    //Set methods
    void setTime(QDateTime newTime);
    void setText(QString newText);

    //Get methods
    QString getText();
    QDateTime getTimePosted();

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; }
};

#endif // TWEETPOST_H
