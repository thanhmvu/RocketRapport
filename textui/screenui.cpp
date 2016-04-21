#include "screenui.h"

int ScreenUI::screenNumber = 1;

ScreenUI::ScreenUI()
{
    getmaxyx(stdscr, this->rows, this->cols);
    this->menuIndex = 0;
    this->changeScreen = false;
}


/**
 * @brief Sets the changeScreen variable (usually when the user is switching screens).
 */
void ScreenUI::changeScreens(bool change) {
    this->changeScreen = change;
}


/**
 * @brief Getter for the current index of the menu that the user is at.
 */
int ScreenUI::getMenuIndex() {
    return this->menuIndex;
}


/**
 * @brief Sets the menu index to the int passed.
 */
void ScreenUI::setMenuIndex(int index) {
    this->menuIndex = index;
}


/**
 * @brief Increases the current menu index by 1 when the user moves down the menu.
 */
void ScreenUI::moveDownMenuIndex() {
    this->menuIndex++;
}


/**
 * @brief Decreases the current menu index by 1 when the user moves up the menu.
 */
void ScreenUI::moveUpMenuIndex() {
    this->menuIndex--;
}


/**
 * @brief Getter for the number of menu options.
 */
int ScreenUI::getNumOfOptions() {
    return this->numOfOptions;
}


void ScreenUI::setNumOfOptions(int options) {
    this->numOfOptions = options;
}


/**
 * @brief Getter for the number of rows (the y-coor) of the terminal window.
 */
int ScreenUI::getRows() {
    return this->rows;
}


/**
 * @brief Getter for the number of cols (the x-coor) of the terminal window.
 */
int ScreenUI::getCols() {
    return this->cols;
}


/**
 * @brief Getter for the boolean that keeps track of when the user is switching screens.
 */
bool ScreenUI::getChangeScreens() {
    return this->changeScreen;
}


/**
 * @brief Getter for the main system.
 */
System* ScreenUI::getSystem() {
    return this->mySystem;
}


/**
 * @brief Setter for the main system.
 */
void ScreenUI::setSystem(System* mainSystem) {
    this->mySystem = mainSystem;
}
