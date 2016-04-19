#ifndef SCREENUI_H
#define SCREENUI_H
#include <ncurses.h>
#include <iostream>
#include <string>


class ScreenUI
{

    int menuIndex;
    int numOfOptions;
    int rows;
    int cols;

public:
    ScreenUI();

    virtual void displayScreen() = 0;
    virtual void runScreen() = 0;

    int getMenuIndex();
    void moveDownMenuIndex();
    void moveUpMenuIndex();
    int getNumOfOptions();
    int getRows();
    int getCols();
};

#endif // SCREENUI_H
