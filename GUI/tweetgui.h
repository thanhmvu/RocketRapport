#ifndef TWEETGUI_H
#define TWEETGUI_H

#include <QWidget>
#include "profilegui.h"

namespace Ui {
class TweetGUI;
}

class ProfileGUI;

class TweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit TweetGUI(QWidget *parent = 0);
    TweetGUI(ProfileGUI* pf_scrn);
    ~TweetGUI();

private:
    Ui::TweetGUI *ui;
    ProfileGUI* profile_screen;
    void init();
};

#endif // TWEETGUI_H
