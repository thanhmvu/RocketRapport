#include "group.h"

int Group::id_cnt = 0;

Group::Group()
{
    groupID = id_cnt;
    id_cnt++;
}


///**
// * @brief Adds a new TweetPost to the group feed.
// */
//void Group::updateFeed(Account* userPosted, TweetPost* latestPost) {
//    this->getFeed()->addPost(latestPost);
//    this->getFeed()->displayFeed();

//    // Add Account to Post.
//}

///**
// * @brief Adds a new account/user to the group.
// */
//void Group::addGroupMember(Account* newMember) {
//    this->getGroupMembers().push_back(newMember);
//}


///**
// * @brief Removes an account/user from the group.
// */
//void Group::removeGroupMember(Account* oldMember) {
//    for (int i = 0; i < this->getGroupMembers().size(); i++) {
//        if (&(*oldMember) == &(*(this->getGroupMembers()[i]))) {
//            this->getGroupMembers().erase(this->getGroupMembers().begin() + i);
//            break;
//        }
//    }
//}


///**
// * @brief Adds a new project to the list of past projects.
// */
//void Group::addToPastProjects(QString project) {
//    this->getPastProjects().push_back(project);
//}


///**
// * @brief Getter that returns the Feed object associated with this group.
// */
//Feed* Group::getFeed() {
//    return this->groupFeed;
//}


///**
// * @brief Getter that returns the isActive boolen.
// */
//bool Group::getIsActive() {
//    return this->isActive;
//}


///**
// * @brief Setter that sets the isActive boolen.
// */
//void Group::setIsActive(bool active) {
//    this->isActive = active;
//}

///**
// * @brief Getter that returns the list of members in this group.
// */
//std::vector<Account*> Group::getGroupMembers() {
//    return this->groupMembers;
//}


///**
// * @brief Getter that returns the admin of this group.
// */
//Account* Group::getAdmin() {
//    return this->admin;
//}


///**
// * @brief Changes the group admin to the given user.
// */
//void Group::changeAdmin(Account* newAdmin) {
//    this->admin = newAdmin;
//}

///**
// * @brief Getter that returns the name of the group.
// */
//QString Group::getGroupName() {
//    return this->groupName;
//}


///**
// * @brief Setter that sets the name of this group.
// */
//void Group::setGroupName(QString name) {
//    this->groupName = name;
//}


///**
// * @brief Getter that returns the current project.
// */
//QString Group::getCurrentProject() {
//    return this->currentProject;
//}


///**
// * @brief Setter that sets the current project.
// */
//void Group::setCurrentProject(QString project) {
//    this->currentProject = project;
//}


///**
// * @brief Changes the current project and adds the old project to the pastProjects list.
// */
//void Group::newProject(QString project) {
//    this->getPastProjects().push_back(this->getCurrentProject());
//    this->currentProject = project;
//}


///**
// * @brief Getter that returns the list of past projects.
// */
//std::vector<QString> Group::getPastProjects() {
//    return this->pastProjects;
//}

/**
 * @brief Getter that returns the ID of this group.
 */
int Group::getID(){
    return groupID;
}
