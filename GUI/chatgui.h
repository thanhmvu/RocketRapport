#ifndef CHATGUI_H
#define CHATGUI_H

#include <QWidget>
#include "mainmenu.h"
#include <QScrollBar>
#include <QVBoxLayout>
#include "../model/account.h"
#include <vector>
#include <QTimer>
#include <QPushButton>

namespace Ui {
class ChatGUI;
}

class MainMenu;
//class Account;

class ChatGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChatGUI(QWidget *parent = 0);
    ChatGUI(MainMenu * mm);
    ~ChatGUI();
    void autoUpdate();
    void setIsDisplaying(bool state);

private slots:
    void on_pushButton_main_menu_clicked();
    void on_pushButton_send_mess_clicked();
    void openChat();
    void refreshChatScreen();

private:
    // own these objects
    Ui::ChatGUI *ui;
    QTimer * timer;
    std::map<QString,int> chatMap; // map talking-to user to number of messages
    // does not own
    MainMenu *main_menu;
    Account * talking_to_user;
    Account * curr_user;
    std::vector<QPushButton*> userList;
    QWidget *scroll_widget;
    QVBoxLayout *layout;
    bool isDisplaying;

    void updateUserList();
    void displayCurrentChat();
    void clearUserBox();
};

#endif // CHATGUI_H
