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
    group_screen = new GroupGUI(this);

    reload();
}

void MainMenu::reload(){
    // load userlist
    ////////////////////////////////////////////////////////////////////
    /// Load list of user name from SYSTEM/ DATABASE
    /// To prevent memory leaks, pay attention to userlist and grouplist
    //////////////////////////////////////////////////////////////////
    std::vector<QString> userList;
    for(int i = 0; i<10; i++){
        userList.push_back(QString ("User_%1").arg(i));
    }

    // display the list of users as a list of user buttons
    QVBoxLayout *layout = new QVBoxLayout();
    for(QString username: userList){
        QPushButton *button = new QPushButton();
        button->setText(username);
        button->setFixedWidth(150);
        layout->addWidget(button);
        connect(button,SIGNAL(clicked()),this,SLOT(openUserProfile()));
    }
    ui->scrollArea_userList->setLayout(layout);

    // load grouplist
    ////////////////////////////////////////////////////////////////////
    /// Load list of groups from SYSTEM/ DATABASE
    /// To prevent memory leaks, pay attention to userlist and grouplist
    //////////////////////////////////////////////////////////////////
    std::vector<QString> groupList;
    for(int i = 0; i<10; i++){
        groupList.push_back(QString ("Group_%1").arg(i));
    }

    // display the list of groups as a list of group buttons
    QVBoxLayout *layout2 = new QVBoxLayout();
    for(QString groupname: groupList){
        QPushButton *button = new QPushButton();
        button->setText(groupname);
        button->setFixedWidth(150);
        layout2->addWidget(button);
        connect(button,SIGNAL(clicked()),this,SLOT(openGroupScreen()));
    }
    ui->scrollArea_groupList->setLayout(layout2);
}

void MainMenu::openUserProfile(){
    QPushButton* button = qobject_cast<QPushButton*> (QObject::sender());
    QString username = button->text();

    this->close();
    profile_screen->loadProfile(username);
    profile_screen->show();
}

void MainMenu::openGroupScreen(){
    QPushButton* button = qobject_cast<QPushButton*> (QObject::sender());
    QString groupname = button->text();
    group_screen->loadGroup(groupname);

    this->close();
    group_screen->show();
}

System * MainMenu::getSystem(){
    return main_system;
}

Login * MainMenu::getLoginScreen(){
    return login_screen;
}

void MainMenu::on_pushButton_profile_clicked()
{
    Account * current_user = this->getSystem()->getCurrentUser();
    profile_screen->loadProfile(QString::fromStdString(current_user->getUsername()));
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
