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

    LoginUI login;
    MainMenuUI mainMenu;
    ChatUI chat;
    ProfileUI profile;
    BlogUI blog;
    TweetUI tweet;
    ScrapbookUI scrapbook;

    while (running) {
        switch(mainMenu.screenNumber) {
        case 0: // Login
            login.displayScreen();
            login.runScreen();
            chat.changeScreens(false);
            clear();
            break;
        case 1: // Main Menu
            mainMenu.displayScreen();
            mainMenu.runScreen();
            mainMenu.setMenuIndex(0);
            mainMenu.changeScreens(false);
            clear();
            break;
        case 2: // Messaging
            chat.displayScreen();
            chat.runScreen();
            chat.changeScreens(false);
            clear();
            break;
        case 3: // Profile
            profile.displayScreen();
            profile.runScreen();
            profile.changeScreens(false);
            clear();
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
