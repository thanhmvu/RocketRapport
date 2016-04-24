#ifndef LOGINUI_H
#define LOGINUI_H
#include <sstream>
#include "screenui.h"

class LoginUI : public ScreenUI
{
public:
    LoginUI(System* mainSystem);

    void displayScreen();
    void runScreen();
};

#endif // LOGINUI_H
