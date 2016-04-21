#ifndef MAINMENUUI_H
#define MAINMENUUI_H
#include "screenui.h"

class MainMenuUI : public ScreenUI
{
public:
    MainMenuUI(System* mainSystem);

    void displayScreen();
    void runScreen();
};

#endif // MAINMENUUI_H
