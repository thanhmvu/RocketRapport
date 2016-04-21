#ifndef TWEETGUI_H
#define TWEETGUI_H

#include <QWidget>
#include <QTextBrowser>
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
    void loadTweetView(QString username);

private slots:
    void on_pushButton_cancel_clicked();
    void on_pushButton_savePost_2_clicked();
    void on_pushButton_newPost_2_clicked();
    void on_pushButton_back_to_profile_clicked();

private:
    Ui::TweetGUI *ui;
    ProfileGUI* profile_screen;
    void init();
};

#endif // TWEETGUI_H
