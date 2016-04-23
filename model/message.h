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
    QString receiver;
    QDateTime sentTime;
public:
    Message();

    //Set methods
    void setText(QString insert);
    void setReceiver(QString insert);
    void setDateTime(QDateTime timeSent);

    //get methods
    QString getText();
    QString getReceiver();
    QDateTime getTimeSent();
    int getID();

};

#endif // MESSAGE_H
