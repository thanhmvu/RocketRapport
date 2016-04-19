#include <iostream>
#include "mainmenuui.h"

using namespace std;

int main(int argc, char *argv[])
{
    initscr();
    echo();
    keypad(stdscr, TRUE);
    curs_set(0);

    MainMenuUI mainMenu;
    mainMenu.displayScreen();
    mainMenu.runScreen();

    endwin();

//    std::cout<< "Start GUI\n";
//    QApplication a(argc, argv);
//    System sys;

//    ProfileGUI profileUI;
//    BlogGUI blogUI;
//    TweetGUI tweetUI;
//    ChatGUI chatUI;
//    ScrapbookGUI sbUI;
//    Login login;
//    MainMenu mm(&login, &profileUI, &blogUI, &tweetUI, &chatUI, &sbUI);

//    blogUI.setMainMenu(&mm);
//    profileUI.setMainMenu(&mm);
//    login.setMainMenu(&mm);

//    login.setMainSystem(&sys);

//    std::cout<< "Screens initiated\n";

//    login.show();
//    std::cout<< "Called Login screen\n";


//    return a.exec();


    return 0;
}
