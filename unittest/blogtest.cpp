#include "gtest/gtest.h"
#include "../model/blog.h"
#include "../model/blogpost.h"
#include "../model/dbmanager.h"
#include <qdatetime.h>
#include <vector>

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

TEST(BlogTest,testBlogConstructor){
    DbManager newDBM("../gProjectDB.db");
    Blog one(&newDBM);

    std::vector<BlogPost*> list = one.getMyPosts();
    qDebug() << "Number of blog posts inside the user's blog" << list.size();

    for(int i=0; i<list.size(); i++){
        BlogPost *look = list.at(i);
        qDebug() << look->getID() << ": " << look->getText();
    }
}

TEST(BlogTest, testBlogAdd){
    DbManager newDBM("../gProjectDB.db");
    Blog one(&newDBM);
    BlogPost *first = new BlogPost;
    first->setText("One");
    BlogPost *second = new BlogPost;
    second->setText("Two");
    BlogPost *third = new BlogPost;
    third->setText("Three");
    one.addPost(first); one.addPost(second); one.addPost(third);
}
