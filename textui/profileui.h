#ifndef PROFILEUI_H
#define PROFILEUI_H
#include <sstream>
#include "screenui.h"

class ProfileUI : public ScreenUI
{
public:
    ProfileUI(System* mainSystem);

    std::stringstream ss;

    void displayScreen();
    void runScreen();
};

#endif // PROFILEUI_H
