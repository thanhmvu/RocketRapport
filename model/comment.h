#ifndef COMMENT_H
#define COMMENT_H
#include <QString>
#include <iostream>
#include <ctime>


class Comment
{
private:
    static int id_cnt;
    int id;
    QString text;
    time_t time;

public:
    Comment();
    QString getText();
    time_t getTime();
    int getID();

    bool setText(QString new_text);
    bool setTime(time_t new_time);
};

#endif // COMMENT_H
