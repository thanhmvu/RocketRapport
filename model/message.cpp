#include "message.h"

int Message::id_cnt = 0;

Message::Message()
{
    messID = id_cnt;
    id_cnt++;
}

void Message::setDateTime(QDateTime timeSent){
    sentTime = timeSent;
}

void Message::setReceiver(std::__cxx11::string insert){
    receiver = insert;
}

void Message::setText(std::__cxx11::string insert){
    text = insert;
}
