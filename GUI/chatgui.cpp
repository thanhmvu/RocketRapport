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
    // load the list of all users to the
    updateUserList();

    updateChatBox();

    // Set chat_box scrollbar to the bottom (solution 1)
    QTextCursor c = ui->chat_box->textCursor();
    c.movePosition(QTextCursor::End);
    ui->chat_box->setTextCursor(c);
}

void ChatGUI::updateUserList(){
//        // display current blog posts
//        QWidget *scroll_widget = new QWidget();
//        QVBoxLayout *layout = new QVBoxLayout();

//        // TODO: display actual blog posts pulled from either system class or the database
//        for(int i=0;i<6;i++) {
//            // randomly generate text for illustration purpose
//            QString text = "blog <b>post</b> ";
//            for(int j=0;j<i+2;j++) text += text;

//             *browser = new QTextBrowser();
//            browser->setMinimumHeight(120);
//            browser->setText(text);

//            layout->addWidget(browser);
//        }

        // try this and try pushbutton
//        QCommandLinkButton *slotButtons[10];
//        QVBoxLayout* layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
//        for(int i=0; i < 5; i++)
//        {
//            slotButtons[i] = new QCommandLinkButton;
//            slotButtons[i]->setText(slotQuery.value(0).toString());
//            slotButtons[i]->setDescription(slotQuery.value(1).toString());
//            ui->scrollAreaWidgetContents->layout()->addWidget(slotButtons[i]);
//        }

//        scroll_widget->setLayout(layout);
//        ui->scrollArea_userList->setWidget(scroll_widget);
}

void ChatGUI::updateChatBox(){
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
    main_menu->show();
    this->close();
}

void ChatGUI::on_pushButton_send_mess_clicked()
{
    // Set scrollbar to the bottom (solution 2)
    QScrollBar *v = ui->chat_box->verticalScrollBar();
    v->setValue(v->maximum());
}
