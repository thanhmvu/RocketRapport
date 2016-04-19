#include "profileui.h"

ProfileUI::ProfileUI()
{

}

void ProfileUI::displayScreen() {
    mvprintw(1, 1, "On Profile Screen");
    refresh();
}

void ProfileUI::runScreen() {
    mvprintw(2, 1, "In Run Screen");
    refresh();
    getch();
}
