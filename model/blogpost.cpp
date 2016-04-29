#include "blogpost.h"

int BlogPost::id_cnt = 0;

//BlogPost::BlogPost()
//{
//    id = id_cnt;
//    id_cnt ++;
//}

/**
 * @brief BlogPost::BlogPost Standard constructor used for creating a new BlogPost object
 * @param BlogID ID of the blog this post belongs to
 * @param t Time that this post was posted on
 * @param content Text content to be attached to this blog post
 */
BlogPost::BlogPost(int BlogID, QDateTime t, QString content){
    id = id_cnt;
    id_cnt ++;

    blogID = BlogID;
    timePosted = t;
    text = content;
}

/**
 * @brief BlogPost::BlogPost Constructor for a blog post retrieved from the database
 * @param newID ID for the blog post retrieved from the database
 * @param BlogID Blog ID that this blog post belongs to retrieved from the database
 * @param t Time that this post was posed on - retrieved from the database
 * @param content Text posted in the given blog post
 */
BlogPost::BlogPost(int newID, int BlogID, QDateTime t, QString content){
    id = newID;
    // update id_cnt if needed
    if(newID >= id_cnt){
        id_cnt = newID + 1;
    }

    blogID = BlogID;
    timePosted = t;
    text = content;
}

/**
 * @brief BlogPost::getID Getter method for the Blog Post's ID
 */
int BlogPost::getID(){ return id; }

//void BlogPost::setID(int newID){
//    id = newID;

//    // update id_cnt if needed
//    if(newID >= id_cnt){
//        id_cnt = newID + 1;
//    }
//}

/**
 * @brief BlogPost::getBlogID Getter methos used to retrieve the ID of the blog this blog post belongs to.
 */
int BlogPost::getBlogID(){ return blogID; }

/**
 * @brief BlogPost::setBlogID Change the ID of the blog that this blog post belongs to. Using this method changes the blog that this post belongs to
 * @param newID
 */
void BlogPost::setBlogID(int newID){
    blogID = newID;
}

/**
 * @brief BlogPost::setText Set the text that is included in this blog post
 * @param new_text New text that we want to store in this blog post.
 */
void BlogPost::setText(QString new_text){
    text = new_text;
}

/**
 * @brief BlogPost::setTimePosted Set the date that this blog post was posted on
 * @param new_time
 */
void BlogPost::setTimePosted(QDateTime new_time){
    timePosted = new_time;
}

/**
 * @brief BlogPost::getText Getter method that returns the text included in this blog post
 */
QString BlogPost::getText(){
    return text;
}

/**
 * @brief BlogPost::getTimePosted Getter method for the time this blog post was added to the user's blog
 */
QDateTime BlogPost::getTimePosted(){
    return timePosted;
}

//We've cut out commenting functionality for now.
//bool BlogPost::addComment(Comment cmt){
//    comments.push_back(cmt);
//    return true;
//}

//bool BlogPost::deleteComment(int cmt_id){
//    int cmt_index = findComment(cmt_id);
//    if(cmt_index != -1){
//        comments.erase(comments.begin() + cmt_index);
//        return true;
//    }else{
//        std::cout << "Comment not found!" <<std::endl;
//        return false;
//    }
//}

//int BlogPost::findComment(int cmt_id){
//    for(int i = 0; i< comments.size(); i++){
//        if(comments[i].getID() == cmt_id){
//            return i;
//        }
//    }
//    return -1;
//}
