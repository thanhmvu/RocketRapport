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
    // init posts section
    posts_widget = new QWidget();
    posts_layout = new QVBoxLayout();
    posts_widget->setLayout(posts_layout);
    ui->group_feed->setWidget(posts_widget);

    // init user list
    memlist = new QTextBrowser();
    ui->member_List->setWidget(memlist);
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
        ui->new_member_username->setVisible(true);
        ui->instruction->setVisible(true);

        ui->pushButton_show_about->setVisible(true);
        ui->pushButton_newPost->setVisible(true);
        ui->pushButton_add_member->setVisible(true);
    }
    else{
        ui->about_group->setVisible(true);
        ui->group_feed->setVisible(false);
        ui->new_member_username->setVisible(false);
        ui->instruction->setVisible(false);

        ui->pushButton_show_about->setVisible(false);
        ui->pushButton_newPost->setVisible(false);
        ui->pushButton_add_member->setVisible(false);
    }

    // load feed
    loadGroupFeed();

    // load member list
    loadMemberList();
}

void GroupGUI::loadGroupFeed(){
    // refresh posts_layout
    QLayoutItem *child;
    while ((child = posts_layout->takeAt(0)) != 0) {
        delete child;
    }
    delete posts_layout;
    delete posts_widget;

    posts_widget = new QWidget();
    posts_layout = new QVBoxLayout();
    posts_widget->setLayout(posts_layout);
    ui->group_feed->setWidget(posts_widget);


    // load blogs from database based on the blog owner
    this_group->retrieveAllPosts();
    std::vector<BlogPost*> blogPosts = this_group->getBlog()->getMyPosts();
    for(BlogPost * post: blogPosts) {
        displayPost(post);
    }
}

void GroupGUI::displayPost(BlogPost * post){
    QTextBrowser *browser = new QTextBrowser();
    browser->setMinimumHeight(120);

    QString content = post->getTimePosted().toString() + "\n" + "\n" + post->getText();
    browser->setText(content);

    posts_layout->addWidget(browser);
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
    // set visibilities
    ui->new_post->setVisible(false);
    ui->group_feed->setVisible(true);

    ui->pushButton_savePost->setVisible(false);
    ui->pushButton_cancelPost->setVisible(false);

    // save the post
    QString text = ui->new_post->toPlainText();
    QDateTime time = QDateTime::currentDateTime();
    int blogID = this_group->getBlog()->getBlogID();

    // create new post object
    BlogPost* post = new BlogPost(blogID,time,text);

    // add new post to database
    this_group->getBlog()->addPost(post);

    // display to screen
    displayPost(post);
}

void GroupGUI::on_pushButton_cancelPost_clicked()
{
    ui->new_post->setVisible(false);
    ui->group_feed->setVisible(true);

    ui->pushButton_savePost->setVisible(false);
    ui->pushButton_cancelPost->setVisible(false);
}

void GroupGUI::on_pushButton_add_member_clicked()
{
    QString username = ui->new_member_username->text();
    Account * newMember = main_menu->getSystem()->getAccountByUsername(username);
    if( newMember != nullptr ){
        // link group and account
        this_group->addGroupMember(newMember);
        // add the link to database
        main_menu->getSystem()->pairGroupWithUser(this_group,newMember);

        loadMemberList();
        ui->new_member_username->setText("New member added!");
    }else{
        ui->new_member_username->setText("#404: User not found!");
    }
}

void GroupGUI::loadMemberList(){
    QString content = "List of Members: \n \n";
    int i = 1;
    for(Account * acc: this_group->getGroupMembers()){
        content += QString::number(i) + ". " + acc->getUsername() + " \n" + " \n";
        i ++;
    }
    memlist->setText(content);
}
