#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <string>
#include <iostream>
//#include "../model/system.h"
#include "mainmenu.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

private slots:
    void on_pushButton_signin_clicked();
    void on_pushButton_login_clicked();

public:
    explicit Login(QWidget *parent = 0);
    Login(MainMenu * mm);
    ~Login();
    void openMainScreen();
    void setMainMenu(MainMenu * mm);

private:
    Ui::Login *ui;
    MainMenu * main_menu;
    void init();
};

#endif // LOGIN_H
