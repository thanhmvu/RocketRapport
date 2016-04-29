#include "tweetpost.h"

int TweetPost::id_cnt = 0;

//TweetPost::TweetPost()
//{
//    id = id_cnt;
//    id_cnt ++;
//}

/**
 * @brief TweetPost::TweetPost Standard constructor used for creating a new TweetPost object
 * @param TweetID ID of the Tweet this post belongs to
 * @param t Time that this post was posted on
 * @param content Text content to be attached to this Tweet post
 */
TweetPost::TweetPost(int TweetID, QDateTime t, QString content){
    id = id_cnt;
    id_cnt ++;

    tweetID = TweetID;
    timePosted = t;
    text = content;
}

/**
 * @brief TweetPost::TweetPost Constructor for a Tweet post retrieved from the database
 * @param newID ID for the Tweet post retrieved from the database
 * @param TweetID Tweet ID that this Tweet post belongs to retrieved from the database
 * @param t Time that this post was posed on - retrieved from the database
 * @param content Text posted in the given Tweet post
 */
TweetPost::TweetPost(int newID, int TweetID, QDateTime t, QString content){
    id = newID;
    // update id_cnt if needed
    if(newID >= id_cnt){
        id_cnt = newID + 1;
    }

    tweetID = TweetID;
    timePosted = t;
    text = content;
}

int TweetPost::getID(){ return id; }

bool TweetPost::addComment(Comment cmt){
    comments.push_back(cmt);
    return true;
}

bool TweetPost::deleteComment(int cmt_id){
    int cmt_index = findComment(cmt_id);
    if(cmt_index != -1){
        comments.erase(comments.begin() + cmt_index);
        return true;
    }else{
        std::cout << "Comment not found!" <<std::endl;
        return false;
    }
}

int TweetPost::findComment(int cmt_id){
    for(unsigned i = 0; i< comments.size(); i++){
        if(comments[i].getID() == cmt_id){
            return i;
        }
    }
    return -1;
}

void TweetPost::setText(QString newText){
    text = newText;
}

void TweetPost::setTime(QDateTime newTime){
    timePosted = newTime;
}

QString TweetPost::getText(){
    return text;
}

QDateTime TweetPost::getTimePosted(){
    return timePosted;
}

/**
 * @brief TweetPost::getTweetID Getter methos used to retrieve the ID of the Tweet this Tweet post belongs to.
 */
int TweetPost::getTweetID(){ return tweetID; }
