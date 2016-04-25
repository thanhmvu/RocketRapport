#include "gtest/gtest.h"
#include "../model/blog.h"
#include "../model/blogpost.h"
#include "../model/dbmanager.h"
#include <qdatetime.h>

TEST(BlogTest, testAddBlogPost){
    DbManager dbmTest("../gProjectDB.db");
    Blog testB(&dbmTest);
    BlogPost *newBP = new BlogPost;
    newBP->setID(3);
    newBP->setText("This is another test blog post");

    QDateTime *newDateTime = new QDateTime;
    QDate newDate(2016,5,23);
    newDateTime->setDate(newDate);
    newBP->setTimePosted(*newDateTime);

    testB.addPost(newBP);
}
