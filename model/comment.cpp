#include "comment.h"

int Comment::id_cnt = 0;

Comment::Comment()
{
    id = id_cnt;
    id_cnt ++;

}

int Comment::getID(){ return id;}

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
