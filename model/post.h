#ifndef POST_H
#define POST_H
#include <iostream>
#include <ctime>
#include <QString>

class Post
{
private:
    static int id_cnt;
    int id;
    QString text;
    time_t time;

public:
    Post();
    QString getText();
    time_t getTime();
    int getID();

    bool setText(QString new_text);
    bool setTime(time_t new_time);
};

#endif // POST_H
