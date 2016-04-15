#include "login.h"
#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
//    MainMenu w;
    w.show();

    return a.exec();
}
