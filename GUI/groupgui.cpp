#include "groupgui.h"
#include "ui_groupgui.h"

GroupGUI::GroupGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupGUI)
{
    ui->setupUi(this);
}

GroupGUI::~GroupGUI()
{
    delete ui;
}

GroupGUI::GroupGUI(MainMenu* mm) :
    ui(new Ui::GroupGUI)
{
    ui->setupUi(this);
    main_menu = mm;
    init();
}

void GroupGUI::init(){

}

void GroupGUI::loadGroup(QString groupname){

}

void GroupGUI::on_pushButton_mainmenu_clicked()
{
    this->close();
    main_menu->show();
}
