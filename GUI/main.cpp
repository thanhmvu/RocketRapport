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
    System sys("/auto/bunter_usr11/cs205_2016_Grp09/gProject_db/gProjectDB.db");
    MainMenu mm(&sys); // create the gui

    mm.getLoginScreen()->show();
    std::cout<< "Called Login screen\n";

    return a.exec();
}
