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
    // load the list of all users
    updateUserList();

    // load all mess
    updateChatBox();

    // Set chat_box scrollbar to the bottom (solution 1)
    QTextCursor c = ui->chat_box->textCursor();
    c.movePosition(QTextCursor::End);
    ui->chat_box->setTextCursor(c);


}

void ChatGUI::updateUserList(){
    ////////////////////////////////////////////////////////////////////
    /// Load list of user name from SYSTEM/ DATABASE
    /// Display to screen
    //////////////////////////////////////////////////////////////////

    // get a list of usernames from DATABASE
    std::vector<QString> userList;
    userList.push_back("asd");
    userList.push_back("zxc");
    userList.push_back("qwe");

    // display the list of users as a list of openChat buttons
    QVBoxLayout *layout = new QVBoxLayout();
    for(QString username: userList){
        QPushButton *button = new QPushButton();
        button->setText(username);
        layout->addWidget(button);
        connect(button,SIGNAL(clicked()),this,SLOT(openChat()));
    }
    ui->scrollArea_userList->setLayout(layout);
}

void ChatGUI::openChat(){
//    QObject* button = QObject::sender();
    QPushButton* button = qobject_cast<QPushButton*> (QObject::sender());
    std::cout<<"Open test chat: " << button->text().toStdString() << "\n";
}

void ChatGUI::updateChatBox(){
    ////////////////////////////////////////////////////////////////////
    /// SOME HOW UPDATE THE MESS CONSTANTLY
    //////////////////////////////////////////////////////////////////

//    // display current blog posts
//    QWidget *scroll_widget = new QWidget();
//    QVBoxLayout *layout = new QVBoxLayout();

//    // TODO: display actual blog posts pulled from either system class or the database
//    for(int i=0;i<6;i++) {
//        // randomly generate text for illustration purpose
//        QString text = "blog <b>post</b> ";
//        for(int j=0;j<i+2;j++) text += text;

//        QTextBrowser *browser = new QTextBrowser();
//        browser->setMinimumHeight(120);
//        browser->setText(text);

//        layout->addWidget(browser);
//    }

//    scroll_widget->setLayout(layout);
//    ui->scrollArea_userList->setWidget(scroll_widget);
}

void ChatGUI::on_pushButton_main_menu_clicked()
{
    this->close();
    main_menu->show();
}

void ChatGUI::on_pushButton_send_mess_clicked()
{
    ////////////////////////////////////////////////////////////////////
    /// STORE NEW MESS TO DB
    /// NEW MESS SHOULD BE automaticall display via updateChatBox
    //////////////////////////////////////////////////////////////////


    // Set scrollbar to the bottom (solution 2)
    QScrollBar *v = ui->chat_box->verticalScrollBar();
    v->setValue(v->maximum());
}
