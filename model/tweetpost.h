#ifndef TWEETPOST_H
#define TWEETPOST_H
#include "post.h"
#include "comment.h"
#include <vector>
#include <QDateTime>
#include <string.h>
#include <qstring.h>

class TweetPost: public Post
{
private:
    static int id_cnt;
    int id;
    int tweetID;
    std::vector<Comment> comments;
    QDateTime timePosted;
    QString text;

    int findComment(int cmt_id);
public:
//    TweetPost();

    TweetPost(int TweetID, QDateTime t, QString content);

    TweetPost(int newID, int TweetID, QDateTime t, QString content);

    std::vector<Comment> getComments();
    bool addComment(Comment cmt);
    bool deleteComment(int id);

    //Set methods
    void setTime(QDateTime newTime);
    void setText(QString newText);

    //Get methods
    int getID();
    int getTweetID();
    QString getText();
    QDateTime getTimePosted();

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; }
};

#endif // TWEETPOST_H
