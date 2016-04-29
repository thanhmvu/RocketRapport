#include "blogui.h"

BlogUI::BlogUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void BlogUI::displayScreen() {
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(0, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(2, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw((this->getRows()/2)-1, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(this->getRows()-2, i, "-");
    }
    ss << this->getSystem()->getCurrentUser()->getBlogTweetUsername();
    int tempsize = this->getSystem()->getCurrentUser()->getBlogTweetUsername().size();
    tempsize += 7;
    tempsize /= 2;
    ss << "'s Blog";
    mvprintw(1, (this->getCols()/2)-tempsize, ss.str().c_str());
    ss.str("");
    mvprintw(4, 1, "New Post:");
    mvprintw((this->getRows()/2), 1, "Former Posts:");
    mvprintw(this->getRows()-3, (this->getCols()/2)-4, "Main Menu");
    mvprintw(this->getRows()-1, 1, "Up, Down - Navigate Sections;  Left, Right - Scroll Posts;  Home - Post/Select");

    refresh();
}

void BlogUI::runScreen() {
    int npY = 5, npX = 1;
    int fpY = (this->getRows()/2)+1, fpX = 1;
    int mmY = this->getRows()-3, mmX = (this->getCols()/2)-5;
    std::stringstream npss;
    int rowIndex = 0;
    int curY = 5, curX = 1;

    curs_set(1);
    move(npY, npX);
    refresh();

    int keyPress;
    while(this->getChangeScreens() == false) {
        getyx(stdscr, curY, curX);
        keyPress = getch();
        switch(keyPress) {
        case KEY_UP: // Switch screen sections
            switch(rowIndex) {
            case 0:
                curs_set(0);
                move(mmY, mmX);
                printw(">");
                move(mmY, mmX);
                rowIndex = 2;
                break;
            case 1:
                move(npY, npX);
                rowIndex = 0;
                break;
            case 2:
                curs_set(1);
                move(mmY, mmX);
                printw(" ");
                move(fpY, fpX);
                rowIndex = 1;
                break;
            }
            break;
        case KEY_DOWN: // Switch screen sections
            switch(rowIndex) {
            case 0:
                move(fpY, fpX);
                rowIndex = 1;
                break;
            case 1:
                curs_set(0);
                move(mmY, mmX);
                printw(">");
                move(mmY, mmX);
                rowIndex = 2;
                break;
            case 2:
                curs_set(1);
                move(mmY, mmX);
                printw(" ");
                move(npY, npX);
                rowIndex = 0;
                break;
            }
            break;
        case KEY_LEFT: // Scroll former posts
            break;
        case KEY_RIGHT: // Scroll former posts
            break;
        case KEY_HOME: // Post/Select option
            break;
        case KEY_BACKSPACE: // Backspace when typing
            break;
        case '\n' :
            move(curY, curX);
            break;
        default: // Typing characters for a post
            break;
        }
    }


    this->getSystem()->getCurrentUser()->setBlogTweetUsername(this->getSystem()->getCurrentUser()->getUsername().toStdString());
    this->changeScreens(false);
    clear();
    refresh();
}
