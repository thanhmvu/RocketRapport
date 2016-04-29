//#include "feedpost.h"

//int FeedPost::id_cnt = 0;

////FeedPost::FeedPost()
////{
////    id = id_cnt;
////    id_cnt ++;
////}

///**
// * @brief FeedPost::FeedPost Standard constructor used for creating a new FeedPost object
// * @param FeedID ID of the Feed this post belongs to
// * @param t Time that this post was posted on
// * @param content Text content to be attached to this Feed post
// */
//FeedPost::FeedPost(int FeedID, QDateTime t, QString content){
//    id = id_cnt;
//    id_cnt ++;

//    feedID = FeedID;
//    timePosted = t;
//    text = content;
//}

///**
// * @brief FeedPost::FeedPost Constructor for a Feed post retrieved from the database
// * @param newID ID for the Feed post retrieved from the database
// * @param FeedID Feed ID that this Feed post belongs to retrieved from the database
// * @param t Time that this post was posed on - retrieved from the database
// * @param content Text posted in the given Feed post
// */
//FeedPost::FeedPost(int newID, int FeedID, QDateTime t, QString content){
//    id = newID;
//    // update id_cnt if needed
//    if(newID >= id_cnt){
//        id_cnt = newID + 1;
//    }

//    feedID = FeedID;
//    timePosted = t;
//    text = content;
//}

///**
// * @brief FeedPost::getID Getter method for the Feed Post's ID
// */
//int FeedPost::getID(){ return id; }

////void FeedPost::setID(int newID){
////    id = newID;

////    // update id_cnt if needed
////    if(newID >= id_cnt){
////        id_cnt = newID + 1;
////    }
////}

///**
// * @brief FeedPost::getFeedID Getter methos used to retrieve the ID of the Feed this Feed post belongs to.
// */
//int FeedPost::getFeedID(){ return feedID; }

///**
// * @brief FeedPost::setFeedID Change the ID of the Feed that this Feed post belongs to. Using this method changes the Feed that this post belongs to
// * @param newID
// */
//void FeedPost::setFeedID(int newID){
//    feedID = newID;
//}

///**
// * @brief FeedPost::setText Set the text that is included in this Feed post
// * @param new_text New text that we want to store in this Feed post.
// */
//void FeedPost::setText(QString new_text){
//    text = new_text;
//}

///**
// * @brief FeedPost::setTimePosted Set the date that this Feed post was posted on
// * @param new_time
// */
//void FeedPost::setTimePosted(QDateTime new_time){
//    timePosted = new_time;
//}

///**
// * @brief FeedPost::getText Getter method that returns the text included in this Feed post
// */
//QString FeedPost::getText(){
//    return text;
//}

///**
// * @brief FeedPost::getTimePosted Getter method for the time this Feed post was added to the user's Feed
// */
//QDateTime FeedPost::getTimePosted(){
//    return timePosted;
//}

////We've cut out commenting functionality for now.
////bool FeedPost::addComment(Comment cmt){
////    comments.push_back(cmt);
////    return true;
////}

////bool FeedPost::deleteComment(int cmt_id){
////    int cmt_index = findComment(cmt_id);
////    if(cmt_index != -1){
////        comments.erase(comments.begin() + cmt_index);
////        return true;
////    }else{
////        std::cout << "Comment not found!" <<std::endl;
////        return false;
////    }
////}

////int FeedPost::findComment(int cmt_id){
////    for(int i = 0; i< comments.size(); i++){
////        if(comments[i].getID() == cmt_id){
////            return i;
////        }
////    }
////    return -1;
////}
