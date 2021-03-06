#include "message.h"

int Message::id_cnt = 0;

Message::Message()
{
    messID = id_cnt;
    id_cnt++;
}

Message::Message(QDateTime time, QString content)
{
    messID = id_cnt;
    id_cnt++;

    sentTime = time;
    text = content;
}

/**
 * @brief This is a special constructor with given message ID
 * The constructor should only be when reload message from database
 */
Message::Message(int newID, QDateTime time, QString content)
{
    messID = newID;
    // update id_cnt if needed
    if(newID >= id_cnt){
        id_cnt = newID + 1;
    }

    sentTime = time;
    text = content;
}

int Message::getID(){
    return messID;
}

void Message::setDateTime(QDateTime timeSent){
    sentTime = timeSent;
}

void Message::setText(QString insert){
    text = insert;
}

QString Message::getText(){
    return text;
}

QDateTime Message::getTimeSent(){
    return sentTime;
}
