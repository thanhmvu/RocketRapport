#include "profileui.h"

ProfileUI::ProfileUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void ProfileUI::displayScreen() {
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(0, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(2, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(this->getRows()-2, i, "-");
    }
    ss << this->getSystem()->getCurrentUser()->getProfileUsername();
    int tempsize = this->getSystem()->getCurrentUser()->getProfileUsername().size();
    tempsize += 10;
    tempsize /= 2;
    ss << "'s Profile";
    mvprintw(1, (this->getCols()/2)-tempsize, ss.str().c_str());
    mvprintw(4, 1, "First Name:");
    mvprintw(6, 1, "Last Name:");
    mvprintw(8, 1, "Gender:");
    mvprintw(10, 1, "Home Address:");
    mvprintw(12, 1, "Most Recent Employer:");
    mvprintw(14, 1, "Age");
    mvprintw(16, 1, "Phone Number:");
    mvprintw(18, 1, "About Yourself:");
    mvprintw(21, (this->getCols()/2)-4, "Main Menu");
    mvprintw(this->getRows()-1, 8, "Up, Down - Navigate Fields;           Backspace - Select/Edit");

    refresh();
}

void ProfileUI::runScreen() {
    int fny = 4, fnx = 13;
    int lny = 6, lnx = 12;
    int gy = 8, gx = 9;
    int hay = 10, hax = 15;
    int mrey = 12, mrex = 23;
    int ay = 14, ax = 5;
    int pny = 16, pnx = 15;
    int ayy = 18, ayx = 17;
    int mmy = 21, mmx = (this->getCols()/2)-5;
    int rowIndex = 0;
    int curY = 4;
    int curX = 13;
    std::stringstream fnss;
    std::stringstream lnss;
    std::stringstream gss;
    std::stringstream hass;
    std::stringstream mress;
    std::stringstream ass;
    std::stringstream pnss;
    std::stringstream ayss;

    curs_set(1);
    move(fny, fnx);
    refresh();

    int keyPress;
    while(this->getChangeScreens() == false) {
        getyx(stdscr, curY, curX);
        keyPress = getch();
    }

    this->getSystem()->getCurrentUser()->setProfileUsername(this->getSystem()->getCurrentUser()->getUsername().toStdString());
    this->changeScreens(false);
    clear();
    refresh();
}
