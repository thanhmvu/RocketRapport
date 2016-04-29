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

void GroupGUI::loadGroup(QString groupname, QString viewer){
    this_group = main_menu->getSystem()->getGroupByName(groupname);
    curr_viewer = viewer;

    // display group name
    ui->label_groupname->setText(groupname);

    // display about-group section
    ui->about_group->setText("About us:\n" + this_group->getAboutGroup());

    // set festures' visibility
    ui->new_post->setVisible(false);
    ui->pushButton_mainmenu->setVisible(true);
    ui->pushButton_savePost->setVisible(false);
    ui->pushButton_cancelPost->setVisible(false);

    if(this_group->isMember(curr_viewer)){
        ui->about_group->setVisible(false);
        ui->group_feed->setVisible(true);

        ui->pushButton_show_about->setVisible(true);
        ui->pushButton_newPost->setVisible(true);
    }
    else{
        ui->about_group->setVisible(true);
        ui->group_feed->setVisible(false);

        ui->pushButton_show_about->setVisible(false);
        ui->pushButton_newPost->setVisible(false);
    }
}

void GroupGUI::on_pushButton_mainmenu_clicked()
{
    // reload main menu in case of new accounts or new groups
    main_menu->reload();

    this->close();
    main_menu->show();
}

void GroupGUI::on_pushButton_newPost_clicked()
{
    ui->new_post->setText("<i>Write your new group post here</i>");
    ui->new_post->setVisible(true);

    ui->pushButton_savePost->setVisible(true);
    ui->pushButton_cancelPost->setVisible(true);
}

void GroupGUI::on_pushButton_show_about_clicked()
{
    if(!ui->about_group->isVisible()){
        ui->about_group->setVisible(true);
        ui->group_feed->setVisible(false);
    }else{
        ui->about_group->setVisible(false);
        ui->group_feed->setVisible(true);
    }
    ui->new_post->setVisible(false);
}

void GroupGUI::on_pushButton_savePost_clicked()
{
    ui->new_post->setVisible(false);
    ui->group_feed->setVisible(true);

    ui->pushButton_savePost->setVisible(false);
    ui->pushButton_cancelPost->setVisible(false);

    /// save the thing and display
}

void GroupGUI::on_pushButton_cancelPost_clicked()
{
    ui->new_post->setVisible(false);
    ui->group_feed->setVisible(true);

    ui->pushButton_savePost->setVisible(false);
    ui->pushButton_cancelPost->setVisible(false);
}
