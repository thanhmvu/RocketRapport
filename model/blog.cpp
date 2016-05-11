#include "blog.h"

int Blog::id_cnt = 0;

/**
 * @brief Blog::Blog Constructor used to create a new blog with a reference to a dbManager object for data storage and retrieval
 * @param newdbm
 */
Blog::Blog(DbManager *newdbm)
{
    dbm = newdbm;
    blogID = id_cnt;
    id_cnt++;
}

/**
 * @brief Blog::Blog Constructor used when adding blog posts from the database using information in the given DB
 * @param BlogID ID of the new Blog we're creating
 * @param newdbm Pointer to a dbm object used for storing and retrieving information
 */
Blog::Blog(int BlogID, DbManager *newdbm)
{
    dbm = newdbm;
    blogID = BlogID;
    // update id_cnt if needed
    if(blogID >= id_cnt){
        id_cnt = blogID + 1;
    }
    dbm->retrieveAllBlogPosts(this); //Retrieve all blog posts associated with this blog
}

/**
 * @brief Blog::~Blog Destructor used to clear each blog post from the vector of blog posts contained in the blog
 */
Blog::~Blog(){
    while(!myPosts.empty()){
        delete myPosts.back();
        myPosts.pop_back();
    }
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

/**
 * @brief Blog::storePostToDB Store a blog post's information to the database
 * @param newPost
 */
void Blog::storePostToDB(BlogPost *newPost) {
    dbm->addBlogPost( newPost->getID()      ,   blogID,
                      newPost->getTimePosted(),   newPost->getText() );
}

/**
 * @brief Removes a BlogPost from the Blog's list of posts.
 */
void Blog::deletePost(BlogPost* oldPost) {
    for (unsigned i = 0; i < myPosts.size(); i++) {
        if (oldPost->getID() == myPosts[i]->getID()) {
            myPosts.erase(myPosts.begin() + i);
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

/**
 * @brief Blog::getBlogID getter used for Blog ID
 * @return
 */
int Blog::getBlogID(){
    return blogID;
}

/**
 * @brief Blog::setID Setter used for blog ID.
 * @param newID
 */
void Blog::setID(int newID){
    blogID = newID;
    // update id_cnt if needed
    if(newID >= id_cnt){
        id_cnt = newID + 1;
    }
}

/**
 * @brief Blog::deleteAllPosts Delete all posts found within the Blog.
 */
void Blog::deleteAllPosts(){
    while(!myPosts.empty()){
        delete myPosts.back();
        myPosts.pop_back();
    }
}
