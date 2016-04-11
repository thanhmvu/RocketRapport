#include "blogpost.h"

int BlogPost::id_cnt = 0;

BlogPost::BlogPost()
{
    id = id_cnt;
    id_cnt ++;
}

int BlogPost::getID(){ return id; }

bool BlogPost::addComment(Comment cmt){
    comments.push_back(cmt);
    return true;
}

bool BlogPost::deleteComment(int cmt_id){
    int cmt_index = findComment(cmt_id);
    if(cmt_index != -1){
        comments.erase(comments.begin() + cmt_index);
        return true;
    }else{
        std::cout << "Comment not found!" <<std::endl;
        return false;
    }
}

int BlogPost::findComment(int cmt_id){
    for(int i = 0; i< comments.size(); i++){
        if(comments[i].getID() == cmt_id){
            return i;
        }
    }
    return -1;
}
