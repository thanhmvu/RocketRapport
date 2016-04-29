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
    curs_set(0);
    int curY = (this->getRows()/2)+1, curX = (this->getCols()/2)-6;
    this->viewMyScrapbook("../index.html");
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
                    << "<div class=\"contentText\"><p>";
    scrapbookHTML.close();
    system("firefox ../index.html");
}
