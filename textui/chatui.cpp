#include "chatui.h"

ChatUI::ChatUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}


/**
 * @brief Displays the screen when the user first loads it before any actions.
 */
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
    int j = 8;
    for(const auto &acc: this->getSystem()->getAllAccounts()) {
        if (j < this->getRows()-4) {
            std::string uName = acc.first;
            ss << uName;
            move(j, 2);
            addnstr(ss.str().c_str(), ((this->getCols()/2)-12)-3);
            ss.str("");
            j++;
        }
    }
    refresh();
}


/**
 * @brief Handles all user input on the screen and will send them to the next screen.
 */
void ChatUI::runScreen() {
    noecho();

    refresh();
    getch();
}


/**
 * @brief Getter that returns the index that the user is at in the account list.
 */
int ChatUI::getAccountIndex() {
    return this->accountIndex;
}


/**
 * @brief Sets the account index.
 */
void ChatUI::setAccountIndex(int number) {
    this->accountIndex = number;
}


/**
 * @brief Getter that returns the index of the messages that the user is viewing.
 */
int ChatUI::getMessageIndex() {
    return this->messageIndex;
}


/**
 * @brief Sets the message index.
 */
void ChatUI::setMessageIndex(int number) {
    this->messageIndex = number;
}
