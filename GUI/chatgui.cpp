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
//    curr_user = main_menu->getSystem()->getCurrentUser();

    // load the list of all users
    updateUserList();

    // Set chat_box scrollbar to the bottom (solution 1)
    QTextCursor c = ui->chat_box->textCursor();
    c.movePosition(QTextCursor::End);
    ui->chat_box->setTextCursor(c);

}

void ChatGUI::updateUserList(){
    ////////////////////////////////////////////////////////////////////
    /// Load list of user name from SYSTEM/ DATABASE
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
    QPushButton* button = qobject_cast<QPushButton*> (QObject::sender());
    QString other_username = button->text();
//    the_other_user = main_menu->getSystem()->getAccountByUsername(other_username);

    ////////////////////////////////////////////////////////////////////
    /// Load chat from DATABASE based on the current user and the other user
    /// and display to screen
    //////////////////////////////////////////////////////////////////
//    std::cout<< curr_user->getUsername()<<" opened a chat with " << other_username.toStdString() << "\n";
}

void ChatGUI::autoUpdate(){
    ////////////////////////////////////////////////////////////////////
    /// SOME HOW UPDATE THE MESS CONSTANTLY
    /// and notice the user
    //////////////////////////////////////////////////////////////////

    // check all users to see if receive new mess from anybody

    // check the current displayed chatmate to see if he/she sends new mess
}

void ChatGUI::on_pushButton_send_mess_clicked()
{
    ////////////////////////////////////////////////////////////////////
    /// STORE NEW MESS TO DB
    /// NEW MESS SHOULD BE automatically display via updateChatBox
    //////////////////////////////////////////////////////////////////

    // get the new message
    // NOT WORKING!!
    std::cout<< ui->input_message->toPlainText().toStdString();

    // concatenate new mess to the current mess history

    // display to screen

    // store to DATABASE



    // Set scrollbar to the bottom (solution 2)
    QScrollBar *v = ui->chat_box->verticalScrollBar();
    v->setValue(v->maximum());
}

void ChatGUI::on_pushButton_main_menu_clicked()
{
    this->close();
    main_menu->show();
}
