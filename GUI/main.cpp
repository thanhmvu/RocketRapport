#include <QApplication>
#include "../model/system.h"
#include "bloggui.h"
#include "chatgui.h"
#include "login.h"
#include "mainmenu.h"
#include "profilegui.h"
#include "scrapbookgui.h"
#include "tweetgui.h"

int main(int argc, char *argv[])
{
    std::cout<< "Start GUI\n";
    QApplication a(argc, argv);
    System sys("./gProjectDB.db");

    ProfileGUI profileUI;
    BlogGUI blogUI;
    TweetGUI tweetUI;
    ChatGUI chatUI;
    ScrapbookGUI sbUI;
    Login login;
    MainMenu mm(&login, &profileUI, &blogUI, &tweetUI, &chatUI, &sbUI);

    blogUI.setMainMenu(&mm);
    profileUI.setMainMenu(&mm);
    login.setMainMenu(&mm);

    login.setMainSystem(&sys);

    std::cout<< "Screens initiated\n";

    login.show();
    std::cout<< "Called Login screen\n";


    return a.exec();
}
