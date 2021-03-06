#include "group.h"

int Group::id_cnt = 0;

/**
 * @brief Group::Group Constructor used for creating a new group
 */
Group::Group(QString gName, DbManager *newdbm){
    groupID = id_cnt;
    id_cnt++;
    groupName = gName;

    dbm = newdbm;

    isActive = true;
    adminID = -1; //Store a default value
    groupBlog = new Blog(dbm);
}

/**
 * @brief Group::Group Constructor used for creating a group on the local memory whose information is located on the database
 * @param gID
 * @param gName
 * @param newStatus
 */
Group::Group(int gID, int GrpAdminID, QString gName,
             bool newStatus, int newBlogID, DbManager *newdbm,
             QString groupDescription)
{
    groupID = gID;
    // update id_cnt if needed
    if(gID >= id_cnt){
        id_cnt = gID + 1;
    }

    dbm = newdbm;

    groupName = gName;
    isActive = newStatus;
    adminID = GrpAdminID;
    aboutGroup = groupDescription;

    // retrieve all blog posts inside the constructor
    groupBlog = new Blog(newBlogID,dbm);
}

Group::~Group(){
    delete groupBlog;
}

///**
// * @brief Adds a new TweetPost to the group Blog.
// */
//void Group::updateBlog(Account* userPosted, TweetPost* latestPost) {
//    this->getBlog()->addPost(latestPost);
//    this->getBlog()->displayBlog();

//    // Add Account to Post.
//}

/**
 * @brief Adds an account/user to the group.
 * @param newMember Pointer to account object that we want to add to this particular group.
 */
bool Group::addGroupMember(Account* newMember) {
    if(newMember != nullptr){
        // check if this member already in the list
        for(Account * a : groupMembers){
            if(a != nullptr){
                if(a->getUsername().compare(newMember->getUsername()) == 0){
                    std::cout<< "Already in group\n";
                    return false;
                }
            }else{
                std::cout<< "null pointer in Group::addGroupMember\n";
            }
        }
        // if not, add to the list
        groupMembers.push_back(newMember);
        // let new member join group
        newMember->joinGroup(this);
        return true;
    }else{
        std::cout<< "null pointer in Group::addGroupMember\n";
        return false;
    }
}

void Group::addGroupMemberID(int newID){
    groupMemberIDs.push_back(newID);
}

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
// * @brief Getter that returns the Blog object associated with this group.
// */
//Blog* Group::getBlog() {
//    return this->groupBlog;
//}


/**
 * @brief Getter that returns the isActive boolen.
 */
bool Group::getIsActive() {
    return isActive;
}


///**
// * @brief Setter that sets the isActive boolen.
// */
//void Group::setIsActive(bool active) {
//    this->isActive = active;
//}

/**
 * @brief Getter that returns the list of members in this group.
 */
std::vector<Account*> Group::getGroupMembers() {
    return this->groupMembers;
}

std::vector<int> Group::getGroupMemberIDs(){
    return groupMemberIDs;
}


/**
 * @brief Getter that returns the admin of this group.
 */
Account* Group::getAdmin() {
    return this->admin;
}


///**
// * @brief Changes the group admin to the given user.
// */
//void Group::changeAdmin(Account* newAdmin) {
//    this->admin = newAdmin;
//}

/**
 * @brief Getter that returns the name of the group.
 */
QString Group::getGroupName() {
    return groupName;
}


/**
 * @brief Setter that sets the name of this group.
 */
void Group::setGroupName(QString name) {
    groupName = name;
}


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

int Group::getAdminID(){
    return adminID;
}

Blog* Group::getBlog(){
    return groupBlog;
}

bool Group::setStatus(bool activeState){
    isActive = activeState;
}

/**
 * @brief Setter that sets the aboutGroup of this group.
 */
bool Group::setAboutGroup(QString aboutUs){
    aboutGroup = aboutUs;
    return true;
}

/**
 * @brief Getter that returns the aboutGroup of this group.
 */
QString Group::getAboutGroup(){
    return aboutGroup;
}

/**
 * @brief Group::isMember check if a given user is a member of the group
 * @param user the username of the user to check
 * @return true if given user is a member
 */
bool Group::isMember(QString user){
    for(Account * acc: groupMembers){
        if(acc->getUsername().compare(user) == 0){
            return true;
        }
    }
    return false;
}

/**
 * @brief Group::retrieveAllPosts() retrieves all group post from the database
 */
void Group::retrieveAllPosts(){
    // clear old posts
    groupBlog->deleteAllPosts();
    // retrieve all posts
    dbm->retrieveAllBlogPosts(groupBlog);
}
