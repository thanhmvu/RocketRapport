#ifndef SCRAPBOOKUI_H
#define SCRAPBOOKUI_H
#include "screenui.h"

class ScrapbookUI : public ScreenUI
{
public:
    ScrapbookUI(System* mainSystem);

    void displayScreen();
    void runScreen();
};

#endif // SCRAPBOOKUI_H
