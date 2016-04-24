#ifndef BLOG_H
#define BLOG_H
#include "blogpost.h"
#include <stdio.h>


class Blog
{
private:
    static int id_cnt;
    int blogID;
    std::vector<BlogPost*> myPosts;
    std::string blogText;

public:
    Blog();
    void setID(int newID);
    void addPost(BlogPost* newPost);
    void deletePost(BlogPost* oldPost);
    //  NEEDS TO BE IMPLEMENTED
    void concastPosts();

    std::vector<BlogPost*> getMyPosts();

    int getBlogID();
};

#endif // BLOG_H
