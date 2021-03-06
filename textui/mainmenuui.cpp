#include "mainmenuui.h"

MainMenuUI::MainMenuUI(System* mainSystem)
{
    this->setSystem(mainSystem);
    this->setNumOfOptions(8);
}


/**
 * @brief Displays the text of the main menu to the screen.
 */
void MainMenuUI::displayScreen() {
    // move(row, col);
    // mvprintw(row, col, string);
    // getmaxyx(screen, rowVar, colVar);
    std::stringstream sstemp;
    sstemp << this->getSystem()->getCurrentUser()->getUsername().toStdString();

    mvprintw(4, (this->getCols()/2)-7, "ROCKET RAPPORT");
    mvprintw(8, 28, "Messaging");
    mvprintw(9, 28, "My Profile");
    mvprintw(10, 28, "My Blog");
    mvprintw(11, 28, "My Tweets");
    mvprintw(12, 28, "My Scrapbook");
    mvprintw(13, 28, "Groups");
    mvprintw(14, 28, "Logout");
    mvprintw(15, 28, "Exit");

    mvprintw(this->getRows()-3, this->getCols()-26, "BckSp -      Select Option");
    mvprintw(this->getRows()-2, this->getCols()-26, "Up    -   Navigate Up Menu");
    mvprintw(this->getRows()-1, this->getCols()-26, "Down  - Navigate Down Menu");

    mvprintw(this->getRows()-1, 0, "@Average Joe's, Inc.");

    mvprintw(0, 0, "User: ");
    mvprintw(0, 6, sstemp.str().c_str());
    sstemp.str("");

    refresh();
}


/**
 * @brief Gets the user input and handles it accordingly for the main menu's functionality.
 */
void MainMenuUI::runScreen() {
    noecho();

    mvprintw(8+(this->getMenuIndex()), 27, ">");
    refresh();

    int keyPress;
    while (this->getChangeScreens() == false) {
        keyPress = getch();
        switch(keyPress) {
        case KEY_UP:
            if (this->getMenuIndex() > 0) {
                mvprintw(8+(this->getMenuIndex()), 27, " ");
                this->moveUpMenuIndex();
                mvprintw(8+(this->getMenuIndex()), 27, ">");
            }
            break;
        case KEY_DOWN:
            if (this->getMenuIndex() < this->getNumOfOptions()-1) {
                mvprintw(8+(this->getMenuIndex()), 27, " ");
                this->moveDownMenuIndex();
                mvprintw(8+(this->getMenuIndex()), 27, ">");
            }
            break;
        case KEY_BACKSPACE:
            this->changeScreens(true);
            switch(this->getMenuIndex()) {
            case 0: // Messaging
                this->screenNumber = 2;
                break;
            case 1: // Profile
                this->screenNumber = 3;
                break;
            case 2: // Blog
                this->screenNumber = 4;
                break;
            case 3: // Tweets
                this->screenNumber = 5;
                break;
            case 4: // Scrapbook
                this->screenNumber = 6;
                break;
            case 5: // Groups
                this->screenNumber = 7;
                break;
            case 6: // Logout
                this->screenNumber = 0;
                break;
            case 7: // Exit
                this->screenNumber = 8;
                break;
            }
            break;
        }
        refresh();
    }

    this->setMenuIndex(0);
    this->changeScreens(false);
    clear();

    refresh();
}
