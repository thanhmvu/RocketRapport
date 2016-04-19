#ifndef SCREENUI_H
#define SCREENUI_H
#include <ncurses.h>
#include <iostream>
#include <string>


class ScreenUI
{
    /*
     * Screen # Reference:
     *
     * 0  -  Login
     * 1  -  Main Menu
     * 2  -  Messaging
     * 3  -  My Profile
     * 4  -  My Blog
     * 5  -  My Tweets
     * 6  -  My Scrapbook
     * 7  -  Exit
     *
     */

    int menuIndex;
    int numOfOptions;
    int rows;
    int cols;
    bool changeScreen;

public:
    ScreenUI();

    static int screenNumber;

    virtual void displayScreen() = 0;
    virtual void runScreen() = 0;

    void changeScreens(bool change);

    int getMenuIndex();
    void setMenuIndex(int index);
    void moveDownMenuIndex();
    void moveUpMenuIndex();
    int getNumOfOptions();
    void setNumOfOptions(int options);
    int getRows();
    int getCols();
    bool getChangeScreens();
};

#endif // SCREENUI_H
