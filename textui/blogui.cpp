#include "blogui.h"

BlogUI::BlogUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void BlogUI::displayScreen() {
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(0, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(2, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw((this->getRows()/2)-1, i, "-");
    }
    for (int i = 0; i < this->getCols(); i++) {
        mvprintw(this->getRows()-2, i, "-");
    }
    ss << this->getSystem()->getCurrentUser()->getBlogTweetUsername();
    int tempsize = this->getSystem()->getCurrentUser()->getBlogTweetUsername().size();
    tempsize += 7;
    tempsize /= 2;
    ss << "'s Blog";
    mvprintw(1, (this->getCols()/2)-tempsize, ss.str().c_str());
    ss.str("");
    mvprintw(4, 1, "New Post:");
    mvprintw((this->getRows()/2), 1, "Former Posts:");
    mvprintw(this->getRows()-3, (this->getCols()/2)-4, "Main Menu");
    mvprintw(this->getRows()-1, 1, "Up, Down - Navigate Sections;  Left, Right - Scroll Posts;  Home - Post/Select");

    refresh();
}

void BlogUI::runScreen() {
    int npY = 5, npX = 0;
    int fpY = (this->getRows()/2)+2, fpX = 0;

    getch();


    this->getSystem()->getCurrentUser()->setBlogTweetUsername(this->getSystem()->getCurrentUser()->getUsername().toStdString());
    this->changeScreens(false);
    clear();
    refresh();
}
