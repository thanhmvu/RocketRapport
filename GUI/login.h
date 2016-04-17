#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <string>
#include <iostream>
#include "../model/system.h"
#include "mainmenu.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

private:
    Ui::Login *ui;
    System * main_system;
    MainMenu * main_menu;

private slots:
    void on_pushButton_signin_clicked();
    void on_pushButton_login_clicked();

public:
    explicit Login(QWidget *parent = 0);
//    explicit Login(QWidget *parent = 0, System * sys = 0, MainMenu * mm = 0);
    ~Login();
    void openMainScreen();
    void setMainSystem(System * sys);
    void setMainMenu(MainMenu * mm);

};

#endif // LOGIN_H
