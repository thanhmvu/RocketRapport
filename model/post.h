#ifndef POST_H
#define POST_H
#include <string>
#include <iostream>

class Post
{
private:
    std::string text;
    std::string date;
    int time;
    int postID;

public:
    Post();
    std::string getText();
    bool setText(std::string new_text);
    std::string getDate();
    bool setDate(std::string new_date);
    int getTime();
    bool setTime(int new_time);
};

#endif // POST_H
