#include "tweetui.h"

TweetUI::TweetUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}

void TweetUI::displayScreen() {
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
    tempsize += 9;
    tempsize /= 2;
    ss << "'s Tweets";
    mvprintw(1, (this->getCols()/2)-tempsize, ss.str().c_str());
    ss.str("");
    mvprintw(4, 1, "New Tweet:");
    mvprintw((this->getRows()/2), 1, "Former Posts:");
    mvprintw(this->getRows()-3, (this->getCols()/2)-4, "Main Menu");
    mvprintw(this->getRows()-1, 1, "Up, Down - Navigate Sections;  Left, Right - Scroll Posts;  Home - Post/Select");

    refresh();
}

void TweetUI::runScreen() {
    refresh();
    getch();
}


/**
 * @brief Clears the former tweets then prints the new former tweet.
 */
void TweetUI::printFormerTweets() {
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
            for (int m = 0; m < acc.second->getMyTweet()->getMyPosts().size(); m++) {
                if (q < 1) {
                    QString datetime = acc.second->getMyTweet()->getMyPosts()[m+scrollIndex]->getTimePosted().toString(dateFormat);
                    std::string text = acc.second->getMyTweet()->getMyPosts()[m+scrollIndex]->getText().toStdString();
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
