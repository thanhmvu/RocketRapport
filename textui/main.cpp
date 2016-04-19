#include <iostream>
#include "loginui.h"
#include "mainmenuui.h"
#include "chatui.h"
#include "profileui.h"
#include "blogui.h"
#include "tweetui.h"
#include "scrapbookui.h"

using namespace std;

int main(int argc, char *argv[])
{
    initscr();
    echo();
    keypad(stdscr, TRUE);
    curs_set(0);

    bool running = true;

    MainMenuUI mainMenu;

    while (running) {
        switch(mainMenu.screenNumber) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        }
    }

    mainMenu.displayScreen();
    mainMenu.runScreen();

    endwin();

    return 0;
}
