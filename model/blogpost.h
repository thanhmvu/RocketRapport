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
    int blogID;
    std::vector<Comment> comments;
    QDateTime timePosted;
    QString text;

    // inherit text and time from Post

public:
//    BlogPost();
    /**
     * @brief BlogPost::BlogPost Standard constructor used for creating a new BlogPost object
     * @param BlogID ID of the blog this post belongs to
     * @param t Time that this post was posted on
     * @param content Text content to be attached to this blog post
     */
    BlogPost(int BlogID, QDateTime t, QString content);
    /**
     * @brief BlogPost::BlogPost Constructor for a blog post retrieved from the database
     * @param newID ID for the blog post retrieved from the database
     * @param BlogID Blog ID that this blog post belongs to retrieved from the database
     * @param t Time that this post was posed on - retrieved from the database
     * @param content Text posted in the given blog post
     */
    BlogPost(int newID, int BlogID, QDateTime t, QString content);

    // Setter methods for each relevant field
    /**
     * @brief BlogPost::setText Set the text that is included in this blog post
     * @param new_text New text that we want to store in this blog post.
     */
    void setText(QString new_text);
    /**
     * @brief BlogPost::setTimePosted Set the date that this blog post was posted on
     */
    void setTimePosted(QDateTime new_time);
//    void setID(int newID);
    /**
     * @brief BlogPost::setBlogID Change the ID of the blog that this blog post belongs to. Using this method changes the blog that this post belongs to
     * @param newID
     */
    void setBlogID(int newID);

    //Getter methods for each field
    /**
     * @brief BlogPost::getID Getter method for the Blog Post's ID
     */
    int getID();
    /**
     * @brief BlogPost::getBlogID Getter methos used to retrieve the ID of the blog this blog post belongs to.
     */
    int getBlogID();
    /**
     * @brief BlogPost::getText Getter method that returns the text included in this blog post
     */
    QString getText();
    /**
     * @brief BlogPost::getTimePosted Getter method for the time this blog post was added to the user's blog
     */
    QDateTime getTimePosted();


//    std::vector<Comment> getComments();

    //Comment methods
//    bool addComment(Comment cmt);
//    bool deleteComment(int id);
//    int findComment(int cmt_id);

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // BLOGPOST_H
