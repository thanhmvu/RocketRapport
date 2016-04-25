#include "loginui.h"

LoginUI::LoginUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}


/**
 * @brief Displays the text of the login to the screen.
 */
void LoginUI::displayScreen() {
    mvprintw(2, (this->getCols()/2)-6, "Welcome to");
    mvprintw(3, (this->getCols()/2)-8, "ROCKET RAPPORT");
    mvprintw(7, ((this->getCols()/2)/2)-7, "Create Account");
    mvprintw(7, (this->getCols()-((this->getCols()/2)/2))-3, "Login ");
    mvprintw(9, 5, "First Name:");
    mvprintw(11, 5, "Last Name:");
    mvprintw(13, 5, "Username:");
    mvprintw(15, 5, "Password:");
    mvprintw(17, ((this->getCols()/2)/2)-4, "Sign In");
    mvprintw(10, (this->getCols()/2)+5, "Username:");
    mvprintw(13, (this->getCols()/2)+5, "Password:");
    mvprintw(17, (this->getCols()-((this->getCols()/2)/2))-3, "Log In");
    mvprintw(20, (this->getCols()/2)-4, "Exit");
    mvprintw(this->getRows()-1, 4, "Up, Down, Left, Right - Navigate Menu;        Home - Select Option");
    refresh();
}


/**
 * @brief Gets the user input and handles it accordingly for the login's functionality.
 */
