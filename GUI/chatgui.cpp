#include "chatgui.h"
#include "ui_chatgui.h"

ChatGUI::ChatGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatGUI)
{
    ui->setupUi(this);
}

ChatGUI::ChatGUI(MainMenu * mm) :
    ui(new Ui::ChatGUI)
{
    ui->setupUi(this);
    main_menu = mm;
    init();
}

ChatGUI::~ChatGUI()
{
    delete ui;
}

void ChatGUI::init(){

}
