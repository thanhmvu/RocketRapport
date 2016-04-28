#include "blogpost.h"

int BlogPost::id_cnt = 0;

//BlogPost::BlogPost()
//{
//    id = id_cnt;
//    id_cnt ++;
//}

/**
 * @brief BlogPost::BlogPost Standard constructor used for creating a new BlogPost object
 * @param BlogID
 * @param t
 * @param content
 */
BlogPost::BlogPost(int BlogID, QDateTime t, QString content){
    id = id_cnt;
    id_cnt ++;

    blogID = BlogID;
    timePosted = t;
    text = content;
}

/**
 * @brief constructor that is used explicitly for loading from database
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

int BlogPost::getID(){ return id; }

//void BlogPost::setID(int newID){
//    id = newID;

//    // update id_cnt if needed
//    if(newID >= id_cnt){
//        id_cnt = newID + 1;
//    }
//}

int BlogPost::getBlogID(){ return blogID; }

void BlogPost::setBlogID(int newID){
    blogID = newID;
}

void BlogPost::setText(QString new_text){
    text = new_text;
}

void BlogPost::setTimePosted(QDateTime new_time){
    timePosted = new_time;
}

QString BlogPost::getText(){
    return text;
}

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
