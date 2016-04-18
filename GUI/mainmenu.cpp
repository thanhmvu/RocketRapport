#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

MainMenu::MainMenu(ProfileGUI * profile, BlogGUI * blog, TweetGUI * tweet,
          ChatGUI * chat, ScrapbookGUI * scrapbook):
    ui(new Ui::MainMenu)
{
    profile_screen = profile;
    blog_screen = blog;
    tweet_screen = tweet;
    chat_screen = chat;
    sb_screen = scrapbook;

    ui->setupUi(this);
}

void MainMenu::init(ProfileGUI * profile, BlogGUI * blog, TweetGUI * tweet,
          ChatGUI * chat, ScrapbookGUI * scrapbook){
    profile_screen = profile;
    blog_screen = blog;
    tweet_screen = tweet;
    chat_screen = chat;
    sb_screen = scrapbook;
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
