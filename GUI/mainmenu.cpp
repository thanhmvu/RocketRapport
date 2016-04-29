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


    // display create-group elements
    ui->label_enter_gName->setVisible(false);
    ui->lineEdit_groupname->setVisible(false);
    ui->pushButton_launch->setVisible(false);
    ui->pushButton_cancel->setVisible(false);

    reload();
}

void MainMenu::reload(){
    // retrieve all accounts from database
//    main_system->retrieveAllAccounts();
    main_system->refreshSystem();

    // display the list of users as a list of user buttons
    QWidget *scroll_widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();
    for(auto pair: main_system->getAllAccounts()){
        QString username = pair.first;
        QPushButton *button = new QPushButton();
        button->setText(username);
        button->setFixedWidth(150);
        layout->addWidget(button);
        connect(button,SIGNAL(clicked()),this,SLOT(openUserProfile()));
    }
    scroll_widget->setLayout(layout);
    ui->scrollArea_userList->setWidget(scroll_widget);


    ////////////////////////////////////////////////////////////////////
    /// Load list of groups from SYSTEM/ DATABASE
    /// To prevent memory leaks, pay attention to userlist and grouplist
    //////////////////////////////////////////////////////////////////
    std::vector<QString> groupList;
    for(int i = 0; i<3; i++){
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
    QString current_user = main_system->getCurrentUser()->getUsername();

    // load content based on viewer
    profile_screen->loadProfile(username, current_user);

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
    QString username = current_user->getUsername();

    // load content based on viewer
    profile_screen->loadProfile(username, username);

    this->close();
    profile_screen->show();
}

void MainMenu::on_pushButton_chat_clicked()
{
//    chat_screen->refreshChatScreen(); // chat screen constantly refreshes itself
    chat_screen->setIsDisplaying(true);

    this->close();
    chat_screen->show();
}

void MainMenu::on_pushButton_signout_clicked()
{
    this->close();
    login_screen->show();
}

void MainMenu::on_pushButton_launch_clicked()
{
    // create new group
    QString gName = ui->lineEdit_groupname->text();
    if(!main_system->createGroup(gName)){
        // username already exists.
        // show warning message and prompt for another username.
        ui->lineEdit_groupname->setText("WARNING: Group name already exists. Try again!");
    }else{
        // add this user to group



        // successfully create group. open group screen
        // load content based on viewer
        group_screen->loadGroup(gName);

        // clean new-groupname box
        ui->lineEdit_groupname->setText("");

        // reset visibility of create-group elements
        ui->label_enter_gName->setVisible(false);
        ui->lineEdit_groupname->setVisible(false);
        ui->pushButton_launch->setVisible(false);
        ui->pushButton_cancel->setVisible(false);

        this->close();
        group_screen->show();
    }
}

void MainMenu::on_pushButton_new_group_clicked()
{
    ui->label_enter_gName->setVisible(true);
    ui->lineEdit_groupname->setVisible(true);
    ui->pushButton_launch->setVisible(true);
    ui->pushButton_cancel->setVisible(true);
}

void MainMenu::on_pushButton_cancel_clicked()
{
    // clean new-groupname box
    ui->lineEdit_groupname->setText("");

    // reset visibility of create-group elements
    ui->label_enter_gName->setVisible(false);
    ui->lineEdit_groupname->setVisible(false);
    ui->pushButton_launch->setVisible(false);
    ui->pushButton_cancel->setVisible(false);

}
