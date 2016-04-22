#include "chatui.h"

ChatUI::ChatUI(System* mainSystem)
{
    this->setSystem(mainSystem);
    this->setMenuIndex(0);
    this->setAccountIndex(0);
    this->setMessageIndex(0);
    this->setMenuNumber(0);
    this->setUserIndex(0);
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
    mvprintw(1, (this->getCols()-20), "End - Switch Section");
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

    mvprintw(8+(this->getAccountIndex()), 1, ">");
    refresh();

    int keyPress;
    while (this->getChangeScreens() == false) {
        switch(this->getMenuNumber()) {
        case 0: // Account List
            while (this->getMenuNumber() == 0) {
                mvprintw(3, this->getCols()/2-14, "!");
                keyPress = getch();
                switch(keyPress) {
                case KEY_UP: // Moves up list
                    if (this->getUserIndex() > 0) {
                        this->setUserIndex(this->getUserIndex()-1);
                        if (this->getAccountIndex() > 0) {
                            mvprintw(8+(this->getAccountIndex()), 1, " ");
                            this->setAccountIndex(this->getAccountIndex()-1);
                            mvprintw(8+(this->getAccountIndex()), 1, ">");
                        }
                        // 25 blank spaces
                        for (int i = 8; i < this->getRows()-5; i++) {
                            mvprintw(i, 2, "                         ");
                        }
                        int j = 8;
                        int k = 0;
                        for(const auto &acc: this->getSystem()->getAllAccounts()) {
                            if (j < this->getRows()-5 && k >= (this->getUserIndex() - this->getAccountIndex())) {
                                std::string uName = acc.first;
                                ss << uName;
                                move(j, 2);
                                addnstr(ss.str().c_str(), ((this->getCols()/2)-12)-3);
                                ss.str("");
                                j++;
                            }
                            k++;
                        }
                    }
                    break;
                case KEY_DOWN: // Moves down list
                    if (this->getUserIndex() < this->getSystem()->getAllAccounts().size()) {
                        this->setUserIndex(this->getUserIndex()+1);
                        if (this->getAccountIndex() < this->getSystem()->getAllAccounts().size()-1) {
                            if (this->getAccountIndex() < (this->getRows()-5)-8 ) {
                                mvprintw(8+(this->getAccountIndex()), 1, " ");
                                this->setAccountIndex(this->getAccountIndex()+1);
                                mvprintw(8+(this->getAccountIndex()), 1, ">");
                            }
                        }
                        // 25 blank spaces
                        for (int i = 8; i < this->getRows()-5; i++) {
                            mvprintw(i, 2, "                         ");
                        }
                        int j = 8;
                        int k = 0;
                        for(const auto &acc: this->getSystem()->getAllAccounts()) {
                            if (j < this->getRows()-5 && k >= (this->getUserIndex() - this->getAccountIndex())) {
                                std::string uName = acc.first;
                                ss << uName;
                                move(j, 2);
                                addnstr(ss.str().c_str(), ((this->getCols()/2)-12)-3);
                                ss.str("");
                                j++;
                            }
                            k++;
                        }
                    }
                    break;
                case KEY_BACKSPACE: // Selects a user
                    if (true) {
                        int k = 0;
                        for(const auto &acc: this->getSystem()->getAllAccounts()) {
                            if (k == this->getUserIndex()) {



                                // ASSIGN CHAT USER



                                // TESTING PURPOSES:
                                testUName = acc.first;

                                this->setMenuNumber(1);
                            }
                            k++;
                        }
                    }
                    break;
                case KEY_END: // Switches section of screen.
                    this->setMenuNumber(1);
                    break;
                case KEY_HOME: // Views that user's profile
                    if (true) {
                        int k = 0;
                        for(const auto &acc: this->getSystem()->getAllAccounts()) {
                            if (k == this->getUserIndex()) {



                                // ASSIGN PROFILE TO SWITCH TO



                                this->screenNumber = 3;
                                this->changeScreens(true);
                                this->setMenuNumber(1);
                            }
                            k++;
                        }
                    }
                    break;
                }
            }
            mvprintw(3, this->getCols()/2-14, " ");
            break;
        case 1: // Chat History
            while (this->getMenuNumber() == 1) {
                mvprintw(3, this->getCols()-2, "!");
                mvprintw(3, (this->getCols()/2)-10, "                                                ");
                ss << testUName;
                mvprintw(3, ((this->getCols()/2)-11) + ((this->getCols()-((this->getCols()/2)-11))/2) - (testUName.size()/2), ss.str().c_str());
                ss.str("");
                keyPress = getch();
                switch(keyPress) {
                case KEY_END:
                    this->setMenuNumber(2);
                    break;

                }
            }
            mvprintw(3, this->getCols()-2, " ");
            break;
        case 2: // Type Message
            while (this->getMenuNumber() == 2) {
                mvprintw(this->getRows()-2, this->getCols()-2, "!");
                keyPress = getch();
                switch(keyPress) {
                case KEY_END:
                    this->setMenuNumber(3);
                    break;
                }
            }
            mvprintw(this->getRows()-2, this->getCols()-2, " ");
            break;
        case 3: // Menu
            while (this->getMenuNumber() == 3) {
                mvprintw(this->getRows()-3, this->getCols()/2-14, "!");
                keyPress = getch();
                switch(keyPress) {
                case KEY_END:
                    this->setMenuNumber(0);
                    break;
                }
            }
            mvprintw(this->getRows()-3, this->getCols()/2-14, " ");
            break;
        }
    }

    this->setAccountIndex(0);
    this->setMessageIndex(0);
    this->setMenuNumber(0);
    this->setUserIndex(0);
    this->changeScreens(false);
    clear();

    refresh();
}


/**
 * @brief Getter that returns the section of the ChatUI the user is interacting with.
 */
int ChatUI::getMenuNumber() {
    return this->menuNumber;
}


/**
 * @brief Sets the menu number.
 */
void ChatUI::setMenuNumber(int number) {
    this->menuNumber = number;
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


/**
 * @brief Getter that returns the index of the account so the user can select a user to chat with.
 */
int ChatUI::getUserIndex() {
    return this->userIndex;
}


/**
 * @brief Sets the user index.
 */
void ChatUI::setUserIndex(int number) {
    this->userIndex = number;
}
