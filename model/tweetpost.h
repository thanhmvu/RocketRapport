#ifndef TWEETPOST_H
#define TWEETPOST_H
#include "post.h"
#include "comment.h"
#include <vector>

class TweetPost: public Post
{
private:
    static int id_cnt;
    int id;
    std::vector<Comment> comments;
    int findComment(int cmt_id);
public:
    TweetPost();
    int getID();
    std::vector<Comment> getComments();
    bool addComment(Comment cmt);
    bool deleteComment(int id);
};

#endif // TWEETPOST_H
