#include "tweetgui.h"
#include "ui_tweetgui.h"

TweetGUI::TweetGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TweetGUI)
{
    ui->setupUi(this);
    init();
}

TweetGUI::TweetGUI(ProfileGUI * pf_scrn) :
    ui(new Ui::TweetGUI)
{
    ui->setupUi(this);
    profile_screen = pf_scrn;
    init();
}

TweetGUI::~TweetGUI()
{
    delete ui;
}

void TweetGUI::init(){
    ui->textEdit_newPost_2->setVisible(false);
    ui->pushButton_savePost_2->setVisible(false);
    ui->pushButton_cancel->setVisible(false);

    // display current blog posts
    QWidget *scroll_widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    // TODO: display actual blog posts pulled from either system class or the database
    for(int i=0;i<6;i++) {
        // randomly generate text for illustration purpose
        QString text = "tweet <b>post</b> ";
        for(int j=0;j<i;j++) text += text;

        QTextBrowser *browser = new QTextBrowser();
        browser->setMinimumHeight(60);
        browser->setText(text);

        layout->addWidget(browser);
    }

    scroll_widget->setLayout(layout);
    ui->scrollArea_2->setWidget(scroll_widget);
}

void TweetGUI::on_pushButton_cancel_clicked()
{
    ui->pushButton_savePost_2->setVisible(false);
    ui->textEdit_newPost_2->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_newPost_2->setVisible(true);
}

void TweetGUI::on_pushButton_savePost_2_clicked()
{
    ui->pushButton_savePost_2->setVisible(false);
    ui->textEdit_newPost_2->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_newPost_2->setVisible(true);
}

void TweetGUI::on_pushButton_newPost_2_clicked()
{
    ui->pushButton_newPost_2->setVisible(false);
    ui->textEdit_newPost_2->setVisible(true);
    ui->pushButton_savePost_2->setVisible(true);
    ui->pushButton_cancel->setVisible(true);
}

void TweetGUI::on_pushButton_back_to_profile_clicked()
{
    this->close();
    profile_screen->show();
}
