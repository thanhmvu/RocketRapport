#include "post.h"

Post::Post()
{   

}

std::string Post::getText(){
    return text;
}

bool Post::setText(std::string new_text){
    text = new_text;
    return true;
}

std::string Post::getDate(){
    return date;
}

bool Post::setDate(std::string new_date){
    date = new_date;
    return true;
}

int Post::getTime(){
    return time;
}

bool Post::setTime(int new_time){
    if(new_time > 0){
        time = new_time;
        return true;
    }else{
        std::cout << "Time can't be negative" << std::endl;
        return false;
    }
}
