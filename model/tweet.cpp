#include "tweet.h"

int Tweet::id_cnt = 0;

Tweet::Tweet(DbManager *newDbm)
{
    dbm = newDbm;
    tweetID = id_cnt;
    id_cnt ++;
}

/**
 * @brief Adds a new TweetPost to the Tweet's list of posts.
 */
void Tweet::addPost(TweetPost* newPost) {
    // add new post to the blog post vector
    myPosts.push_back(newPost);


}

void Tweet::createPost(TweetPost *newPost){
    myPosts.push_back(newPost);
    // add new post to the database
    dbm->addTweetPost(tweetID,newPost->getID(),newPost->getTimePosted(),newPost->getText());

}

/**
 * @brief Removes a TweetPost from the Tweet's list of posts.
 */
void Tweet::deletePost(TweetPost* oldPost) {
    for (unsigned i = 0; i < this->getMyPosts().size(); i++) {
        if (&(*oldPost) == &(*(this->getMyPosts()[i]))) {
            this->getMyPosts().erase(this->getMyPosts().begin() + i);
            break;
        }
    }
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

void Tweet::setID(int newID){
    tweetID = newID;
}
