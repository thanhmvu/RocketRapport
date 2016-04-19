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

//MainMenu::MainMenu(Login * login, ProfileGUI * profile, BlogGUI * blog, TweetGUI * tweet,
//          ChatGUI * chat, ScrapbookGUI * scrapbook):
//    ui(new Ui::MainMenu)
//{
//    profile_screen = profile;
//    blog_screen = blog;
//    tweet_screen = tweet;
//    chat_screen = chat;
//    sb_screen = scrapbook;
//    login_screen = login;

//    ui->setupUi(this);
//}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::init(){
    login_screen = new Login(this);
    profile_screen = new ProfileGUI(this);
    blog_screen = new BlogGUI(this);
    tweet_screen = new TweetGUI(this);
    chat_screen = new ChatGUI(this);
    sb_screen = new ScrapbookGUI(this);
}


void MainMenu::init(ProfileGUI * profile, BlogGUI * blog, TweetGUI * tweet,
          ChatGUI * chat, ScrapbookGUI * scrapbook){
    profile_screen = profile;
    blog_screen = blog;
    tweet_screen = tweet;
    chat_screen = chat;
    sb_screen = scrapbook;
}

System * MainMenu::getSystem(){
    return main_system;
}

Login * MainMenu::getLoginScreen(){
    return login_screen;
}

void MainMenu::on_pushButton_profile_clicked()
{
    profile_screen->show();
    this->close();
}

void MainMenu::on_pushButton_chat_clicked()
{
    chat_screen->show();
    this->close();
}

void MainMenu::on_pushButton_blog_clicked()
{
    blog_screen->show();
    this->close();
}

void MainMenu::on_pushButton_tweet_clicked()
{
    tweet_screen->show();
    this->close();
}

void MainMenu::on_pushButton_scrapbook_clicked()
{
    sb_screen->show();
    this->close();
}

void MainMenu::on_pushButton_signout_clicked()
{
    login_screen->show();
    this->close();
}
