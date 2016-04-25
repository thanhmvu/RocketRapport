#ifndef BLOGGUI_H
#define BLOGGUI_H

#include <QWidget>
#include <QTextBrowser>
#include <QVBoxLayout>
#include "profilegui.h"
#include "../model/blogpost.h"

namespace Ui {
class BlogGUI;
}

class ProfileGUI;

class BlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit BlogGUI(QWidget *parent = 0);
    BlogGUI(ProfileGUI* pfGUI);
    ~BlogGUI();
    void loadBlogView(QString blog_owner, QString viewer);

private slots:
    void on_pushButton_newPost_clicked();
    void on_pushButton_savePost_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_back_to_profile_clicked();

private:
    Ui::BlogGUI *ui;
    ProfileGUI* profile_screen;
    QWidget *posts_widget;
    QVBoxLayout *posts_layout;
    void init();
    void displayPost(BlogPost * post);
};

#endif // BLOGGUI_H
