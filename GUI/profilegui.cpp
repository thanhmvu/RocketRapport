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
    // reload main menu in case of new accounts or new groups
    main_menu->reload();

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

//    std::cout<< "BlogPost internal id_cnt value is: " << BlogPost::getIdCnt() << std::endl;
    System::printAllIdCnt();
}

void ProfileGUI::on_pushButton_tweet_clicked()
{
    // load content based on viewer
    tweet_screen->loadTweetView(owner->getUsername(), curr_viewer);

    this->close();
    tweet_screen->show();
}


void ProfileGUI::on_pushButton_update_about_clicked()
{
    ////////////////////////////////////////////////////////////////////
    /// Store new about to the database
    //////////////////////////////////////////////////////////////////
}


void ProfileGUI::on_pushButton_scrapbook_clicked()
{
    std::string path = main_menu->getSystem()->getHtmlPath();

    const QString dateFormat = "h:m ap MMMM d yyyy";
    std::ofstream scrapbookHTML;
    scrapbookHTML.open(path, std::ios::out | std::ios::trunc);
    scrapbookHTML   << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"
                    << "<html xmlns=\"http://www.w3.org/1999/xhtml\">"
                    << "<head>"
                    << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />"
                    << "<link rel=\"stylesheet\" type=\"text/css\" href=\"anoceanofsky.css\" />"
                    << "<title>"
                    << owner->getUsername().toStdString()
                    << "'s Scrapbook</title>"
                    << "</head>"
                    << "<body>"
                    << "<div id=\"mainPicture\">"
                    << "<div class=\"picture\">"
                    << "<div id=\"headerTitle\">"
                    << owner->getUsername().toStdString()
                    << "'s Scrapbook</div>"
                    << "</div>"
                    << "</div>"
                    << "<div class=\"contentBox\">"
                    << "<div class=\"innerBox\">"
                    << "<div class=\"contentTitle\">First Name</div>"
                    << "<div class=\"contentText\"><p>"
                    << owner->getFirstName().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Last Name</div>"
                    << "<div class=\"contentText\"><p>"
                    << owner->getLastName().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Gender</div>"
                    << "<div class=\"contentText\"><p>"
                    << owner->getGender().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Home Address</div>"
                    << "<div class=\"contentText\"><p>"
                    << owner->getAddress().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Most Recent Employer</div>"
                    << "<div class=\"contentText\"><p>"
                    << owner->getMostRecentEmployer().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Age</div>"
                    << "<div class=\"contentText\"><p>"
                    << owner->getAge()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Phone Number</div>"
                    << "<div class=\"contentText\"><p>"
                    << owner->getPhoneNumber()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">About Yourself</div>"
                    << "<div class=\"contentText\"><p>"
                    << owner->getAbout().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Tweets</div>"
                    << "<div class=\"contentText\"><p>";
    for (int i = 0; i < owner->getMyTweet()->getMyPosts().size(); i++) {
        std::string datetime = owner->getMyTweet()->getMyPosts()[i]->getTimePosted().toString(dateFormat).toStdString();
        std::string text = owner->getMyTweet()->getMyPosts()[i]->getText().toStdString();
        scrapbookHTML   << datetime
                        << "<br />"
                        << text
                        << "<br /><br />";
    }
    scrapbookHTML   << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Blog</div>"
                    << "<div class=\"contentText\"><p>";
    for (int i = 0; i < owner->getMyBlog()->getMyPosts().size(); i++) {
        std::string datetime = owner->getMyBlog()->getMyPosts()[i]->getTimePosted().toString(dateFormat).toStdString();
        std::string text = owner->getMyBlog()->getMyPosts()[i]->getText().toStdString();
        scrapbookHTML   << datetime
                        << "<br />"
                        << text
                        << "<br /><br />";
    }
    scrapbookHTML   << "</p><br /></div>"
                    << "</div>"
                    << "</div>"
                    << "</body>"
                    << "</html>";
    scrapbookHTML.close();
    system("firefox ../index.html");
}

Account * ProfileGUI::getProfileOwner(){
    return owner;
}
