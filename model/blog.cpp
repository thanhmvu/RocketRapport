#include "blog.h"

int Blog::id_cnt = 0;

Blog::Blog(DbManager *newdbm)
{
    dbm = newdbm;
    blogID = id_cnt;
    id_cnt++;
    //dbm->retrieveAllBlogPosts(this); //Retrieve all blog posts associated with this blog
}

/**
 * @brief Adds a new BlogPost to the Blog's list of posts.
 */
void Blog::addPost(BlogPost* newPost) {
    // add new post to the blog post vector
    myPosts.push_back(newPost);
    // add new post to the database
    storePostToDB(newPost);
}

void Blog::storePostToDB(BlogPost *newPost) {
    dbm->addBlogPost( newPost->getID()      ,   blogID,
                      newPost->getTimePosted(),   newPost->getText() );
}

/**
 * @brief Removes a BlogPost from the Blog's list of posts.
 */
void Blog::deletePost(BlogPost* oldPost) {
    for (unsigned i = 0; i < this->getMyPosts().size(); i++) {
        if (&(*oldPost) == &(*(this->getMyPosts()[i]))) {
            this->getMyPosts().erase(this->getMyPosts().begin() + i);
            break;
        }
    }
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

void Blog::setID(int newID){
    blogID = newID;
}

void Blog::deleteAllPosts(){
    while(!myPosts.empty()){
        delete myPosts.back();
        myPosts.pop_back();
    }
}
