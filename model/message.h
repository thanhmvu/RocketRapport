#ifndef MESSAGE_H
#define MESSAGE_H
#include <stdio.h>
#include <string>
#include <qdatetime.h>

class Message
{
private:
    static int id_cnt;
    int messID;
    QString text;
    QDateTime sentTime;
public:
    Message();
    Message(int newID, QDateTime time, QString content);

    //Set methods
    void setText(QString insert);
    void setDateTime(QDateTime timeSent);

    //get methods
    QString getText();
    QDateTime getTimeSent();
    int getID();

};

#endif // MESSAGE_H
