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
    std::string text;
    std::string receiver;
    QDateTime sentTime;
public:
    Message();
    void setText(std::string insert);
    void setReceiver(std::string insert);
    void setDateTime(QDateTime timeSent);
};

#endif // MESSAGE_H
