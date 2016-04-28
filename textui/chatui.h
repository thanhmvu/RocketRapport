#ifndef CHATUI_H
#define CHATUI_H
#include "screenui.h"
#include "../model/chat.h"
#include <sstream>

class ChatUI : public ScreenUI
{

    int accountIndex; // Index for account list section.
    int messageIndex; // Index for message history
    int menuNumber; // Section of the screen the user is on.
    int userIndex; // Keep track of which account they are on.
    // Menu Index   -   Index for the menu section.

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

    std::string talkingWith;
    int indexOfTalking;
    int scrollIndex;

    std::stringstream ss;

    void displayScreen();
    void runScreen();

    void printChatHistory();

    int getMenuNumber();
    void setMenuNumber(int number);
    int getAccountIndex();
    void setAccountIndex(int number);
    int getMessageIndex();
    void setMessageIndex(int number);
    int getUserIndex();
    void setUserIndex(int number);
};

#endif // CHATUI_H
