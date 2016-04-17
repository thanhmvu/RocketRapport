#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "bloggui.h"
#include "chatgui.h"
#include "profilegui.h"
#include "scrapbookgui.h"
#include "tweetgui.h"

namespace Ui {
class MainMenu;
}

class ProfileGUI;

class MainMenu : public QWidget
{
    Q_OBJECT

private:
    Ui::MainMenu *ui;
    ProfileGUI * profile_screen;
    BlogGUI * blog_screen;
    TweetGUI * tweet_screen;
    ChatGUI * chat_screen;
    ScrapbookGUI * sb_screen;

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    void init(ProfileGUI * profile, BlogGUI * blog, TweetGUI * tweet,
              ChatGUI * chat, ScrapbookGUI * scrapbook);

private slots:
    void on_pushButton_profile_clicked();
};

#endif // MAINMENU_H