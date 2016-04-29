#include "blogui.h"

BlogUI::BlogUI(System* mainSystem)
{
    this->setSystem(mainSystem);
    this->scrollIndex = 0;
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
    int npY = 5, npX = 1;
    int fpY = (this->getRows()/2)+1, fpX = 1;
    int mmY = this->getRows()-3, mmX = (this->getCols()/2)-5;
    std::stringstream npss;
    int rowIndex = 0;
    int curY = 5, curX = 1;

    this->printFormerPosts();

    curs_set(1);
    move(npY, npX);
    refresh();

    int keyPress;
    while(this->getChangeScreens() == false) {
        getyx(stdscr, curY, curX);
        keyPress = getch();
        switch(keyPress) {
        case KEY_UP: // Switch screen sections
            switch(rowIndex) {
            case 0:
                curs_set(0);
                move(mmY, mmX);
                printw(">");
                move(mmY, mmX);
                rowIndex = 2;
                break;
            case 1:
                move(npY, npX);
                rowIndex = 0;
                break;
            case 2:
                curs_set(1);
                move(mmY, mmX);
                printw(" ");
                move(fpY, fpX);
                rowIndex = 1;
                break;
            }
            break;
        case KEY_DOWN: // Switch screen sections
            switch(rowIndex) {
            case 0:
                move(fpY, fpX);
                rowIndex = 1;
                break;
            case 1:
                curs_set(0);
                move(mmY, mmX);
                printw(">");
                move(mmY, mmX);
                rowIndex = 2;
                break;
            case 2:
                curs_set(1);
                move(mmY, mmX);
                printw(" ");
                move(npY, npX);
                rowIndex = 0;
                break;
            }
            break;
        case KEY_LEFT: // Scroll former posts
            if (scrollIndex > 0) {
                scrollIndex--;
            }
            this->printFormerPosts();
            break;
        case KEY_RIGHT: // Scroll former posts
            for(const auto &acc: this->getSystem()->getAllAccounts()) {
                if (acc.first.toStdString() == this->getSystem()->getCurrentUser()->getBlogTweetUsername()) {
                    int temp = ((acc.second->getMyBlog()->getMyPosts().size())-1)-scrollIndex;
                    if (temp > 0) {
                        scrollIndex++;
                    }
                }
            }
            this->printFormerPosts();
            break;
        case KEY_HOME: // Post/Select option
            switch(rowIndex) {
            case 0: // User posts





                break;
            case 1:
                move(curY, curX);
                break;
            case 2:
                this->screenNumber = 1;
                this->changeScreens(true);
                break;
            }
            break;
        case KEY_BACKSPACE: // Backspace when typing
            switch(rowIndex) {
            case 0: // Deletes a character

                break;
            case 1:
                move(curY, curX);
                break;
            case 2:
                move(curY, curX);
                break;
            }
            break;
        case '\n' :
            move(curY, curX);
            break;
        default: // Typing characters for a post
            switch(rowIndex) {
            case 0: // Types a character

                break;
            case 1:
                move(curY, curX);
                break;
            case 2:
                move(curY, curX);
                break;
            }
            break;
        }
    }


    this->getSystem()->getCurrentUser()->setBlogTweetUsername(this->getSystem()->getCurrentUser()->getUsername().toStdString());
    this->changeScreens(false);
    clear();
    refresh();
}


/**
 * @brief Clears the former posts then prints the new former post.
 */
void BlogUI::printFormerPosts() {
    std::stringstream sstemp;
    int q = 0;
    const QString dateFormat = "h:m ap MMMM d yyyy";
    for (int i = (this->getRows()/2)+1; i < this->getRows()-3; i++) {
        for (int j = 0; j < this->getCols(); j++) {
            mvprintw(i, j, " ");
        }
    }
    for(const auto &acc: this->getSystem()->getAllAccounts()) {
        if (acc.first.toStdString() == this->getSystem()->getCurrentUser()->getBlogTweetUsername()) {
            for (int m = 0; m < acc.second->getMyBlog()->getMyPosts().size(); m++) {
                if (q < 1) {
                    QString datetime = acc.second->getMyBlog()->getMyPosts()[m+scrollIndex]->getTimePosted().toString(dateFormat);
                    std::string text = acc.second->getMyBlog()->getMyPosts()[m+scrollIndex]->getText().toStdString();
                    sstemp << datetime.toStdString();
                    mvprintw((this->getRows()/2)+1, 1, sstemp.str().c_str());
                    sstemp.str("");
                    refresh();
                    int x = 0;
                    int y = 0;
                    for (int a = 0; a < text.size(); a++) {
                        sstemp << text[a];
                        mvprintw(((this->getRows()/2)+2)+y, 1+x, sstemp.str().c_str());
                        sstemp.str("");
                        if (x == this->getCols()) {
                            y++;
                            x = 0;
                        } else {
                            x++;
                        }
                    }
                    q++;
                    refresh();
                }
            }
        }
    }
}
