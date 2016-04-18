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

    MainMenu mm(&profileUI, &blogUI, &tweetUI, &chatUI, &sbUI);

    blogUI.setMainMenu(&mm);
    profileUI.setMainMenu(&mm);

    Login w;
    w.setMainSystem(&sys);
    w.setMainMenu(&mm);

    w.show();

    return a.exec();
}
