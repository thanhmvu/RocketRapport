#include "scrapbookui.h"

ScrapbookUI::ScrapbookUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void ScrapbookUI::displayScreen() {
    mvprintw(1, 1, "On Scrapbook Screen");
    refresh();
}

void ScrapbookUI::runScreen() {
    mvprintw(2, 1, "In Run Screen");
    refresh();
    getch();
}
