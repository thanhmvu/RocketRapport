#include "message.h"

int Message::id_cnt = 0;

Message::Message()
{
    messID = id_cnt;
    id_cnt++;
}
