#ifndef TWEETGUI_H
#define TWEETGUI_H

#include <QWidget>
#include "mainmenu.h"

namespace Ui {
class TweetGUI;
}

class MainMenu;

class TweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit TweetGUI(QWidget *parent = 0);
    TweetGUI(MainMenu* mm);
    ~TweetGUI();

private:
    Ui::TweetGUI *ui;
    MainMenu* main_menu;
    void init();
};

#endif // TWEETGUI_H
