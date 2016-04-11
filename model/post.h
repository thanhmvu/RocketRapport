#ifndef POST_H
#define POST_H
#include <string>
#include <iostream>
#include <ctime>

class Post
{
private:
    static int id_cnt;
    int id;
    std::string text;
    time_t time;

public:
    Post();
    std::string getText();
    time_t getTime();
    int getID();

    bool setText(std::string new_text);
    bool setTime(time_t new_time);
};

#endif // POST_H
