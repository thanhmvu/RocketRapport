#ifndef BLOG_H
#define BLOG_H
#include "blogpost.h"
#include <stdio.h>
#include "dbmanager.h"
#include <vector>
class DbManager;


class Blog
{
private:
    static int id_cnt;
    int blogID;
    std::vector<BlogPost*> myPosts;
//    QString blogText;
    DbManager *dbm;
public:
    Blog(DbManager *newdbm);
    void setID(int newID);
    void addPost(BlogPost* newPost);
    void storePostToDB(BlogPost* newPost);
    void deletePost(BlogPost* oldPost);
    void deleteAllPosts();

    std::vector<BlogPost*> getMyPosts();
    int getBlogID();
};

#endif // BLOG_H
