#include "tweetpost.h"

int TweetPost::id_cnt = 0;

TweetPost::TweetPost()
{
    id = id_cnt;
    id_cnt ++;
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
