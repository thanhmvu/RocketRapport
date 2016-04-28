#include "scrapbookui.h"

ScrapbookUI::ScrapbookUI(System* mainSystem)
{
    this->setSystem(mainSystem);
}


/**
 * @brief Sets up the design of the screen.
 */
void ScrapbookUI::displayScreen() {
    mvprintw(1, 1, "On Scrapbook Screen");
    refresh();
}


/**
 * @brief Loops through this method while the user is on this screen.
 */
void ScrapbookUI::runScreen() {
//    this->viewMyScrapbook("../index.html");
    mvprintw(2, 1, "In Run Screen");
    getch();

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
    scrapbookHTML << "";
    scrapbookHTML.close();
}
