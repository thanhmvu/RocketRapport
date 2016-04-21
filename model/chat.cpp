#include "chat.h"

int Chat::id_cnt = 0;

Chat::Chat()
{
    chatID = id_cnt;
    id_cnt++;
}

int Chat::getID(){
    return chatID;
}
