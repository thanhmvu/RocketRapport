#ifndef CHATUI_H
#define CHATUI_H
#include "screenui.h"

class ChatUI : public ScreenUI
{
public:
    ChatUI();

    void displayScreen();
    void runScreen();
};

#endif // CHATUI_H
