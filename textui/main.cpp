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

    System mySystem("/auto/bunter_usr11/cs205_2016_Grp09/gProject_db/gProjectDB.db");

    LoginUI login(&mySystem);
    MainMenuUI mainMenu(&mySystem);
    ChatUI chat(&mySystem);
    ProfileUI profile(&mySystem);
    BlogUI blog(&mySystem);
    TweetUI tweet(&mySystem);
    ScrapbookUI scrapbook(&mySystem);

    while (running) {
        switch(mainMenu.screenNumber) {
        case 0: // Login
            login.displayScreen();
            login.runScreen();
            break;
        case 1: // Main Menu
            mainMenu.displayScreen();
            mainMenu.runScreen();
            break;
        case 2: // Messaging
            chat.displayScreen();
            chat.runScreen();
            break;
        case 3: // Profile
            profile.displayScreen();
            profile.runScreen();
            break;
        case 4: // Blog
            blog.displayScreen();
            blog.runScreen();
            blog.changeScreens(false);
            clear();
            break;
        case 5: // Tweet
            tweet.displayScreen();
            tweet.runScreen();
            tweet.changeScreens(false);
            clear();
            break;
        case 6: // Scrapbook
            scrapbook.displayScreen();
            scrapbook.runScreen();
            scrapbook.changeScreens(false);
            clear();
            break;
        case 7: // Exit
            running = false;
            break;
        }
    }

    endwin();

    return 0;
}
