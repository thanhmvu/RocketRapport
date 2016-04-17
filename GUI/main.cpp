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
    MainMenu mm;
    ProfileGUI profileGUI;
    profileGUI.setMainMenu(&mm);
    mm.init(&profileGUI, 0, 0, 0, 0);

    Login w;
    w.setMainSystem(&sys);
    w.setMainMenu(&mm);
    w.show();

    return a.exec();
}
