#ifndef GROUPGUI_H
#define GROUPGUI_H

#include <QWidget>
#include "mainmenu.h"

namespace Ui {
class GroupGUI;
}

class MainMenu;

class GroupGUI : public QWidget
{
    Q_OBJECT

public:
    explicit GroupGUI(QWidget *parent = 0);
    GroupGUI(MainMenu* mm);
    ~GroupGUI();
    void init();
    void loadGroup(QString groupname);

private:
    Ui::GroupGUI *ui;
    MainMenu* main_menu;
};

#endif // GROUPGUI_H
