#include "tweet.h"

int Tweet::id_cnt = 0;

Tweet::Tweet()
{
    tweetID = id_cnt;
    id_cnt ++;
}

void Tweet::setID(int newID){
    tweetID = newID;
}

/**
 * @brief Adds a new TweetPost to the Tweet's list of posts.
 */
void Tweet::addPost(TweetPost* newPost) {
    myPosts.push_back(newPost);
}


/**
 * @brief Removes a TweetPost from the Tweet's list of posts.
 */
void Tweet::deletePost(TweetPost* oldPost) {
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
void Tweet::concastPosts() {

}



/**
 * @brief Getter that returns the list of TweetPosts.
 */
std::vector<TweetPost*> Tweet::getMyPosts() {
    return myPosts;
}

int Tweet::getTweetID(){
    return tweetID;
}
