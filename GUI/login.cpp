#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_signin_clicked()
{
    std::string username = ui->lineEdit_signin_user->text().toStdString();
    std::string password = ui->lineEdit_signin_pw->text().toStdString();
    std::string firstname = ui->lineEdit_firstname->text().toStdString();
    std::string lastname = ui->lineEdit_lastname->text().toStdString();

//    bool accountCreated = main_system->createAccount(username,password,firstname,lastname);

//    if(accountCreated){
//        // sign in successful, proceed to menu screen
//        openMainScreen();
//    }else{
//        // username already exists. prompt for new username
//    }
}

void Login::openMainScreen(){

}
