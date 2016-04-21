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
