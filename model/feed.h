//#ifndef FEED_H
//#define FEED_H
//#include "feedpost.h"
//#include <stdio.h>
//#include "dbmanager.h"
//#include <vector>
//class DbManager;


//class Feed
//{
//private:
//    static int id_cnt;
//    int feedID;
//    std::vector<FeedPost*> myPosts; // own this
////    QString FeedText;
//    DbManager *dbm; // does not own this
//public:
//    /**
//     * @brief Feed::Feed Constructor used to create a new Feed with a reference to a dbManager object for data storage and retrieval
//     * @param newdbm
//     */
//    Feed(DbManager *newdbm);
//    /**
//     * @brief Feed::Feed Constructor used when adding Feed posts from the database using information in the given DB
//     * @param FeedID ID of the new Feed we're creating
//     * @param newdbm Pointer to a dbm object used for storing and retrieving information
//     */
//    Feed(int FeedID, DbManager *newdbm);
//    /**
//     * @brief Feed::~Feed Destructor used to clear each Feed post from the vector of Feed posts contained in the Feed
//     */
//    ~Feed();
//    /**
//     * @brief Feed::setID Setter used for Feed ID.
//     */
//    void setID(int newID);
//    /**
//     * @brief Adds a new FeedPost to the Feed's list of posts.
//     */
//    void addPost(FeedPost* newPost);
//    /**
//     * @brief Feed::storePostToDB Store a Feed post's information to the database
//     * @param newPost
//     */
//    void storePostToDB(FeedPost* newPost);
//    /**
//     * @brief Removes a FeedPost from the Feed's list of posts.
//     */
//    void deletePost(FeedPost* oldPost);
//    /**
//     * @brief Feed::deleteAllPosts Delete all posts found within the Feed.
//     */
//    void deleteAllPosts();

//    /**
//     * @brief Getter that returns the list of FeedPosts.
//     */
//    std::vector<FeedPost*> getMyPosts();
//    /**
//     * @brief Feed::getFeedID getter used for Feed ID
//     */
//    int getFeedID();

//    // for debugging purpose
//    static int getIdCnt(){ return id_cnt; };
//};

//#endif // FEED_H
