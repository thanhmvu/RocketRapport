#include "currentguest.h"

CurrentGuest::CurrentGuest()
{
    depart = false;
}


/**
 * @brief Sets the depart boolen to true indicating that the user is leaving the ranch.
 */
void CurrentGuest::departRanch() {
    this->setDepart(true);
}


/**
 * @brief Getter for the Blog pointer.
 */
Blog* CurrentGuest::getMyBlog() {
    return this->myBlog;
}


/**
 * @brief Setter for the Blog pointer.
 */
void CurrentGuest::setMyBlog(Blog* myBlog) {
    this->myBlog = myBlog;
}


/**
 * @brief Getter for the Tweet pointer.
 */
Tweet* CurrentGuest::getMyTweet() {
    return this->myTweet;
}


/**
 * @brief Setter for the Tweet pointer.
 */
void CurrentGuest::setMyTweet(Tweet* myTweet) {
    this->myTweet = myTweet;
}


/**
 * @brief Getter for the depart boolen.
 */
bool CurrentGuest::getDepart() {
    return this->depart;
}


/**
 * @brief Setter for the depart boolen.
 */
void CurrentGuest::setDepart(bool depart) {
    this->depart = depart;
}
