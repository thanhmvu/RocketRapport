#include "scrapbook.h"

int Scrapbook::id_cnt = 0;

Scrapbook::Scrapbook()
{
    scrpBookID = id_cnt;
    id_cnt++;
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
    for (int i = 0; i < this->getMyPosts().size(); i++) {
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
