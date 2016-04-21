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

    // display current blog posts
    QWidget *scroll_widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    // TODO: display actual blog posts pulled from either system class or the database
    for(int i=0;i<6;i++) {
        // randomly generate text for illustration purpose
        QString text = "blog <b>post</b> ";
        for(int j=0;j<i+2;j++) text += text;

        QTextBrowser *browser = new QTextBrowser();
        browser->setMinimumHeight(120);
        browser->setText(text);

        layout->addWidget(browser);
    }

    scroll_widget->setLayout(layout);
    ui->scrollArea->setWidget(scroll_widget);
}

void BlogGUI::on_pushButton_newPost_clicked()
{
    ui->pushButton_newPost->setVisible(false);
    ui->textEdit_newPost->setVisible(true);
    ui->pushButton_savePost->setVisible(true);
    ui->pushButton_cancel->setVisible(true);
}

void BlogGUI::on_pushButton_savePost_clicked()
{
    ui->pushButton_savePost->setVisible(false);
    ui->textEdit_newPost->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_newPost->setVisible(true);

    // TODO: add new post to the system and display
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

void BlogGUI::loadViewForUser(int viewerID){

}
