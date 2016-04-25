#include "bloggui.h"
#include "ui_bloggui.h"

BlogGUI::BlogGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlogGUI)
{
    ui->setupUi(this);
    init();
}

BlogGUI::BlogGUI(ProfileGUI* pfGUI) :
    ui(new Ui::BlogGUI)
{
    ui->setupUi(this);
    profile_screen = pfGUI;
    init();
}

BlogGUI::~BlogGUI()
{
    delete ui;
}

void BlogGUI::init(){
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_savePost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);

    // init posts section
    posts_widget = new QWidget();
    posts_layout = new QVBoxLayout();
    posts_widget->setLayout(posts_layout);
    ui->scrollArea->setWidget(posts_widget);

    // TODO: display actual blog posts pulled from either system class or the database
    for(int i=0;i<5;i++) {
        // randomly generate text for illustration purpose
        QString text = "blog <b>post</b> ";
        for(int j=0;j<i+2;j++) text += text;

        QTextBrowser *browser = new QTextBrowser();
        browser->setMinimumHeight(120);
        browser->setText(text);

        posts_layout->addWidget(browser);
    }

}

void BlogGUI::on_pushButton_newPost_clicked()
{
    ui->pushButton_newPost->setVisible(false);
    ui->textEdit_newPost->setText("<i>Write your new blog post here</i>");
    ui->textEdit_newPost->setVisible(true);
    ui->pushButton_savePost->setVisible(true);
    ui->pushButton_cancel->setVisible(true);
}

void BlogGUI::on_pushButton_savePost_clicked()
{
    QString text = ui->textEdit_newPost->toPlainText();
    QDateTime time = QDateTime::currentDateTime();

    // create new post object
    BlogPost *post = new BlogPost();
    post->setText(text);
    post->setTimePosted(time);

    // add new post to database
    profile_screen->getProfileOwner()->getMyBlog()->addPost(post);

    // display to screen
    displayPost(post);

    // set other visibility
    ui->pushButton_savePost->setVisible(false);
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_newPost->setVisible(true);
}

void BlogGUI::displayPost(BlogPost * post){
    QTextBrowser *browser = new QTextBrowser();
    browser->setMinimumHeight(120);

    QString content = post->getTimePosted().toString() + "\n" + "\n" + post->getText();
    browser->setText(content);

    posts_layout->addWidget(browser);
}

void BlogGUI::on_pushButton_cancel_clicked()
{
    ui->pushButton_savePost->setVisible(false);
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_newPost->setVisible(true);
}

void BlogGUI::on_pushButton_back_to_profile_clicked()
{
    this->close();
    profile_screen->show();
}

void BlogGUI::loadBlogView(QString blog_owner, QString viewer){
    ui->label_myBlog->setText(blog_owner+"'s blog");

    ////////////////////////////////////////////////////////////////////
    /// load blogs from database
    //////////////////////////////////////////////////////////////////


    // check if current user is the owner of the profile

}
