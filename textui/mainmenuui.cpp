#include "mainmenuui.h"

MainMenuUI::MainMenuUI()
{

}

void MainMenuUI::displayScreen() {
    // move(row, col);
    // mvprintw(row, col, string);
    // getmaxyx(screen, rowVar, colVar);

    mvprintw(4, (this->getCols()/2)-7, "ROCKET RAPPORT");
    mvprintw(8, 28, "Messaging");
    mvprintw(9, 28, "My Profile");
    mvprintw(10, 28, "My Blog");
    mvprintw(11, 28, "My Tweets");
    mvprintw(12, 28, "My Scrapbook");
    mvprintw(13, 28, "Logout");
    mvprintw(14, 28, "Exit");

    mvprintw(this->getRows()-3, this->getCols()-26, "Enter -      Select Option");
    mvprintw(this->getRows()-2, this->getCols()-26, "Up    -   Navigate Up Menu");
    mvprintw(this->getRows()-1, this->getCols()-26, "Down  - Navigate Down Menu");

    mvprintw(this->getRows()-1, 0, "@Average Joe's, Inc.");

    refresh();
    getch();
}

void MainMenuUI::runScreen() {
    noecho();

    mvprintw(8, 27, ">");
    refresh();

    getch();
}
