#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    init();
}

MainMenu::MainMenu(System * sys) :
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    main_system = sys;
    init();
}

MainMenu::~MainMenu()
{
    delete ui;
    delete login_screen;
    delete profile_screen;
    delete chat_screen;
}

void MainMenu::init(){
    login_screen = new Login(this);
    profile_screen = new ProfileGUI(this);
    chat_screen = new ChatGUI(this);
}

System * MainMenu::getSystem(){
    return main_system;
}

Login * MainMenu::getLoginScreen(){
    return login_screen;
}

void MainMenu::on_pushButton_profile_clicked()
{
    this->close();
    profile_screen->show();
}

void MainMenu::on_pushButton_chat_clicked()
{
    this->close();
    chat_screen->show();
}

void MainMenu::on_pushButton_signout_clicked()
{
    this->close();
    login_screen->show();
}
