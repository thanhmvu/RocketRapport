#ifndef SCRAPBOOKGUI_H
#define SCRAPBOOKGUI_H

#include <QWidget>
#include "mainmenu.h"

namespace Ui {
class ScrapbookGUI;
}

class MainMenu;

class ScrapbookGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ScrapbookGUI(QWidget *parent = 0);
    ScrapbookGUI(MainMenu* mm);
    ~ScrapbookGUI();

private:
    Ui::ScrapbookGUI *ui;
    MainMenu* main_menu;
    void init();
};

#endif // SCRAPBOOKGUI_H
