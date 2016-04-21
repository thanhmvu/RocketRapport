#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    init();
}

Login::Login(MainMenu * mm):
    ui(new Ui::Login)
{
    ui->setupUi(this);
    main_menu = mm;
    init();
}

Login::~Login()
{
    delete ui;
}

void Login::init(){

}

void Login::setMainMenu(MainMenu * mm){
    main_menu = mm;
}

void Login::on_pushButton_signin_clicked()
{
    std::string username = ui->lineEdit_signin_user->text().toStdString();
    std::string password = ui->lineEdit_signin_pw->text().toStdString();
    std::string firstname = ui->lineEdit_firstname->text().toStdString();
    std::string lastname = ui->lineEdit_lastname->text().toStdString();

    bool accountCreated = main_menu->getSystem()->createAccount(username,password,firstname,lastname);

    if(accountCreated){
        std::cout<< "Sign in successfully, proceed to menu screen \n";
        openMainScreen();
    }else{
        // username already exists.
        // show warning message and prompt for another username.
        std::cout<< "Failed to log \n";
        ui->lineEdit_signin_user->setText("WARNING: Username already exists. Try again!");
    }
}

void Login::openMainScreen(){
    this->close();
    main_menu->show();
}

void Login::on_pushButton_login_clicked()
{
    std::string username = ui->lineEdit_login_user->text().toStdString();
    std::string password = ui->lineEdit_login_pw->text().toStdString();

    bool accountLoggedIn = main_menu->getSystem()->login(username,password);

    if(accountLoggedIn){
        // log in successfully, proceed to menu screen
        std::cout<< "Log in successfully, proceed to menu screen \n";
        openMainScreen();
    }else{
        // no username found.
        // show warning message and prompt for another username.
        std::cout<< "Failed to log \n";
        ui->lineEdit_login_user->setText("WARNING: Username or Password is incorrect");
        ui->lineEdit_login_pw->setText("WARNING: Try again or create new account");
    }
}
