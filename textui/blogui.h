#ifndef BLOGUI_H
#define BLOGUI_H
#include "screenui.h"

class BlogUI : public ScreenUI
{
public:
    BlogUI(System* mainSystem);

    void displayScreen();
    void runScreen();
};

#endif // BLOGUI_H
