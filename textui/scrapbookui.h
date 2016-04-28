#ifndef SCRAPBOOKUI_H
#define SCRAPBOOKUI_H
#include <fstream>
#include "screenui.h"
#include "../model/account.h"

class ScrapbookUI : public ScreenUI
{
public:
    ScrapbookUI(System* mainSystem);

    void displayScreen();
    void runScreen();

    void viewMyScrapbook(std::string path);
};

#endif // SCRAPBOOKUI_H
