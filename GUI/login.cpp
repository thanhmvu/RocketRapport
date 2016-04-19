#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
//    main_system = new System();
//    main_menu = new MainMenu();
}

//Login::Login(QWidget *parent = 0, System * sys, MainMenu * mm):
//    QWidget(parent),
//    ui(new Ui::Login)
//{
//    ui->setupUi(this);
//    main_system = sys;
//    main_menu = mm;
//}

Login::~Login()
{
    delete ui;
}

void Login::setMainSystem(System * sys){
    main_system = sys;
}

void Login::setMainMenu(MainMenu * mm){
    main_menu = mm;
}

void Login::on_pushButton_signin_clicked()
{
    std::cout<< "Clicked signin button\n";
    std::string username = ui->lineEdit_signin_user->text().toStdString();
    std::string password = ui->lineEdit_signin_pw->text().toStdString();
    std::string firstname = ui->lineEdit_firstname->text().toStdString();
    std::string lastname = ui->lineEdit_lastname->text().toStdString();

    bool accountCreated = main_system->createAccount(username,password,firstname,lastname);

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
    main_menu->show();
    this->close();
}

void Login::on_pushButton_login_clicked()
{
    std::string username = ui->lineEdit_login_user->text().toStdString();
    std::string password = ui->lineEdit_login_pw->text().toStdString();

    bool accountLoggedIn = main_system->login(username,password);

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
