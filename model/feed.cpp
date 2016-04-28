#include "feed.h"

int Feed::id_cnt = 0;

Feed::Feed()
{
    feedID = id_cnt;
    id_cnt++;
}

Feed::Feed(int newID){
    feedID = newID;
}

Feed::~Feed(){
    while(!feedPosts.empty()){
        delete feedPosts.back();
        feedPosts.pop_back();
    }
}

/**
 * @brief Concatenates all of the TweetPosts in this Feed into one string of text.
 */
void Feed::displayFeed() {
    this->setFeedText("");
    for (unsigned i = 0; i < this->getFeedPosts().size(); i++) {
        this->setFeedText(this->getFeedText() += (*(this->getFeedPosts()[i])).getText() += /*" "
                          + (*(this->getFeedPosts()[i])).getTime() + " "
                          + (*(this->getFeedPosts()[i])).getDate() + */
                          "`");
        // Character '`' will be used to seperate each post.

        // Talk to Thanh about Post class and concatenating the posts.
    }
}


/**
 * @brief Adds a new TweetPost to the list of posts.
 */
void Feed::addPost(TweetPost* newPost) {
    this->getFeedPosts().push_back(newPost);
}


/**
 * @brief Removes a TweetPost from the list of posts.
 */
void Feed::removePost(TweetPost* oldPost) {
    for (unsigned i = 0; i < this->getFeedPosts().size(); i++) {
        if (&(*oldPost) == &(*(this->getFeedPosts()[i]))) {
            this->getFeedPosts().erase(this->getFeedPosts().begin() + i);
            break;
        }
    }
}


/**
 * @brief Getter that returns the list of feed posts.
 */
std::vector<TweetPost*> Feed::getFeedPosts() {
    return this->feedPosts;
}


/**
 * @brief Getter that returns the feed text in one string.
 */
QString Feed::getFeedText() {
    return this->feedText;
}


/**
 * @brief Setter that sets the feed text;
 */
void Feed::setFeedText(QString text) {
    this->feedText = text;
}

int Feed::getFeedID(){
    return feedID;
}
