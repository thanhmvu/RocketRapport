#ifndef COMMENT_H
#define COMMENT_H
#include <string>
#include <iostream>
#include <ctime>


class Comment
{
private:
    static int id_cnt;
    int id;
    std::string text;
    time_t time;

public:
    Comment();
    std::string getText();
    time_t getTime();
    int getID();

    bool setText(std::string new_text);
    bool setTime(time_t new_time);
};

#endif // COMMENT_H
