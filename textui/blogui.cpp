#include "blogui.h"

BlogUI::BlogUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void BlogUI::displayScreen() {
    mvprintw(1, 1, "On Blog Screen");
    refresh();
}

void BlogUI::runScreen() {
    mvprintw(2, 1, "In Run Screen");
    refresh();
    getch();
}
