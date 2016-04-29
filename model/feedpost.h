//#ifndef FEEDPOST_H
//#define FEEDPOST_H
//#include "post.h"
//#include "comment.h"
//#include <vector>
//#include <string>
//#include <qstring.h>
//#include <qdatetime.h>
//class Feed;

//class FeedPost: public Post
//{
//private:
//    static int id_cnt;
//    int id;
//    int feedID;
//    std::vector<Comment> comments;
//    QDateTime timePosted;
//    QString text;

//    // inherit text and time from Post

//public:
////    FeedPost();
//    /**
//     * @brief FeedPost::FeedPost Standard constructor used for creating a new FeedPost object
//     * @param FeedID ID of the feed this post belongs to
//     * @param t Time that this post was posted on
//     * @param content Text content to be attached to this feed post
//     */
//    FeedPost(int FeedID, QDateTime t, QString content);
//    /**
//     * @brief FeedPost::FeedPost Constructor for a Feed post retrieved from the database
//     * @param newID ID for the Feed post retrieved from the database
//     * @param FeedID Feed ID that this Feed post belongs to retrieved from the database
//     * @param t Time that this post was posed on - retrieved from the database
//     * @param content Text posted in the given Feed post
//     */
//    FeedPost(int newID, int FeedID, QDateTime t, QString content);

//    // Setter methods for each relevant field
//    /**
//     * @brief FeedPost::setText Set the text that is included in this Feed post
//     * @param new_text New text that we want to store in this Feed post.
//     */
//    void setText(QString new_text);
//    /**
//     * @brief FeedPost::setTimePosted Set the date that this Feed post was posted on
//     */
//    void setTimePosted(QDateTime new_time);
////    void setID(int newID);
//    /**
//     * @brief FeedPost::setFeedID Change the ID of the Feed that this Feed post belongs to. Using this method changes the Feed that this post belongs to
//     * @param newID
//     */
//    void setFeedID(int newID);

//    //Getter methods for each field
//    /**
//     * @brief FeedPost::getID Getter method for the Feed Post's ID
//     */
//    int getID();
//    /**
//     * @brief FeedPost::getFeedID Getter methos used to retrieve the ID of the Feed this Feed post belongs to.
//     */
//    int getFeedID();
//    /**
//     * @brief FeedPost::getText Getter method that returns the text included in this Feed post
//     */
//    QString getText();
//    /**
//     * @brief FeedPost::getTimePosted Getter method for the time this Feed post was added to the user's Feed
//     */
//    QDateTime getTimePosted();


////    std::vector<Comment> getComments();

//    //Comment methods
////    bool addComment(Comment cmt);
////    bool deleteComment(int id);
////    int findComment(int cmt_id);

//    // for debugging purpose
//    static int getIdCnt(){ return id_cnt; };
//};

//#endif // FEEDPOST_H
