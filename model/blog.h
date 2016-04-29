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
    std::vector<BlogPost*> myPosts; // own this

    DbManager *dbm; // does not own this
public:
    Blog(DbManager *newdbm);
    Blog(int BlogID, DbManager *newdbm);
    ~Blog();
    void setID(int newID);
    void addPost(BlogPost* newPost);
    void storePostToDB(BlogPost* newPost);
    void deletePost(BlogPost* oldPost);
    void deleteAllPosts();

    std::vector<BlogPost*> getMyPosts();
    int getBlogID();

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // BLOG_H
