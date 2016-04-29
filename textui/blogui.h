#ifndef BLOGUI_H
#define BLOGUI_H
#include <sstream>
#include "screenui.h"

class BlogUI : public ScreenUI
{
public:
    BlogUI(System* mainSystem);

    std::stringstream ss;

    void displayScreen();
    void runScreen();
};

#endif // BLOGUI_H
