#ifndef CHAT_H
#define CHAT_H


class Chat
{
private:
    static int id_cnt;
    int chatID;
public:
    Chat();
    int getID();
};

#endif // CHAT_H
