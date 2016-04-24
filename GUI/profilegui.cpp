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
    this->close();
    main_menu->show();
}

void ProfileGUI::loadProfile(QString username){

    Account * curr_user = main_menu->getSystem()->getCurrentUser();
    // display full name
    std::string user_fullname = curr_user->getFirstName() + " " + curr_user->getLastName();
    ui->label_name->setText(QString::fromStdString(user_fullname));

    // display username
    ui->label_username->setText(QString::fromStdString(curr_user->getUsername()));

    // display about-you section
    ui->about_section->setText("About me:\n" + QString::fromStdString(curr_user->getAbout()));

    ////////////////////////////////////////////////////////////////////
    /// Check if current user is the owner of the profile
    //////////////////////////////////////////////////////////////////
//    QString current_user = QString::fromStdString(main_menu->getSystem()->getCurrentUser()->getUsername());
//    if(username.compare(current_user) == 0){
//        // allow edit profile
//    }

}

void ProfileGUI::on_pushButton_blog_clicked()
{
    ////////////////////////////////////////////////////////////////////
    /// BUG in retrieve current user
    //////////////////////////////////////////////////////////////////
//    Account * current_user = main_menu->getSystem()->getCurrentUser();
//    // load content based on viewer
//    blog_screen->loadBlogView(QString::fromStdString(current_user->getUsername()));

    this->close();
    blog_screen->show();
}

void ProfileGUI::on_pushButton_tweet_clicked()
{
    ////////////////////////////////////////////////////////////////////
    /// BUG in retrieve current user
    //////////////////////////////////////////////////////////////////
//    Account * current_user = main_menu->getSystem()->getCurrentUser();
//    // load content based on viewer
//    tweet_screen->loadTweetView(QString::fromStdString(current_user->getUsername()));

    this->close();
    tweet_screen->show();
}

void ProfileGUI::on_pushButton_scrapbook_clicked()
{
    //TODO: OPEN SCRAPBOOK AS HTML FILE
}
