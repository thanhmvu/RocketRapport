#ifndef BLOGPOST_H
#define BLOGPOST_H
#include "post.h"
#include "comment.h"
#include <vector>
#include <QDateTime>

class BlogPost: public Post
{
private:
    static int id_cnt;
    int id;
    std::vector<Comment> comments;
    int findComment(int cmt_id);
    QString text;
    QDateTime datePosted;
public:
    BlogPost();
    int getID();
    bool setText(QString new_text);
    QString getText();
    std::vector<Comment> getComments();
    bool addComment(Comment cmt);
    bool deleteComment(int id);
};

#endif // BLOGPOST_H
