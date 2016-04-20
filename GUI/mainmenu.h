#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "chatgui.h"
#include "profilegui.h"
#include "login.h"
#include "../model/system.h"

namespace Ui {
class MainMenu;
}

class ProfileGUI;
class ChatGUI;
class Login;

class MainMenu : public QWidget
{
    Q_OBJECT

private:
    System * main_system;

    Ui::MainMenu *ui;
    ProfileGUI * profile_screen;
    ChatGUI * chat_screen;
    Login * login_screen;


public:
    explicit MainMenu(QWidget *parent = 0);
    MainMenu(System * sys);
    ~MainMenu();
    void init();
    System * getSystem();
    Login * getLoginScreen();

private slots:
    void on_pushButton_profile_clicked();
    void on_pushButton_chat_clicked();
    void on_pushButton_signout_clicked();
};

#endif // MAINMENU_H
