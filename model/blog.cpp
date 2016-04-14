#include "blog.h"

Blog::Blog()
{

}


/**
 * @brief Adds a new BlogPost to the Blog's list of posts.
 */
void Blog::addPost(BlogPost* newPost) {
    this->getMyPosts().push_back(newPost);
}


/**
 * @brief Removes a BlogPost from the Blog's list of posts.
 */
void Blog::deletePost(BlogPost* oldPost) {
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
void Blog::concastPosts() {

}



/**
 * @brief Getter that returns the list of BlogPosts.
 */
std::vector<BlogPost*> Blog::getMyPosts() {
    return this->myPosts;
}

int Blog::getBlogID(){
    return blogID;
}
