#ifndef POST_H
#define POST_H
#include <iostream>
#include <QString>
#include <QDateTime>

class Post
{
private:
    static int id_cnt;

protected:
    int id;
    QString text;
    QDateTime timePosted;

public:
    Post();
    QString getText();
    QDateTime getTimePosted();
    int getID();

    bool setText(QString new_text);
    bool setTimePosted(QDateTime new_time);
};

#endif // POST_H
