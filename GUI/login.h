#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <string>
#include <iostream>
#include "../model/system.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void openMainScreen();

private slots:
    void on_pushButton_signin_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::Login *ui;
    System * main_system;
};

#endif // LOGIN_H
