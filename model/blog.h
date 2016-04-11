#ifndef BLOG_H
#define BLOG_H
#include "blogpost.h"


class Blog
{

    std::vector<BlogPost*> myPosts;
    std::string blogText;

public:
    Blog();

    void addPost(BlogPost* newPost);
    void deletePost(BlogPost* oldPost);
    //  NEEDS TO BE IMPLEMENTED
    void concastPosts();

    std::vector<BlogPost*> getMyPosts();
};

#endif // BLOG_H
