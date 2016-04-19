#include "chatui.h"

ChatUI::ChatUI()
{

}

void ChatUI::displayScreen() {
    mvprintw(1, 1, "On Chat Screen");
    refresh();
}

void ChatUI::runScreen() {
    mvprintw(2, 1, "In Run Screen");
    refresh();
    getch();
}
