#include "chatgui.h"
#include "ui_chatgui.h"



/**
 * @brief default constructor that we don't reall use in this project
 */
ChatGUI::ChatGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatGUI)
{
    ui->setupUi(this);
}

/**
 * @brief constructor that is actually used
 */
ChatGUI::ChatGUI(MainMenu * mm) :
    ui(new Ui::ChatGUI)
{
    ui->setupUi(this);
    main_menu = mm;
    scroll_widget = new QWidget();
    layout = new QVBoxLayout();
    scroll_widget->setLayout(layout);
    ui->scrollArea_userList->setWidget(scroll_widget);

    isDisplaying = false;
//    refreshChatScreen();

    // constantly refresh chat screen
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(refreshChatScreen()));
    timer->start(1000);
}

/**
 * @brief
 */
ChatGUI::~ChatGUI()
{
    delete ui;
    delete timer;
    delete scroll_widget;
    delete layout;
    clearUserBox();
}

/**
 * @brief
 */
void ChatGUI::refreshChatScreen(){
    if(isDisplaying){
        curr_user = main_menu->getSystem()->getCurrentUser();
        if(curr_user != nullptr){
            // rebuild all chats
            curr_user->retrieveAllChats();

            // rebuild all messages
            curr_user->retrieveAllMessages();

            // display user list
            updateUserList();

            // check all chats for new messages and notify viewer
            std::vector<Chat*> chats = curr_user->getMyChats();
            QString noti = "New messages with:\n";
            for(Chat * chat: chats){
                int currNumOfMess = chat->getMessages().size();
                int lastNumOfMess = chatMap[chat->getTalkingToUser()];

                if(currNumOfMess > lastNumOfMess){ // got new messages
                    noti += (chat->getTalkingToUser() + "\n");
                    // update number of messages
                    chatMap[chat->getTalkingToUser()] = currNumOfMess;
                }
            }
            ui->notification->setText(noti);

            // check the current displayed chatmate to see if he/she sends new mess
            displayCurrentChat();
        }
    }
}

/**
 * @brief display the accounts as list of buttons
 */
void ChatGUI::updateUserList(){

    clearUserBox();

    for(auto pair: main_menu->getSystem()->getAllAccounts()){
        QString username = pair.first;
        QPushButton *button = new QPushButton();
        button->setText(username);
        button->setFixedWidth(150);
        layout->addWidget(button);
        connect(button,SIGNAL(clicked()),this,SLOT(openChat()));

        userList.push_back(button);
    }
}

/**
 * @brief
 */
void ChatGUI::clearUserBox(){
    while(!userList.empty()){
        delete userList.back();
        userList.pop_back();
    }
}

/**
 * @brief
 */
void ChatGUI::openChat(){
    // update the talking-to user
    QPushButton* button = qobject_cast<QPushButton*> (QObject::sender());
    QString other_username = button->text();
    talking_to_user = main_menu->getSystem()->getAccountByUsername(other_username);
    ui->name_tag->setText(other_username);

    // Load chat from DATABASE based on the current user and the other user
    displayCurrentChat();

    // Set chat_box scrollbar to the bottom (solution 1)
    QTextCursor c = ui->chat_box->textCursor();
    c.movePosition(QTextCursor::End);
    ui->chat_box->setTextCursor(c);
}

/**
 * @brief
 */
void ChatGUI::displayCurrentChat(){
    QString chat_text;
    if(talking_to_user != nullptr && curr_user != nullptr){
        Chat * chat = curr_user->getChatByPartnerName(talking_to_user->getUsername());
        if(chat != nullptr){
            // Display to screen
            for(Message * mess: chat->getMessages()){
                chat_text += (mess->getTimeSent().toString() + "\n" + mess->getText()+ "\n" + "\n");
            }
        }
    }
    ui->chat_box->setText(chat_text);

    // Set chat_box scrollbar to the bottom (solution 1)
    QTextCursor c = ui->chat_box->textCursor();
    c.movePosition(QTextCursor::End);
    ui->chat_box->setTextCursor(c);
}

/**
 * @brief
 */
void ChatGUI::autoUpdate(){
    ////////////////////////////////////////////////////////////////////
    /// SOME HOW UPDATE THE MESS CONSTANTLY
    /// and notice the user
    //////////////////////////////////////////////////////////////////

    // retrieve all accounts from the database


    // check all users to see if receive new mess from anybody

    // check the current displayed chatmate to see if he/she sends new mess

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

    // Set scrollbar to the bottom (solution 2)
    QScrollBar *v = ui->chat_box->verticalScrollBar();
    v->setValue(v->maximum());
}

/**
 * @brief
 */
void ChatGUI::on_pushButton_main_menu_clicked()
{
    isDisplaying = false;
    // reload main menu in case of new accounts or new groups
    main_menu->reload();

    this->close();
    main_menu->show();
}

void ChatGUI::setIsDisplaying(bool state){
    isDisplaying = state;
}
