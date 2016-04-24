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
    // display the list of users as a list of user buttons
    QWidget *scroll_widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();
    for(auto pair: main_system->getAllAccounts()){
        QString username = QString::fromStdString(pair.first);
        QPushButton *button = new QPushButton();
        button->setText(username);
        button->setFixedWidth(150);
        layout->addWidget(button);
        connect(button,SIGNAL(clicked()),this,SLOT(openUserProfile()));
    }
    scroll_widget->setLayout(layout);
    ui->scrollArea_userList->setWidget(scroll_widget);

    // load grouplist
    ////////////////////////////////////////////////////////////////////
    /// Load list of groups from SYSTEM/ DATABASE
    /// To prevent memory leaks, pay attention to userlist and grouplist
    //////////////////////////////////////////////////////////////////
    std::vector<QString> groupList;
    for(int i = 0; i<20; i++){
        groupList.push_back(QString ("Group_%1").arg(i));
    }

    // display the list of groups as a list of group buttons
    QWidget *scroll_widget2 = new QWidget();
    QVBoxLayout *layout2 = new QVBoxLayout();
    for(QString groupname: groupList){
        QPushButton *button = new QPushButton();
        button->setText(groupname);
        button->setFixedWidth(150);
        layout2->addWidget(button);
        connect(button,SIGNAL(clicked()),this,SLOT(openGroupScreen()));
    }
    scroll_widget2->setLayout(layout2);
    ui->scrollArea_groupList->setWidget(scroll_widget2);
}

void MainMenu::openUserProfile(){
    QPushButton* button = qobject_cast<QPushButton*> (QObject::sender());
    QString username = button->text();
    // load content based on viewer
    profile_screen->loadProfile(username);

    this->close();
    profile_screen->show();
}

void MainMenu::openGroupScreen(){
    QPushButton* button = qobject_cast<QPushButton*> (QObject::sender());
    QString groupname = button->text();
    // load content based on viewer
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

    // load content based on viewer
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
