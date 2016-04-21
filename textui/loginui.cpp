#include "loginui.h"

LoginUI::LoginUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void LoginUI::displayScreen() {
    mvprintw(1, 1, "On Login Screen");
    refresh();
}

void LoginUI::runScreen() {
    mvprintw(2, 1, "In Run Screen");
    refresh();
    getch();
}
