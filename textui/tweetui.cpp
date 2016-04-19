#include "tweetui.h"

TweetUI::TweetUI()
{

}

void TweetUI::displayScreen() {
    mvprintw(1, 1, "On Tweet Screen");
    refresh();
}

void TweetUI::runScreen() {
    mvprintw(2, 1, "In Run Screen");
    refresh();
    getch();
}
