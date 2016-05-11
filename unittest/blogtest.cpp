#include "gtest/gtest.h"
#include "../model/blog.h"
#include "../model/blogpost.h"
#include "../model/dbmanager.h"
#include "../model/account.h"
#include <qdatetime.h>
#include <vector>


TEST(BlogTest, testAddBlogPost){
    DbManager dbmTest("./gProjectDB.db");
    dbmTest.deleteTable("blogPosts");
    Blog testB(&dbmTest);

    QDateTime *newDateTime = new QDateTime;
    QDate newDate(2016,5,23);
    newDateTime->setDate(newDate);

    BlogPost *newBP1 = new BlogPost(3,*newDateTime,"MOM'S SPAGHETTI");
    BlogPost *newBP2 = new BlogPost(4,*newDateTime,"Test1");
    BlogPost *newBP3 = new BlogPost(5,*newDateTime,"Test2");
    testB.addPost(newBP1);
    testB.addPost(newBP2);
    testB.addPost(newBP3);
}

TEST(BlogTest,testRetrieveAllBlogPosts){
    DbManager newDBM("./gProjectDB.db");
    newDBM.deleteTable("blogPosts"); //Start with a fresh table
    newDBM.addBlogPost(0,3,2016,"One");
    newDBM.addBlogPost(1,3,2016,"Two");
    newDBM.addBlogPost(2,3,2016,"Three");
    Blog one(&newDBM);
   // newDBM.retrieveAllBlogPosts(&one);

    std::vector<BlogPost*> list = one.getMyPosts();
    qDebug() << "Blog ID: " << one.getBlogID();
    qDebug() << "Number of blog posts inside the user's blog" << list.size();

    for(int i=0; i<list.size(); i++){
        BlogPost *look = list.at(i);
        qDebug() << look->getID() << ": " << look->getText();
    }
    newDBM.deleteTable("blogPosts"); //Clean up the table
}

TEST(BlogTest, testDeleteAllPost){
    DbManager newDBM("./gProjectDB.db");
    newDBM.deleteTable("blogs");
    newDBM.deleteTable("blogPosts");
    Blog testBlog(0,&newDBM);
    BlogPost *insert1 = new BlogPost(0,QDateTime::currentDateTime(),"Test1");
    BlogPost *insert2 = new BlogPost(1,QDateTime::currentDateTime(),"Test2");
    BlogPost *insert3 = new BlogPost(2,QDateTime::currentDateTime(),"Test3");
    testBlog.addPost(insert1);
    testBlog.addPost(insert2);
    testBlog.addPost(insert3);
    ASSERT_EQ(testBlog.getMyPosts().size(),3);
    testBlog.deleteAllPosts();
    ASSERT_EQ(testBlog.getMyPosts().size(),0);
}

TEST(BlogTest, deletePost){
    DbManager dbmTest("./gProjectDB.db");
    dbmTest.deleteTable("blogPosts");
    Blog testB(&dbmTest);

    QDateTime *newDateTime = new QDateTime;
    QDate newDate(2016,5,23);
    newDateTime->setDate(newDate);

    BlogPost *newBP1 = new BlogPost(3,*newDateTime,"MOM'S SPAGHETTI");
    testB.addPost(newBP1);
    testB.deletePost(newBP1);

    ASSERT_EQ(testB.getMyPosts().size(),0);
}
