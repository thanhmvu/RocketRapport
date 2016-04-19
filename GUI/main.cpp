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
    QApplication a(argc, argv);
    System sys;

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


    login.show();

    return a.exec();
}
