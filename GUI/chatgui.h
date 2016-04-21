#ifndef CHATGUI_H
#define CHATGUI_H

#include <QWidget>
#include "mainmenu.h"
#include <QScrollBar>
#include <QVBoxLayout>

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
    void updateUserList();
    void updateChatBox();

private slots:
    void on_pushButton_main_menu_clicked();
    void on_pushButton_send_mess_clicked();
    void openChat();

private:
    Ui::ChatGUI *ui;
    MainMenu *main_menu;
    void init();
};

#endif // CHATGUI_H
