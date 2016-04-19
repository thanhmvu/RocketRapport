#include "tweetgui.h"
#include "ui_tweetgui.h"

TweetGUI::TweetGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TweetGUI)
{
    ui->setupUi(this);
    init();
}

TweetGUI::TweetGUI(MainMenu * mm) :
    ui(new Ui::TweetGUI)
{
    ui->setupUi(this);
    main_menu = mm;
    init();
}

TweetGUI::~TweetGUI()
{
    delete ui;
}

void TweetGUI::init(){

}
