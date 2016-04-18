#include "screenui.h"

ScreenUI::ScreenUI()
{

}


/**
 * @brief Getter for the current index of the menu that the user is at.
 */
int ScreenUI::getMenuIndex() {
    return this->menuIndex;
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
