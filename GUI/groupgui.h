#ifndef GROUPGUI_H
#define GROUPGUI_H

#include <QWidget>
#include <QTextBrowser>
#include "mainmenu.h"
#include "../model/group.h"

namespace Ui {
class GroupGUI;
}

class MainMenu;

class GroupGUI : public QWidget
{
    Q_OBJECT

private:
    Ui::GroupGUI *ui;
    MainMenu* main_menu;
    Group * this_group;
    QString curr_viewer;
    QWidget *posts_widget;
    QVBoxLayout *posts_layout;
    QTextBrowser* memlist;
    void loadGroupFeed();
    void displayPost(BlogPost * post);
    void loadMemberList();

public:
    explicit GroupGUI(QWidget *parent = 0);
    GroupGUI(MainMenu* mm);
    ~GroupGUI();
    void init();
    void loadGroup(QString groupname, QString viewer);

private slots:
    void on_pushButton_mainmenu_clicked();

    void on_pushButton_newPost_clicked();
    void on_pushButton_show_about_clicked();
    void on_pushButton_savePost_clicked();
    void on_pushButton_cancelPost_clicked();
    void on_pushButton_add_member_clicked();
};

#endif // GROUPGUI_H
