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
    refreshChatScreen();
}

ChatGUI::~ChatGUI()
{
    delete ui;
}

void ChatGUI::refreshChatScreen(){
    // load the list of all users from database
    updateUserList();

    // update current user
    curr_user = main_menu->getSystem()->getCurrentUser();

    // Set chat_box scrollbar to the bottom (solution 1)
    QTextCursor c = ui->chat_box->textCursor();
    c.movePosition(QTextCursor::End);
    ui->chat_box->setTextCursor(c);

}

void ChatGUI::updateUserList(){
    // retrieve all accounts from the database
    main_menu->getSystem()->refreshSystem();

    // and display the accounts as list of buttons
    QWidget *scroll_widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();
    for(auto pair: main_menu->getSystem()->getAllAccounts()){
        QString username = pair.first;
        QPushButton *button = new QPushButton();
        button->setText(username);
        button->setFixedWidth(150);
        layout->addWidget(button);
        connect(button,SIGNAL(clicked()),this,SLOT(openChat()));
    }
    scroll_widget->setLayout(layout);
    ui->scrollArea_userList->setWidget(scroll_widget);
}

void ChatGUI::openChat(){
    // update the talking-to user
    QPushButton* button = qobject_cast<QPushButton*> (QObject::sender());
    QString other_username = button->text();
    talking_to_user = main_menu->getSystem()->getAccountByUsername(other_username);
    ui->name_tag->setText(other_username);


    // Load chat from DATABASE based on the current user and the other user
    Chat * chat = curr_user->getChatByPartnerName(other_username);
    if(chat != nullptr){
        // Display to screen
        QString chat_text;
        for(Message * mess: chat->getMessages()){
            chat_text += (mess->getTimeSent().toString() + "\n" + mess->getText()+ "\n" + "\n");
        }
        ui->chat_box->setText(chat_text);
    }
}

void ChatGUI::autoUpdate(){
    ////////////////////////////////////////////////////////////////////
    /// SOME HOW UPDATE THE MESS CONSTANTLY
    /// and notice the user
    //////////////////////////////////////////////////////////////////

    // check all users to see if receive new mess from anybody

    // check the current displayed chatmate to see if he/she sends new mess


    // Set scrollbar to the bottom (solution 2)
    QScrollBar *v = ui->chat_box->verticalScrollBar();
    v->setValue(v->maximum());
}

/**
 * @brief This method stores new mess to db
 *
 * It should not be worried with displaying the new messages
 * because all messages from the database
 * should be displayed somewhat automatically by other method
 */
void ChatGUI::on_pushButton_send_mess_clicked()
{
    if(talking_to_user != nullptr){
        // obtain info from the screen
        QString text = ui->input_message->toPlainText();
        QDateTime time = QDateTime::currentDateTime();

        // get current chat
        Chat * curr_chat = curr_user->getChatByPartnerName(talking_to_user->getUsername());
        if(curr_chat == nullptr){ // if a chat between this 2 does not exist
            // create one chat for current user
            curr_chat = new Chat(talking_to_user->getUsername(),main_menu->getSystem()->getDbm());
            curr_user->addChat(curr_chat);

            // create another for the talking-to user
            Chat* newChat2 = new Chat(curr_user->getUsername(),main_menu->getSystem()->getDbm());
            talking_to_user->addChat(newChat2);
        }
        // create and add mess to current user
        Message * mess = new Message(time,text);
        curr_chat->sendMessage(mess);

        // create and add mess to the other
        Message * mess2 = new Message(time,text);
        talking_to_user->getChatByPartnerName(curr_user->getUsername())->sendMessage(mess2);
    }
}

void ChatGUI::on_pushButton_main_menu_clicked()
{
    // reload main menu in case of new accounts or new groups
    main_menu->reload();

    this->close();
    main_menu->show();
}