void LoginUI::runScreen() {
    int fnY = 9, fnX = 17;
    int lnY = 11, lnX = 16;
    int uY = 13, uX = 15;
    int pY = 15, pX = 15;
    int luY = 10, luX = (this->getCols()/2)+15;
    int lpY = 13, lpX = (this->getCols()/2)+15;
    int siY = 17, siX = ((this->getCols()/2)/2)-5;
    int liY = 17, liX = (this->getCols()-((this->getCols()/2)/2))-4;
    int exitY = 20, exitX = (this->getCols()/2)-5;
    int colIndex = 0;
    int rowIndex = 0;
    int curY = 9;
    int curX = 17;
    std::stringstream fnss;
    std::stringstream lnss;
    std::stringstream uss;
    std::stringstream pss;
    std::stringstream luss;
    std::stringstream lpss;
    std::stringstream sstemp;

    curs_set(1);
    move(fnY, fnX);
    refresh();

    int keyPress;
    while(this->getChangeScreens() == false) {
        getyx(stdscr, curY, curX);
        keyPress = getch();
        mvprintw(19, 7, "                        ");
        mvprintw(20, 14, "          ");
        mvprintw(19, 44, "                                  ");
        mvprintw(20, 44, "                                  ");
        switch(keyPress) {
        case KEY_UP: // Move up options
            switch(colIndex) {
            case 0: // Left Side
                switch(rowIndex) {
                case 0:
                    curs_set(0);
                    move(exitY, exitX);
                    printw(">");
                    move(exitY, exitX);
                    rowIndex = 5;
                    break;
                case 1:
                    move(fnY, fnX);
                    rowIndex = 0;
                    break;
                case 2:
                    move(lnY, lnX);
                    rowIndex = 1;
                    break;
                case 3:
                    move(uY, uX);
                    rowIndex = 2;
                    break;
                case 4:
                    curs_set(1);
                    move(siY, siX);
                    printw(" ");
                    move(pY, pX);
                    rowIndex = 3;
                    break;
                case 5:
                    curs_set(0);
                    move(exitY, exitX);
                    printw(" ");
                    move(siY, siX);
                    printw(">");
                    move(siY, siX);
                    rowIndex = 4;
                    break;
                }
                break;
            case 1: // Right Side
                switch(rowIndex) {
                case 0:
                    curs_set(0);
                    move(exitY, exitX);
                    printw(">");
                    move(exitY, exitX);
                    rowIndex = 5;
                    break;
                case 1:
                    curs_set(0);
                    move(exitY, exitX);
                    printw(">");
                    move(exitY, exitX);
                    rowIndex = 5;
                    break;
                case 2:
                    move(luY, luX);
                    rowIndex = 0;
                    break;
                case 3:
                    move(luY, luX);
                    rowIndex = 0;
                    break;
                case 4:
                    curs_set(1);
                    move(liY, liX);
                    printw(" ");
                    move(lpY, lpX);
                    rowIndex = 2;
                    break;
                case 5:
                    curs_set(0);
                    move(exitY, exitX);
                    printw(" ");
                    move(liY, liX);
                    printw(">");
                    move(liY, liX);
                    rowIndex = 4;
                    break;
                }
                break;
            }
            break;
        case KEY_DOWN: // Move down options
            switch(colIndex) {
            case 0: // Left Side
                switch(rowIndex) {
                case 0:
                    move(lnY, lnX);
                    rowIndex = 1;
                    break;
                case 1:
                    move(uY, uX);
                    rowIndex = 2;
                    break;
                case 2:
                    move(pY, pX);
                    rowIndex = 3;
                    break;
                case 3:
                    curs_set(0);
                    move(siY, siX);
                    printw(">");
                    move(siY, siX);
                    rowIndex = 4;
                    break;
                case 4:
                    move(siY, siX);
                    printw(" ");
                    move(exitY, exitX);
                    printw(">");
                    move(exitY, exitX);
                    rowIndex = 5;
                    break;
                case 5:
                    curs_set(1);
                    move(exitY, exitX);
                    printw(" ");
                    move(fnY, fnX);
                    rowIndex = 0;
                    break;
                }
                break;
            case 1: // Right Side
                switch(rowIndex) {
                case 0:
                    move(lpY, lpX);
                    rowIndex = 2;
                    break;
                case 1:
                    move(lpY, lpX);
                    rowIndex = 2;
                    break;
                case 2:
                    curs_set(0);
                    move(liY, liX);
                    printw(">");
                    move(liY, liX);
                    rowIndex = 4;
                    break;
                case 3:
                    curs_set(0);
                    move(liY, liX);
                    printw(">");
                    move(liY, liX);
                    rowIndex = 4;
                    break;
                case 4:
                    move(liY, liX);
                    printw(" ");
                    move(exitY, exitX);
                    printw(">");
                    move(exitY, exitX);
                    rowIndex = 5;
                    break;
                case 5:
                    curs_set(1);
                    move(exitY, exitX);
                    printw(" ");
                    move(luY, luX);
                    rowIndex = 0;
                    break;
                }
                break;
            }
            break;
        case KEY_LEFT: // Move left options
        case KEY_RIGHT: // Move right options
            switch(colIndex) {
            case 0:
                switch(rowIndex) {
                case 0:
                    move(luY, luX);
                    colIndex = 1;
                    break;
                case 1:
                    move(luY, luX);
                    colIndex = 1;
                    break;
                case 2:
                    move(lpY, lpX);
                    colIndex = 1;
                    break;
                case 3:
                    move(lpY, lpX);
                    colIndex = 1;
                    break;
                case 4:
                    move(siY, siX);
                    printw(" ");
                    curs_set(0);
                    move(liY, liX);
                    printw(">");
                    move(liY, liX);
                    colIndex = 1;
                    break;
                case 5:
                    move(exitY, exitX);
                    printw(" ");
                    curs_set(0);
                    move(exitY, exitX);
                    printw(">");
                    move(exitY, exitX);
                    colIndex = 1;
                    break;
                }
                break;
            case 1:
                switch(rowIndex) {
                case 0:
                    move(fnY, fnX);
                    colIndex = 0;
                    break;
                case 1:
                    move(lnY, lnX);
                    colIndex = 0;
                    break;
                case 2:
                    move(uY, uX);
                    colIndex = 0;
                    break;
                case 3:
                    move(pY, pX);
                    colIndex = 0;
                    break;
                case 4:
                    move(liY, liX);
                    printw(" ");
                    curs_set(0);
                    move(siY, siX);
                    printw(">");
                    move(siY, siX);
                    colIndex = 0;
                    break;
                case 5:
                    move(exitY, exitX);
                    printw(" ");
                    curs_set(0);
                    move(exitY, exitX);
                    printw(">");
                    move(exitY, exitX);
                    colIndex = 0;
                    break;
                }
                break;
            }
            break;
        case '\n': // Return to position if they press enter
            move(curY, curX);
            break;
        case KEY_BACKSPACE: // Deleting text input
            switch(colIndex) {
            case 0:
                switch(rowIndex) {
                case 0:
                    if ((fnX-17) > 0) {
                        fnX--;
                        mvprintw(fnY, fnX, " ");
                        move(fnY, fnX);
                        std::string remove = fnss.str();
                        remove.erase(remove.size()-1, 1);
                        fnss.str("");
                        fnss << remove;
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 1:
                    if ((lnX-16) > 0) {
                        lnX--;
                        mvprintw(lnY, lnX, " ");
                        move(lnY, lnX);
                        std::string remove = lnss.str();
                        remove.erase(remove.size()-1, 1);
                        lnss.str("");
                        lnss << remove;
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 2:
                    if ((uX-15) > 0) {
                        uX--;
                        mvprintw(uY, uX, " ");
                        move(uY, uX);
                        std::string remove = uss.str();
                        remove.erase(remove.size()-1, 1);
                        uss.str("");
                        uss << remove;
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 3:
                    if ((pX-15) > 0) {
                        pX--;
                        mvprintw(pY, pX, " ");
                        move(pY, pX);
                        std::string remove = pss.str();
                        remove.erase(remove.size()-1, 1);
                        pss.str("");
                        pss << remove;
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 4:
                    move(curY, curX);
                    break;
                case 5:
                    move(curY, curX);
                    break;
                }
                break;
            case 1:
                switch(rowIndex) {
                case 0:
                case 1:
                    if ((luX-((this->getCols()/2)+15)) > 0) {
                        luX--;
                        mvprintw(luY, luX, " ");
                        move(luY, luX);
                        std::string remove = luss.str();
                        remove.erase(remove.size()-1, 1);
                        luss.str("");
                        luss << remove;
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 2:
                case 3:
                    if ((lpX-((this->getCols()/2)+15)) > 0) {
                        lpX--;
                        mvprintw(lpY, lpX, " ");
                        move(lpY, lpX);
                        std::string remove = lpss.str();
                        remove.erase(remove.size()-1, 1);
                        lpss.str("");
                        lpss << remove;
                    } else {
                        move(curY, curX);
                    }
                    break;
                case 4:
                    move(curY, curX);
                    break;
                case 5:
                    move(curY, curX);
                    break;
                }
                break;
            }
            break;
        case KEY_HOME: // Select options
            switch(rowIndex) {
            case 4:
                switch(colIndex) {
                case 0: // Create new account
                    if (true) {
                        bool accountCreated = this->getSystem()->createAccount(QString::fromStdString(uss.str()), QString::fromStdString(pss.str()), QString::fromStdString(fnss.str()), QString::fromStdString(lnss.str()));
                        if (accountCreated) {
                            this->screenNumber = 1;
                            this->changeScreens(true);
                        } else {
                            mvprintw(19, 7, "Username already exists.");
                            mvprintw(20, 14, "Try again.");
                            fnX = 17;
                            lnX = 16;
                            uX = 15;
                            pX = 15;
                            luX = (this->getCols()/2)+15;
                            lpX = (this->getCols()/2)+15;
                            fnss.str("");
                            lnss.str("");
                            uss.str("");
                            pss.str("");
                            luss.str("");
                            lpss.str("");
                            for (int i = 0; i < 20; i++) {
                                mvprintw(fnY, (fnX+i), " ");
                                mvprintw(lnY, (lnX+i), " ");
                                mvprintw(uY, (uX+i), " ");
                                mvprintw(pY, (pX+i), " ");
                                mvprintw(luY, (luX+i), " ");
                                mvprintw(lpY, (lpX+i), " ");
                            }
                        }
                    }
                    break;
                case 1: // Log in
                    if (true) {
                        bool accountLoggedIn = this->getSystem()->login(QString::fromStdString(luss.str()), QString::fromStdString(lpss.str()));
                        if (accountLoggedIn) {
                            this->screenNumber = 1;
                            this->changeScreens(true);
                        } else {
                            mvprintw(19, 44, "Username or Password is incorrect.");
                            mvprintw(20, 44, "Try again or create a new account.");
                            fnX = 17;
                            lnX = 16;
                            uX = 15;
                            pX = 15;
                            luX = (this->getCols()/2)+15;
                            lpX = (this->getCols()/2)+15;
                            fnss.str("");
                            lnss.str("");
                            uss.str("");
                            pss.str("");
                            luss.str("");
                            lpss.str("");
                            for (int i = 0; i < 20; i++) {
                                mvprintw(fnY, (fnX+i), " ");
                                mvprintw(lnY, (lnX+i), " ");
                                mvprintw(uY, (uX+i), " ");
                                mvprintw(pY, (pX+i), " ");
                                mvprintw(luY, (luX+i), " ");
                                mvprintw(lpY, (lpX+i), " ");
                            }
                        }
                    }
                    break;
                }
                break;
            case 5: // Exit
                this->screenNumber = 7;
                this->changeScreens(true);
                break;
            }
            break;
        default: // User types into fields
            char temp = (char)keyPress;
            switch(colIndex) {
            case 0:
                switch(rowIndex) {
                case 0:
                    if ((fnX-17) < 20) {
                        fnss << temp;
                        sstemp << temp;
                        mvprintw(fnY, fnX, sstemp.str().c_str());
                        sstemp.str("");
                        fnX++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 1:
                    if ((lnX-16) < 20) {
                        lnss << temp;
                        sstemp << temp;
                        mvprintw(lnY, lnX, sstemp.str().c_str());
                        sstemp.str("");
                        lnX++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 2:
                    if ((uX-15) < 20) {
                        uss << temp;
                        sstemp << temp;
                        mvprintw(uY, uX, sstemp.str().c_str());
                        sstemp.str("");
                        uX++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 3:
                    if ((pX-15) < 20) {
                        pss << temp;
                        sstemp << temp;
                        mvprintw(pY, pX, sstemp.str().c_str());
                        sstemp.str("");
                        pX++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 4:
                    move(curY, curX);
                    printw(">");
                    move(curY, curX);
                    break;
                case 5:
                    move(curY, curX);
                    printw(">");
                    move(curY, curX);
                    break;
                }
                break;
            case 1:
                switch(rowIndex) {
                case 0:
                case 1:
                    if ((luX-((this->getCols()/2)+15)) < 20) {
                        luss << temp;
                        sstemp << temp;
                        mvprintw(luY, luX, sstemp.str().c_str());
                        sstemp.str("");
                        luX++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 2:
                case 3:
                    if ((lpX-((this->getCols()/2)+15)) < 20) {
                        lpss << temp;
                        sstemp << temp;
                        mvprintw(lpY, lpX, sstemp.str().c_str());
                        sstemp.str("");
                        lpX++;
                    } else {
                        move(curY, curX);
                        printw(" ");
                        move(curY, curX);
                    }
                    break;
                case 4:
                    move(curY, curX);
                    printw(">");
                    move(curY, curX);
                    break;
                case 5:
                    move(curY, curX);
                    printw(">");
                    move(curY, curX);
                    break;
                }
                break;
            }
            break;
        }
    }

    this->changeScreens(false);
    clear();
    refresh();
}
