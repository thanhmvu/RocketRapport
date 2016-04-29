#ifndef TWEETGUI_H
#define TWEETGUI_H

#include <QWidget>
#include <QTextBrowser>
#include "profilegui.h"
#include "../model/tweetpost.h"

namespace Ui {
class TweetGUI;
}

class ProfileGUI;

class TweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit TweetGUI(QWidget *parent = 0);
    TweetGUI(ProfileGUI* pfGUI);
    ~TweetGUI();
    void loadTweetView(QString owner, QString viewer);

private slots:

    void on_pushButton_cancel_clicked();

    void on_pushButton_savePost_clicked();

    void on_pushButton_newPost_clicked();

    void on_pushButton_back_to_profile_clicked();

private:
    Ui::TweetGUI *ui;
    ProfileGUI* profile_screen;
    QWidget *posts_widget;
    QVBoxLayout *posts_layout;
    void init();
    void displayPost(TweetPost * post);
};

#endif // TWEETGUI_H
