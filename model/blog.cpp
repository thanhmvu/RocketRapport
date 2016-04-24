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
    // add new post to the blog post vector
    myPosts.push_back(newPost);

    // add new post to the database
    storePostToDB(newPost);
}

void Blog::storePostToDB(BlogPost* newPost) {
//    std::cout << "Now entering add account method" << std::endl;
//    const QString &x = QString::fromStdString(newAccount->getFirstName());
//    const QString &y = QString::fromStdString(newAccount->getLastName());
//    const QVariant accntD = newAccount->getAccountID();
//    const QVariant frstName(x);
//    const QVariant lstNme(y);
//    const QString &a = QString::fromStdString(newAccount->getUsername() );
//    const QString &b = QString::fromStdString(newAccount->getPassword() );
//    const QVariant usrName(a);
//    const QVariant passWord(b);

//    const QVariant ScrpBkID = newAccount->getMyScrapbook()->getScrpbkID();
//    const QVariant BlgID = newAccount->getMyBlog()->getBlogID();
//    const QVariant TweetID = newAccount->getMyTweet()->getTweetID();

//    dbm->addBlogPost(accntD,frstName,lstNme,
//                ScrpBkID,BlgID,TweetID,usrName,
//                 passWord);
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
