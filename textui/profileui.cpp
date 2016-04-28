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
    ss.str("");
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
        switch(keyPress) {
        case KEY_UP: // Move up options
            switch(rowIndex) {
            case 0:
                curs_set(0);
                move(mmy, mmx);
                printw(">");
                move(mmy, mmx);
                rowIndex = 8;
                break;
            case 1:
                move(fny, fnx);
                rowIndex = 0;
                break;
            case 2:
                move(lny, lnx);
                rowIndex = 1;
                break;
            case 3:
                move(gy, gx);
                rowIndex = 2;
                break;
            case 4:
                move(hay, hax);
                rowIndex = 3;
                break;
            case 5:
                move(mrey, mrex);
                rowIndex = 4;
                break;
            case 6:
                move(ay, ax);
                rowIndex = 5;
                break;
            case 7:
                move(pny, pnx);
                rowIndex = 6;
                break;
            case 8:
                curs_set(1);
                move(mmy, mmx);
                printw(" ");
                move(ayy, ayx);
                rowIndex = 7;
                break;
            }
            break;
        case KEY_DOWN: // Move down options
            switch(rowIndex) {
            case 0:
                move(lny, lnx);
                rowIndex = 1;
                break;
            case 1:
                move(gy, gx);
                rowIndex = 2;
                break;
            case 2:
                move(hay, hax);
                rowIndex = 3;
                break;
            case 3:
                move(mrey, mrex);
                rowIndex = 4;
                break;
            case 4:
                move(ay, ax);
                rowIndex = 5;
                break;
            case 5:
                move(pny, pnx);
                rowIndex = 6;
                break;
            case 6:
                move(ayy, ayx);
                rowIndex = 7;
                break;
            case 7:
                curs_set(0);
                move(mmy, mmx);
                printw(">");
                move(mmy, mmx);
                rowIndex = 8;
                break;
            case 8:
                curs_set(1);
                move(mmy, mmx);
                printw(" ");
                move(fny, fnx);
                rowIndex = 0;
                break;
            }
            break;
        case '\n':
            move(curY, curX);
            break;
        case KEY_BACKSPACE:
            switch(rowIndex) {
            case 0:
                if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                    // User can edit

                }
                break;
            case 1:
                if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                    // User can edit

                }
                break;
            case 2:
                if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                    // User can edit

                }
                break;
            case 3:
                if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                    // User can edit

                }
                break;
            case 4:
                if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                    // User can edit

                }
                break;
            case 5:
                if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                    // User can edit

                }
                break;
            case 6:
                if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                    // User can edit

                }
                break;
            case 7:
                if (this->getSystem()->getCurrentUser()->getUsername().toStdString() == this->getSystem()->getCurrentUser()->getProfileUsername()) {
                    // User can edit

                }
                break;
            case 8:
                this->changeScreens(true);
                this->screenNumber = 1;
                break;
            }
            break;
            break;
        }
    }

    this->getSystem()->getCurrentUser()->setProfileUsername(this->getSystem()->getCurrentUser()->getUsername().toStdString());
    this->changeScreens(false);
    clear();
    refresh();
}
