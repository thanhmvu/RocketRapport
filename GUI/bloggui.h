#ifndef BLOGGUI_H
#define BLOGGUI_H

#include <QWidget>
#include "profilegui.h"

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

private slots:
    void on_pushButton_newPost_clicked();
    void on_pushButton_savePost_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::BlogGUI *ui;
    ProfileGUI* profile_screen;
    void init();
};

#endif // BLOGGUI_H
