#include "tweetgui.h"
#include "ui_tweetgui.h"

TweetGUI::TweetGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TweetGUI)
{
    ui->setupUi(this);
}

TweetGUI::~TweetGUI()
{
    delete ui;
}
