#include "chatui.h"

ChatUI::ChatUI()
{

}

void ChatUI::displayScreen() {
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(0, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(2, i, "-");
    }
    for (int i = 3; i < this->getRows(); i++) {
        mvprintw(i, (this->getCols()/2)-12, "|");
    }
    for (int i = 3; i < this->getRows(); i++) {
        mvprintw(i, (this->getCols()/2)-11, "|");
    }
    for (int i = 0; i < (this->getCols()/2)-12; i++) {
        mvprintw(this->getRows()-4, i, "-");
    }
    for (int i = 0; i < (this->getCols()/2)-12; i++) {
        mvprintw(this->getRows()-1, i, "-");
    }
    for (int i = (this->getCols()/2)-10; i < this->getCols(); i++) {
        mvprintw(this->getRows()-4, i, "-");
    }
    for (int i = (this->getCols()/2)-10; i < this->getCols(); i++) {
        mvprintw(this->getRows()-1, i, "-");
    }
    mvprintw(1, (this->getCols()/2)-12, "ROCKET RAPPORT MESSAGING");
    mvprintw(this->getRows()-3, 2, "My Profile");
    mvprintw(this->getRows()-2, 2, "Main Menu");
    mvprintw(this->getRows()-3, this->getCols()-14, "|");
    mvprintw(this->getRows()-2, this->getCols()-14, "|");
    mvprintw(this->getRows()-3, this->getCols()-12, "Press Home");
    mvprintw(this->getRows()-2, this->getCols()-11, "to Send");
    mvprintw(3, ((((this->getCols()/2)-12))/2)-2, "Users");
    mvprintw(5, 6, "Backspace to Chat");
    mvprintw(6, 5, "Home to View Profile");
    for (int i = 8; i < this->getRows()-4; i++) {
        move(i, 2);
        addnstr("Test Username", ((this->getCols()/2)-12)-3);
    }
    refresh();
}

void ChatUI::runScreen() {
    refresh();
    getch();
}
