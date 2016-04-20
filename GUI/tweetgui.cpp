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

}
