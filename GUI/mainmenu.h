#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "chatgui.h"
#include "profilegui.h"
#include "groupgui.h"
#include "login.h"
#include "../model/system.h"

namespace Ui {
class MainMenu;
}

class ProfileGUI;
class ChatGUI;
class GroupGUI;
class Login;

class MainMenu : public QWidget
{
    Q_OBJECT

private:
    System * main_system;

    Ui::MainMenu *ui;
    ProfileGUI * profile_screen;
    ChatGUI * chat_screen;
    GroupGUI * group_screen;
    Login * login_screen;


public:
    explicit MainMenu(QWidget *parent = 0);
    MainMenu(System * sys);
    ~MainMenu();
    void init();
    System * getSystem();
    Login * getLoginScreen();
    void reload();

private slots:
    void on_pushButton_profile_clicked();
    void on_pushButton_chat_clicked();
    void on_pushButton_signout_clicked();
    void openUserProfile();
    void openGroupScreen();
    void on_pushButton_launch_clicked();
    void on_pushButton_new_group_clicked();
    void on_pushButton_cancel_clicked();
};

#endif // MAINMENU_H
