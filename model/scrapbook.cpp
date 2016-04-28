#include "scrapbook.h"

int Scrapbook::id_cnt = 0;


Scrapbook::Scrapbook(Account* sb_owner)
{
    scrpBookID = id_cnt;
    id_cnt++;
    owner = sb_owner;
}

/**
 * @brief constructor to rebuild an instance of existing scrapbook.
 *
 */
Scrapbook::Scrapbook(int newID, Account* sb_owner)
{
    scrpBookID = newID;
    // update id_cnt if needed
    if(scrpBookID >= id_cnt){
        id_cnt = scrpBookID + 1;
    }
    owner = sb_owner;
}

Scrapbook::~Scrapbook(){
    while(!myPosts.empty()){
        delete myPosts.back();
        myPosts.pop_back();
    }
}


void Scrapbook::setID(int newID){
    scrpBookID = newID;
    // update id_cnt if needed
    if(newID >= id_cnt){
        id_cnt = newID + 1;
    }
}

/**
 * @brief Adds a new ScrapbookPost to the Scrapbook's list of posts.
 */
void Scrapbook::addPost(ScrapbookPost* newPost) {
    this->getMyPosts().push_back(newPost);
}


/**
 * @brief Removes a ScrapbookPost from the Scrapbook's list of posts.
 */
void Scrapbook::deletePost(ScrapbookPost* oldPost) {
    for (unsigned i = 0; i < this->getMyPosts().size(); i++) {
        if (&(*oldPost) == &(*(this->getMyPosts()[i]))) {
            this->getMyPosts().erase(this->getMyPosts().begin() + i);
            break;
        }
    }
}


/*//////////////////////////////////////////////////////////////////
///
///
///
///                 NEEDS TO BE IMPLEMENTED.
///
///
///
/////////////////////////////////////////////////////////////////*/
void Scrapbook::concastPosts() {

}



/**
 * @brief Getter that returns the list of ScrapbookPosts.
 */
std::vector<ScrapbookPost*> Scrapbook::getMyPosts() {
    return this->myPosts;
}

int Scrapbook::getScrpbkID(){
    return scrpBookID;
}
