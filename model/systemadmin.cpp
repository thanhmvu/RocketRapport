#include "systemadmin.h"

SystemAdmin::SystemAdmin()
{

}


/**
 * @brief Adds a group to the System's list of groups.
 */
void SystemAdmin::addGroup(Group* newGroup) {
    this->getSystem()->addGroup(newGroup);
}


/**
 * @brief Removes a group from the System's list of groups.
 */
void SystemAdmin::deleteGroup(Group* oldGroup) {
    this->getSystem()->removeGroup(oldGroup);
}


/**
 * @brief Adds an account to the System's list of accounts.
 */
void SystemAdmin::addAccount(Account* newAccount, std::string username, std::string firstName, std::string lastName) {
    (*newAccount).setFirstName(firstName);
    (*newAccount).setLastName(lastName);
    (*newAccount).setUsername(username);

    this->getSystem()->addAccount(newAccount);
}


/**
 * @brief Removes an account from the System's list of accounts.
 */
void SystemAdmin::deleteAccount(Account* oldAccount) {
    this->getSystem()->removeAccount(oldAccount);
}


/**
 * @brief Removes a blog post from the Blog in question.
 */
void SystemAdmin::deleteBlogPost(Blog* targetBlog, BlogPost* badPost) {
    (*targetBlog).deletePost(badPost);
}


/**
 * @brief Removes a tweet post from the Tweet in question.
 */
void SystemAdmin::deleteTweetPost(Tweet* targetTweet, TweetPost* badPost) {
    (*targetTweet).deletePost(badPost);
}


/**
 * @brief Removes a scracpbook post from the Scrapbook in question.
 */
void SystemAdmin::deleteScrapbookPost(Scrapbook* targetScrapbook, ScrapbookPost* badPost) {
    (*targetScrapbook).deletePost(badPost);
}


/**
 * @brief Getter that returns the System object.
 */
System* SystemAdmin::getSystem() {
    return this->theSystem;
}


/**
 * @brief Setter that sets the System object.
 */
void SystemAdmin::setSystem(System* newSystem) {
    this->theSystem = newSystem;
}
