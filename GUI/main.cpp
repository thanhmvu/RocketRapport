#include "login.h"
#include "../model/system.h"
#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    System sys;
    MainMenu mm;

    Login w;
    w.setMainSystem(&sys);
    w.setMainMenu(&mm);
    w.show();

    return a.exec();
}
