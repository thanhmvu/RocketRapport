#ifndef CHATGUI_H
#define CHATGUI_H

#include <QWidget>
#include "mainmenu.h"

namespace Ui {
class ChatGUI;
}

class MainMenu;

class ChatGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChatGUI(QWidget *parent = 0);
    ChatGUI(MainMenu * mm);
    ~ChatGUI();

private:
    Ui::ChatGUI *ui;
    MainMenu *main_menu;
    void init();
};

#endif // CHATGUI_H
