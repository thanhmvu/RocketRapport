#include "comment.h"

int Comment::id_cnt = 0;

/**
 * @brief Comment::Comment Constructor for a new comment object
 */
Comment::Comment()
{
    id = id_cnt;
    id_cnt ++;

}

/**
 * @brief Comment::getID getter method for obtaining the ID associated with the given comment
 * @return
 */
int Comment::getID(){ return id;}

/**
 * @brief Comment::getText
 * @return
 */
QString Comment::getText(){
    return text;
}

time_t Comment::getTime(){
    return time;
}

bool Comment::setText(QString new_text){
    text = new_text;
    return true;
}

bool Comment::setTime(time_t new_time){
    time = new_time;
    return true;
}
