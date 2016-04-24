#include "profilegui.h"
#include "ui_profilegui.h"

ProfileGUI::ProfileGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileGUI)
{
    ui->setupUi(this);
}

ProfileGUI::ProfileGUI(MainMenu * mm) :
    ui(new Ui::ProfileGUI)
{
    ui->setupUi(this);
    main_menu = mm;

    blog_screen = new BlogGUI(this);
    tweet_screen = new TweetGUI(this);

    ui->about_section->setReadOnly(true);
    ui->pushButton_update_about->setVisible(false);

    init();
}

void ProfileGUI::init(){
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

void ProfileGUI::loadProfile(QString ownername, QString viewer){
    this->owner = main_menu->getSystem()->getAccountByUsername(ownername);
    this->curr_viewer = viewer;

    // display full name
    QString owner_fullname = owner->getFirstName() + " " + owner->getLastName();
    ui->label_name->setText(owner_fullname);

    // display username
    ui->label_username->setText(owner->getUsername());

    // display about-you section
    ui->about_section->setText("About me:\n" + owner->getAbout());

    // Check if current user is the owner of the profile;
    if(owner->getUsername().compare(viewer) == 0){
       ui->about_section->setReadOnly(false);
       ui->pushButton_update_about->setVisible(true);
    }else{
        ui->about_section->setReadOnly(true);
        ui->pushButton_update_about->setVisible(false);
    }
}

void ProfileGUI::on_pushButton_blog_clicked()
{
    // load content based on viewer
    blog_screen->loadBlogView(owner->getUsername(), curr_viewer);

    this->close();
    blog_screen->show();
}

void ProfileGUI::on_pushButton_tweet_clicked()
{
//    Account * current_user = main_menu->getSystem()->getCurrentUser();
//    // load content based on viewer
//    tweet_screen->loadTweetView(QString::fromStdString(current_user->getUsername()));

    this->close();
    tweet_screen->show();
}

void ProfileGUI::on_pushButton_scrapbook_clicked()
{
    ////////////////////////////////////////////////////////////////////
    /// TODO: OPEN SCRAPBOOK AS HTML FILE
    //////////////////////////////////////////////////////////////////
}

void ProfileGUI::on_pushButton_update_about_clicked()
{
    ////////////////////////////////////////////////////////////////////
    /// Store new about to the database
    //////////////////////////////////////////////////////////////////
}
