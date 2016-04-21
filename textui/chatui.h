#ifndef CHATUI_H
#define CHATUI_H
#include "screenui.h"
#include <sstream>

class ChatUI : public ScreenUI
{

    int accountIndex;
    int messageIndex;
    int menuNumber;

    /*
     * Menu Numbers:
     *
     * 0 - Account List
     * 1 - Chat History
     * 2 - Type Message
     * 3 - Menu
     *
     */


public:
    ChatUI(System* mainSystem);

    std::stringstream ss;

    void displayScreen();
    void runScreen();

    int getMenuNumber();
    void setMenuNumber(int number);
    int getAccountIndex();
    void setAccountIndex(int number);
    int getMessageIndex();
    void setMessageIndex(int number);
};

#endif // CHATUI_H
