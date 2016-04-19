#include "mainmenuui.h"

MainMenuUI::MainMenuUI()
{

}

void MainMenuUI::displayScreen() {
    // move(row, col);
    // mvprintw(row, col, string);
    // getmaxyx(screen, rowVar, colVar);

    mvprintw(1, (this->getCols()/2)-7, "ROCKET RAPPORT");
    refresh();
    getch();
    getch();
}

void MainMenuUI::runScreen() {
    noecho();

}
