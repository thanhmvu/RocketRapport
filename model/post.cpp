#include "post.h"

int Post::id_cnt = 0;

Post::Post()
{
    id = id_cnt;
    id_cnt ++;

}

int Post::getID(){ return id;}

QString Post::getText(){
    return text;
}

QDateTime Post::getTimePosted(){
    return timePosted;
}

bool Post::setText(QString new_text){
    text = new_text;
    return true;
}

bool Post::setTimePosted(QDateTime new_time){
    this->timePosted = new_time;
    return true;
}
