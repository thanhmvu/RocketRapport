#include "scrapbookui.h"

ScrapbookUI::ScrapbookUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}


/**
 * @brief Sets up the design of the screen.
 */
void ScrapbookUI::displayScreen() {
    mvprintw((this->getRows()/2)-4, (this->getCols()/2)-9, "Viewing Scrapbook");
    mvprintw((this->getRows()/2)+1, (this->getCols()/2)-5, "MainMenu");
    mvprintw((this->getRows()/2)+1, (this->getCols()/2)-6, ">");
    refresh();
}


/**
 * @brief Loops through this method while the user is on this screen.
 */
void ScrapbookUI::runScreen() {
    std::string html_path = this->getSystem()->getHtmlPath();

    curs_set(0);
    int curY = (this->getRows()/2)+1, curX = (this->getCols()/2)-6;
    this->viewMyScrapbook(html_path);
    int keyPress;
    while (this->getChangeScreens() == false) {
        getyx(stdscr, curY, curX);
        keyPress = getch();
        switch(keyPress) {
        case KEY_BACKSPACE:
            this->changeScreens(true);
            this->screenNumber = 1;
            break;
        default:
            move(curY, curX);
            break;
        }
    }

    this->changeScreens(false);
    clear();

    refresh();
}


/**
 * @brief Clears the index.html file and prints the new stuff to it.
 */
void ScrapbookUI::viewMyScrapbook(std::string path) {
    const QString dateFormat = "h:m ap MMMM d yyyy";
    std::ofstream scrapbookHTML;
    scrapbookHTML.open(path, std::ios::out | std::ios::trunc);
    scrapbookHTML   << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"
                    << "<html xmlns=\"http://www.w3.org/1999/xhtml\">"
                    << "<head>"
                    << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />"
                    << "<link rel=\"stylesheet\" type=\"text/css\" href=\"anoceanofsky.css\" />"
                    << "<title>"
                    << this->getSystem()->getCurrentUser()->getUsername().toStdString()
                    << "'s Scrapbook</title>"
                    << "</head>"
                    << "<body>"
                    << "<div id=\"mainPicture\">"
                    << "<div class=\"picture\">"
                    << "<div id=\"headerTitle\">"
                    << this->getSystem()->getCurrentUser()->getUsername().toStdString()
                    << "'s Scrapbook</div>"
                    << "</div>"
                    << "</div>"
                    << "<div class=\"contentBox\">"
                    << "<div class=\"innerBox\">"
                    << "<div class=\"contentTitle\">First Name</div>"
                    << "<div class=\"contentText\"><p>"
                    << this->getSystem()->getCurrentUser()->getFirstName().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Last Name</div>"
                    << "<div class=\"contentText\"><p>"
                    << this->getSystem()->getCurrentUser()->getLastName().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Gender</div>"
                    << "<div class=\"contentText\"><p>"
                    << this->getSystem()->getCurrentUser()->getGender().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Home Address</div>"
                    << "<div class=\"contentText\"><p>"
                    << this->getSystem()->getCurrentUser()->getAddress().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Most Recent Employer</div>"
                    << "<div class=\"contentText\"><p>"
                    << this->getSystem()->getCurrentUser()->getMostRecentEmployer().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Age</div>"
                    << "<div class=\"contentText\"><p>"
                    << this->getSystem()->getCurrentUser()->getAge()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Phone Number</div>"
                    << "<div class=\"contentText\"><p>"
                    << this->getSystem()->getCurrentUser()->getPhoneNumber()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">About Yourself</div>"
                    << "<div class=\"contentText\"><p>"
                    << this->getSystem()->getCurrentUser()->getAbout().toStdString()
                    << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Tweets</div>"
                    << "<div class=\"contentText\"><p>";
    for (int i = 0; i < this->getSystem()->getCurrentUser()->getMyTweet()->getMyPosts().size(); i++) {
        std::string datetime = this->getSystem()->getCurrentUser()->getMyTweet()->getMyPosts()[i]->getTimePosted().toString(dateFormat).toStdString();
        std::string text = this->getSystem()->getCurrentUser()->getMyTweet()->getMyPosts()[i]->getText().toStdString();
        scrapbookHTML   << datetime
                        << "<br />"
                        << text
                        << "<br /><br />";
    }
    scrapbookHTML   << "</p><br /></div>"
                    << "<div class=\"contentTitle\">Blog</div>"
                    << "<div class=\"contentText\"><p>";
    for (int i = 0; i < this->getSystem()->getCurrentUser()->getMyBlog()->getMyPosts().size(); i++) {
        std::string datetime = this->getSystem()->getCurrentUser()->getMyBlog()->getMyPosts()[i]->getTimePosted().toString(dateFormat).toStdString();
        std::string text = this->getSystem()->getCurrentUser()->getMyBlog()->getMyPosts()[i]->getText().toStdString();
        scrapbookHTML   << datetime
                        << "<br />"
                        << text
                        << "<br /><br />";
    }
    scrapbookHTML   << "</p><br /></div>"
                    << "</div>"
                    << "</div>"
                    << "</body>"
                    << "</html>";
    scrapbookHTML.close();
    std::string command = "firefox "+path;
    system(command.c_str());
}
