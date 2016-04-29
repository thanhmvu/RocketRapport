#include "tweetgui.h"
#include "ui_tweetgui.h"

TweetGUI::TweetGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TweetGUI)
{
    ui->setupUi(this);
    init();
}

TweetGUI::TweetGUI(ProfileGUI * pfGUI) :
    ui(new Ui::TweetGUI)
{
    ui->setupUi(this);
    profile_screen = pfGUI;
    init();
}

TweetGUI::~TweetGUI()
{
    delete ui;
}

void TweetGUI::init(){
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_savePost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);

    // init posts section
    posts_widget = new QWidget();
    posts_layout = new QVBoxLayout();
    posts_widget->setLayout(posts_layout);
    ui->scrollArea->setWidget(posts_widget);
}

void TweetGUI::loadTweetView(QString owner, QString viewer){
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


    // set the tweet's name
    ui->label_myTweet->setText(owner+"'s tweet");

    // load tweets from database based on the tweet owner
    profile_screen->getProfileOwner()->retrieveAllTweets();
    std::vector<TweetPost*> tweetPosts = profile_screen->getProfileOwner()->getMyTweet()->getMyPosts();
    for(TweetPost * post: tweetPosts) {
        displayPost(post);
    }

    // set visibility of features
    ui->pushButton_savePost->setVisible(false);
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    if(viewer.compare(owner)== 0){
        ui->pushButton_newPost->setVisible(true);
    }else{
        ui->pushButton_newPost->setVisible(false);
    }

}

void TweetGUI::on_pushButton_cancel_clicked()
{
    ui->pushButton_savePost->setVisible(false);
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_newPost->setVisible(true);
}

void TweetGUI::on_pushButton_savePost_clicked()
{
    QString text = ui->textEdit_newPost->toPlainText();
    QDateTime time = QDateTime::currentDateTime();
    Tweet *tweet = profile_screen->getProfileOwner()->getMyTweet();
    int tweetID = tweet->getTweetID();

    // create new post object
    TweetPost *post = new TweetPost(tweetID,time,text);

    // add new post to database
    tweet->addPost(post);

    // display to screen
    displayPost(post);

    // set other visibility
    ui->pushButton_savePost->setVisible(false);
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_newPost->setVisible(true);
}

void TweetGUI::on_pushButton_newPost_clicked()
{
    ui->pushButton_newPost->setVisible(false);
    ui->textEdit_newPost->setText("<i>Write your new tweet here</i>");
    ui->textEdit_newPost->setVisible(true);
    ui->pushButton_savePost->setVisible(true);
    ui->pushButton_cancel->setVisible(true);
}

void TweetGUI::on_pushButton_back_to_profile_clicked()
{
    this->close();
    profile_screen->show();
}

void TweetGUI::displayPost(TweetPost * post){
    QTextBrowser *browser = new QTextBrowser();
    browser->setMinimumHeight(120);

    QString content = post->getTimePosted().toString() + "\n" + "\n" + post->getText();
    browser->setText(content);

    posts_layout->addWidget(browser);
}


