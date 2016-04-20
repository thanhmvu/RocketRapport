#ifndef CHATGUI_H
#define CHATGUI_H

#include <QWidget>
#include "mainmenu.h"
#include <QScrollBar>

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

private slots:
    void on_pushButton_main_menu_clicked();

private:
    Ui::ChatGUI *ui;
    MainMenu *main_menu;
    void init();
};

#endif // CHATGUI_H
