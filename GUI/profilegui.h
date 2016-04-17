#ifndef PROFILEGUI_H
#define PROFILEGUI_H

#include <QWidget>
#include "mainmenu.h"

namespace Ui {
class ProfileGUI;
}

class MainMenu;

class ProfileGUI : public QWidget
{
    Q_OBJECT

private:
    Ui::ProfileGUI *ui;
    MainMenu* main_menu;

public:
    explicit ProfileGUI(QWidget *parent = 0);
    ~ProfileGUI();
    void setMainMenu(MainMenu* mm);

private slots:
    void on_pushButton_back_to_menu_clicked();
};

#endif // PROFILEGUI_H
