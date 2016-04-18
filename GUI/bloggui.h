#ifndef BLOGGUI_H
#define BLOGGUI_H

#include <QWidget>
#include "mainmenu.h"

namespace Ui {
class BlogGUI;
}

class MainMenu;

class BlogGUI : public QWidget
{
    Q_OBJECT

public:
    explicit BlogGUI(QWidget *parent = 0);
    BlogGUI(MainMenu* mm);
    ~BlogGUI();
    void setMainMenu(MainMenu* mm);

private slots:
    void on_pushButton_newPost_clicked();

    void on_pushButton_savePost_clicked();

    void on_pushButton_back_to_menu_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::BlogGUI *ui;
    MainMenu* main_menu;
    void init();
};

#endif // BLOGGUI_H
