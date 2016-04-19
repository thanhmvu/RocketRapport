#include "scrapbookgui.h"
#include "ui_scrapbookgui.h"

ScrapbookGUI::ScrapbookGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrapbookGUI)
{
    ui->setupUi(this);
}

ScrapbookGUI::ScrapbookGUI(MainMenu * mm) :
    ui(new Ui::ScrapbookGUI)
{
    ui->setupUi(this);
    main_menu = mm;
    init();
}

ScrapbookGUI::~ScrapbookGUI()
{
    delete ui;
}

void ScrapbookGUI::init(){

}
