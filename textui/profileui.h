#ifndef PROFILEUI_H
#define PROFILEUI_H
#include "screenui.h"

class ProfileUI : public ScreenUI
{
public:
    ProfileUI(System* mainSystem);

    void displayScreen();
    void runScreen();
};

#endif // PROFILEUI_H
