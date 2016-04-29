#include "bloggui.h"
#include "ui_bloggui.h"

/**
 * @brief BlogGUI::BlogGUI default constructor
 */
BlogGUI::BlogGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlogGUI)
{
    ui->setupUi(this);
    init();
}

/**
 * @brief BlogGUI::BlogGUI constructor
 * @param pfGUI pointer to a ProfileGUI that is linked to this BlogGUI
 */
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
    Blog *blog = profile_screen->getProfileOwner()->getMyBlog();
    int blogID = blog->getBlogID();

    // create new post object
    BlogPost *post = new BlogPost(blogID,time,text);

    // add new post to database
    blog->addPost(post);

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
    // refresh posts_layout
    QLayoutItem *child;
    while ((child = posts_layout->takeAt(0)) != 0) {
        delete child;
    }
    delete posts_layout;
    delete posts_widget;

    posts_widget = new QWidget();
    posts_layout = new QVBoxLayout();
    posts_widget->setLayout(posts_layout);
    ui->scrollArea->setWidget(posts_widget);


    // set the blog's name
    ui->label_myBlog->setText(blog_owner+"'s blog");

    // load blogs from database based on the blog owner
    profile_screen->getProfileOwner()->retrieveAllBlogPosts();
    std::vector<BlogPost*> blogPosts = profile_screen->getProfileOwner()->getMyBlog()->getMyPosts();
    for(BlogPost * post: blogPosts) {
        displayPost(post);
    }

    // set visibility of features
    ui->pushButton_savePost->setVisible(false);
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    if(viewer.compare(blog_owner)== 0){
        ui->pushButton_newPost->setVisible(true);
    }else{
        ui->pushButton_newPost->setVisible(false);
    }

}
