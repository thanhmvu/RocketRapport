#ifndef PROFILEGUI_H
#define PROFILEGUI_H

#include <QWidget>
#include "mainmenu.h"
#include "bloggui.h"
#include "tweetgui.h"

namespace Ui {
class ProfileGUI;
}

class MainMenu;
class BlogGUI;
class TweetGUI;

class ProfileGUI : public QWidget
{
    Q_OBJECT

private:
    Ui::ProfileGUI *ui;
    MainMenu* main_menu;
    BlogGUI * blog_screen;
    TweetGUI * tweet_screen;
    void init();

public:
    explicit ProfileGUI(QWidget *parent = 0);
    ProfileGUI(MainMenu * mm);
    ~ProfileGUI();
    void setMainMenu(MainMenu* mm);
    void loadProfile();

private slots:
    void on_pushButton_back_to_menu_clicked();
    void on_pushButton_blog_clicked();
    void on_pushButton_tweet_clicked();
    void on_pushButton_scrapbook_clicked();
};

#endif // PROFILEGUI_H
