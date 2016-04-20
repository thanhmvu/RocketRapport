#include "profilegui.h"
#include "ui_profilegui.h"

ProfileGUI::ProfileGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileGUI)
{
    ui->setupUi(this);
    init();
}

ProfileGUI::ProfileGUI(MainMenu * mm) :
    ui(new Ui::ProfileGUI)
{
    ui->setupUi(this);
    main_menu = mm;
    init();
}

void ProfileGUI::init(){
    blog_screen = new BlogGUI(this);
    tweet_screen = new TweetGUI(this);
}

ProfileGUI::~ProfileGUI()
{
    delete ui;
}

void ProfileGUI::setMainMenu(MainMenu* mm){
    main_menu = mm;
}

void ProfileGUI::on_pushButton_back_to_menu_clicked()
{
    main_menu->show();
    this->close();
}

void ProfileGUI::loadProfile(){
    Account * curr_user = main_menu->getSystem()->getCurrentUser();
    std::string user_fullname = curr_user->getFirstName()
            + " " + curr_user->getLastName();
    ui->label_name->setText(QString::fromStdString(user_fullname));
}

void ProfileGUI::on_pushButton_blog_clicked()
{
    blog_screen->show();
    this->close();
}

void ProfileGUI::on_pushButton_tweet_clicked()
{
    tweet_screen->show();
    this->close();
}

void ProfileGUI::on_pushButton_scrapbook_clicked()
{
    //TODO: OPEN SCRAPBOOK AS HTML FILE
}
