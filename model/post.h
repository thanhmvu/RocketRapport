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

    // for debugging purpose
    static int getIdCnt(){ return id_cnt; };
};

#endif // POST_H
