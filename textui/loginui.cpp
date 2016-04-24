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

    curs_set(1);
    move(fnY, fnX);
    refresh();
    getch();


    this->changeScreens(false);
    clear();
    refresh();
}
