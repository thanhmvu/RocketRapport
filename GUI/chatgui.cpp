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
//    ui->scrollArea->setWidget(scroll_widget);

    // not working
    QScrollBar *v = ui->chat_box->verticalScrollBar();
    v->setSliderPosition(v->maximum());

}

void ChatGUI::on_pushButton_main_menu_clicked()
{
    main_menu->show();
    this->close();
}
