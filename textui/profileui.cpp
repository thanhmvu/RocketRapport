#include "profileui.h"

ProfileUI::ProfileUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void ProfileUI::displayScreen() {
    mvprintw(1, 1, "On Profile Screen");
    refresh();
}

void ProfileUI::runScreen() {


    this->changeScreens(false);
    clear();
    refresh();
}
