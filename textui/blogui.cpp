#include "blogui.h"

BlogUI::BlogUI()
{

}

void BlogUI::displayScreen() {
    mvprintw(1, 1, "On Blog Screen");
    refresh();
}

void BlogUI::runScreen() {
    mvprintw(2, 1, "In Run Screen");
    refresh();
    getch();
}
