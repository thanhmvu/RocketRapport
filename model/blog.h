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
//    QString blogText;
    DbManager *dbm; // does not own this
public:
    /**
     * @brief Blog::Blog Constructor used to create a new blog with a reference to a dbManager object for data storage and retrieval
     * @param newdbm
     */
    Blog(DbManager *newdbm);
    /**
     * @brief Blog::Blog Constructor used when adding blog posts from the database using information in the given DB
     * @param BlogID ID of the new Blog we're creating
     * @param newdbm Pointer to a dbm object used for storing and retrieving information
     */
    Blog(int BlogID, DbManager *newdbm);
    /**
     * @brief Blog::~Blog Destructor used to clear each blog post from the vector of blog posts contained in the blog
     */
    ~Blog();
    /**
     * @brief Blog::setID Setter used for blog ID.
     */
    void setID(int newID);
    /**
     * @brief Adds a new BlogPost to the Blog's list of posts.
     */
    void addPost(BlogPost* newPost);
    /**
     * @brief Blog::storePostToDB Store a blog post's information to the database
     * @param newPost
     */
    void storePostToDB(BlogPost* newPost);
    /**
     * @brief Removes a BlogPost from the Blog's list of posts.
     */
    void deletePost(BlogPost* oldPost);
    /**
     * @brief Blog::deleteAllPosts Delete all posts found within the Blog.
     */
    void deleteAllPosts();

    /**
     * @brief Getter that returns the list of BlogPosts.
     */
    std::vector<BlogPost*> getMyPosts();
    /**
     * @brief Blog::getBlogID getter used for Blog ID
     */
    int getBlogID();

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // BLOG_H
