#ifndef BLOGPOST_H
#define BLOGPOST_H
#include "post.h"
#include "comment.h"
#include <vector>

class BlogPost: public Post
{
private:
    static int id_cnt;
    int id;
    std::vector<Comment> comments;

    // inherit text and time from Post

public:
    BlogPost();
    int getID();

    // inherit getter and setter of text and time from Post

    std::vector<Comment> getComments();
    bool addComment(Comment cmt);
    bool deleteComment(int id);
    int findComment(int cmt_id);
};

#endif // BLOGPOST_H
