#include "blog.h"

int Blog::id_cnt = 0;

Blog::Blog()
{
    blogID = id_cnt;
    id_cnt++;
}


/**
 * @brief Adds a new BlogPost to the Blog's list of posts.
 */
void Blog::addPost(BlogPost* newPost) {
    myPosts.push_back(newPost);
    std::cout << "New Blog Post has been added \n";
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
