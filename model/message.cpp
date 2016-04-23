#include "message.h"

int Message::id_cnt = 0;

Message::Message()
{
    messID = id_cnt;
    id_cnt++;
}

int Message::getID(){
    return messID;
}

void Message::setDateTime(QDateTime timeSent){
    sentTime = timeSent;
}

void Message::setReceiver(QString insert){
    receiver = insert;
}

void Message::setText(QString insert){
    text = insert;
}

QString Message::getReceiver(){
    return receiver;
}

QString Message::getText(){
    return text;
}

QDateTime Message::getTimeSent(){
    return sentTime;
}
