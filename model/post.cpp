#include "post.h"

int Post::id_cnt = 0;

Post::Post()
{
    id = id_cnt;
    id_cnt ++;

}

int Post::getID(){ return id;}

std::string Post::getText(){
    return text;
}

time_t Post::getTime(){
    return time;
}

bool Post::setText(std::string new_text){
    text = new_text;
    return true;
}

bool Post::setTime(time_t new_time){
    time = new_time;
    return true;
}
