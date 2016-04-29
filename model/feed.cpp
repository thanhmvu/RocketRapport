//#include "feed.h"

//int Feed::id_cnt = 0;

///**
// * @brief Feed::Feed Constructor used to create a new Feed with a reference to a dbManager object for data storage and retrieval
// * @param newdbm
// */
//Feed::Feed(DbManager *newdbm)
//{
//    dbm = newdbm;
//    feedID = id_cnt;
//    id_cnt++;
////    dbm->retrieveAllFeedPosts(this); //Retrieve all Feed posts associated with this Feed
//}

///**
// * @brief Feed::Feed Constructor used when adding Feed posts from the database using information in the given DB
// * @param FeedID ID of the new Feed we're creating
// * @param newdbm Pointer to a dbm object used for storing and retrieving information
// */
//Feed::Feed(int FeedID, DbManager *newdbm)
//{
//    dbm = newdbm;
//    feedID = FeedID;
//    // update id_cnt if needed
//    if(feedID >= id_cnt){
//        id_cnt = feedID + 1;
//    }
//    dbm->retrieveAllFeedPosts(this); //Retrieve all Feed posts associated with this Feed
//}

///**
// * @brief Feed::~Feed Destructor used to clear each Feed post from the vector of Feed posts contained in the Feed
// */
//Feed::~Feed(){
//    while(!myPosts.empty()){
//        delete myPosts.back();
//        myPosts.pop_back();
//    }
//}


///**
// * @brief Adds a new FeedPost to the Feed's list of posts.
// */
//void Feed::addPost(FeedPost* newPost) {
//    // add new post to the Feed post vector
//    myPosts.push_back(newPost);
//    // add new post to the database
//    storePostToDB(newPost);
//}

///**
// * @brief Feed::storePostToDB Store a Feed post's information to the database
// * @param newPost
// */
//void Feed::storePostToDB(FeedPost *newPost) {
//    dbm->addFeedPost( newPost->getID()      ,   feedID,
//                      newPost->getTimePosted(),   newPost->getText() );
//}

///**
// * @brief Removes a FeedPost from the Feed's list of posts.
// */
//void Feed::deletePost(FeedPost* oldPost) {
//    for (unsigned i = 0; i < this->getMyPosts().size(); i++) {
//        if (&(*oldPost) == &(*(this->getMyPosts()[i]))) {
//            this->getMyPosts().erase(this->getMyPosts().begin() + i);
//            break;
//        }
//    }
//}


///**
// * @brief Getter that returns the list of FeedPosts.
// */
//std::vector<FeedPost*> Feed::getMyPosts() {
//    return this->myPosts;
//}

///**
// * @brief Feed::getFeedID getter used for Feed ID
// * @return
// */
//int Feed::getFeedID(){
//    return feedID;
//}

///**
// * @brief Feed::setID Setter used for Feed ID.
// * @param newID
// */
//void Feed::setID(int newID){
//    feedID = newID;
//    // update id_cnt if needed
//    if(newID >= id_cnt){
//        id_cnt = newID + 1;
//    }
//}

///**
// * @brief Feed::deleteAllPosts Delete all posts found within the Feed.
// */
//void Feed::deleteAllPosts(){
//    while(!myPosts.empty()){
//        delete myPosts.back();
//        myPosts.pop_back();
//    }
//}
