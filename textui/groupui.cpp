#include "groupui.h"

GroupUI::GroupUI(System* mainSystem)
{
    this->setSystem(mainSystem);
    this->setMenuIndex(0);
    this->setAccountIndex(0);
    this->scrollIndex = 0;
}

void GroupUI::displayScreen() {
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(0, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(2, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(this->getRows()-2, i, "-");
    }
    mvprintw(1, (this->getCols()/2)-3, "Groups");
    mvprintw(this->getRows()-3, (this->getCols()/2)-4, "Main Menu");
    mvprintw(this->getRows()-1, 5, " Up, Down - Navigate List;                    Backspace - View Group Feed");

    int j = 5;
    for (int i = 0; i < this->getSystem()->getGroups().size(); i++) {
        if (j < this->getRows()-5) {
            std::string uName = this->getSystem()->getGroups()[i]->getGroupName().toStdString();
            ss << uName;
            move(j, (this->getCols()/2)-10);
            addnstr(ss.str().c_str(), (this->getCols()-(this->getCols()/2)-10));
            ss.str("");
            j++;
        }
    }

    refresh();
}


void GroupUI::runScreen() {
    int curY = 5, curX = (this->getCols()/2)-10;
    int mmY = this->getRows()-3, mmX = (this->getCols()/2)-5;
    mvprintw(5+(this->getAccountIndex()), (this->getCols()/2)-11, ">");
    int keyPress;
    while (this->getChangeScreens() == false) {
        getyx(stdscr, curY, curX);
        keyPress = getch();
        switch(keyPress) {
        case KEY_UP: // Moves up list
            move(mmY, mmX);
            printw(" ");
            refresh();
            move(curY, curX);
            if (this->getMenuIndex() > 0) {
                this->setMenuIndex(this->getMenuIndex()-1);
                if (this->getAccountIndex() > 0) {
                    mvprintw(5+(this->getAccountIndex()), (this->getCols()/2)-11, " ");
                    this->setAccountIndex(this->getAccountIndex()-1);
                    mvprintw(5+(this->getAccountIndex()), (this->getCols()/2)-11, ">");
                }
                // 25 blank spaces
                for (int i = 5; i < this->getRows()-6; i++) {
                    mvprintw(i, (this->getCols()/2)-10, "                         ");
                }
                int j = 5;
                for (int i = 0; i < this->getSystem()->getGroups().size(); i++) {
                    if (j < this->getRows()-6 && i >= (this->getMenuIndex() - this->getAccountIndex())) {
                        std::string uName = this->getSystem()->getGroups()[i]->getGroupName().toStdString();
                        ss << uName;
                        move(j, (this->getCols()/2)-10);
                        addnstr(ss.str().c_str(), (this->getCols()-(this->getCols()/2)-10));
                        ss.str("");
                        j++;
                    }
                }
            }
            break;
        case KEY_DOWN: // Moves down list
            move(mmY, mmX);
            printw(" ");
            refresh();
            move(curY, curX);
            if (this->getMenuIndex() < this->getSystem()->getGroups().size()-1) {
                this->setMenuIndex(this->getMenuIndex()+1);
                if (this->getAccountIndex() < this->getSystem()->getGroups().size()-1) {
                    if (this->getAccountIndex() < (this->getRows()-6)-5 ) {
                        mvprintw(5+(this->getAccountIndex()), (this->getCols()/2)-11, " ");
                        this->setAccountIndex(this->getAccountIndex()+1);
                        mvprintw(5+(this->getAccountIndex()), (this->getCols()/2)-11, ">");
                    }
                }
                // 25 blank spaces
                for (int i = 5; i < this->getRows()-5; i++) {
                    mvprintw(i, (this->getCols()/2)-10, "                         ");
                }
                int j = 5;
                for (int i = 0; i < this->getSystem()->getGroups().size(); i++) {
                    if (j < this->getRows()-5 && i >= (this->getMenuIndex() - this->getAccountIndex())) {
                        std::string uName = this->getSystem()->getGroups()[i]->getGroupName().toStdString();
                        ss << uName;
                        move(j, (this->getCols()/2)-10);
                        addnstr(ss.str().c_str(), (this->getCols()-(this->getCols()/2)-10));
                        ss.str("");
                        j++;
                    }
                }
            }
            break;
        case KEY_BACKSPACE: // Selects a group
            move(mmY, mmX);
            printw(" ");
            refresh();
            move(curY, curX);
            if (curY != (this->getRows()-3)) {
//                int k = 0;
//                for(const auto &acc: this->getSystem()->getAllAccounts()) {
//                    if (k == this->getMenuIndex()) {

//                        // Group selection logic
//                    }
//                    k++;
//                }
            } else {
                this->changeScreens(true);
                this->screenNumber = 1;
            }
            break;
        case KEY_HOME:
            move(curY, curX-1);
            printw(" ");
            move(mmY, mmX);
            printw(">");
            move(mmY, mmX);
            break;
        default:
            move(curY, curX);
            break;
        }
        refresh();
    }

    this->setMenuIndex(0);
    this->changeScreens(false);
    clear();

    refresh();
}


/**
 * @brief Getter that returns the index that the user is at in the account list.
 */
int GroupUI::getAccountIndex() {
    return this->accountIndex;
}


/**
 * @brief Sets the account index.
 */
void GroupUI::setAccountIndex(int number) {
    this->accountIndex = number;
}
