#ifndef BLOGPOST_H
#define BLOGPOST_H
#include "post.h"
#include "comment.h"
#include <vector>
#include <string>
#include <qstring.h>
#include <qdatetime.h>

class BlogPost: public Post
{
private:
    static int id_cnt;
    int id;
    std::vector<Comment> comments;
    QDateTime timePosted;
    QString text;

    // inherit text and time from Post

public:
    BlogPost();

    // Setter methods for each relevant field
    void setText(QString new_text);
    void setTimePosted(QDateTime new_time);
    void setID(int newID);

    //Getter methods for each field
    int getID();
    QString getText();
    QDateTime getTimePosted();


    std::vector<Comment> getComments();

    //Comment methods
    bool addComment(Comment cmt);
    bool deleteComment(int id);
    int findComment(int cmt_id);
};

#endif // BLOGPOST_H
