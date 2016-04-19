#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "bloggui.h"
#include "chatgui.h"
#include "profilegui.h"
#include "scrapbookgui.h"
#include "tweetgui.h"
#include "login.h"
#include "../model/system.h"

namespace Ui {
class MainMenu;
}

class ProfileGUI;
class BlogGUI;
class ChatGUI;
class TweetGUI;
class ScrapbookGUI;
class Login;

class MainMenu : public QWidget
{
    Q_OBJECT

private:
    System * main_system;

    Ui::MainMenu *ui;
    ProfileGUI * profile_screen;
    BlogGUI * blog_screen;
    TweetGUI * tweet_screen;
    ChatGUI * chat_screen;
    ScrapbookGUI * sb_screen;
    Login * login_screen;


public:
    explicit MainMenu(QWidget *parent = 0);
    MainMenu(System * sys);
//    MainMenu(Login * login, ProfileGUI * profile, BlogGUI * blog, TweetGUI * tweet,
//              ChatGUI * chat, ScrapbookGUI * scrapbook);
    ~MainMenu();
    void init(ProfileGUI * profile, BlogGUI * blog, TweetGUI * tweet,
              ChatGUI * chat, ScrapbookGUI * scrapbook);
    void init();
    System * getSystem();
    Login * getLoginScreen();

private slots:
    void on_pushButton_profile_clicked();
    void on_pushButton_chat_clicked();
    void on_pushButton_blog_clicked();
    void on_pushButton_tweet_clicked();
    void on_pushButton_scrapbook_clicked();
    void on_pushButton_signout_clicked();
};

#endif // MAINMENU_H
