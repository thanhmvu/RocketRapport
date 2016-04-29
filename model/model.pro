TEMPLATE = app
CONFIG += console c++11
QT += sql

SOURCES += main.cpp \
    system.cpp \
    account.cpp \
    post.cpp \
    scrapbook.cpp \
    group.cpp \
    feed.cpp \
    chat.cpp \
    message.cpp \
    blog.cpp \
    tweet.cpp \
    comment.cpp \
    blogpost.cpp \
    tweetpost.cpp \
    scrapbookpost.cpp \
    dbmanager.cpp \
    feedpost.cpp

HEADERS += \
    system.h \
    account.h \
    post.h \
    scrapbook.h \
    group.h \
    feed.h \
    chat.h \
    message.h \
    blog.h \
    tweet.h \
    comment.h \
    blogpost.h \
    tweetpost.h \
    scrapbookpost.h \
    dbmanager.h \
    feedpost.h

LIBS += -l sqlite3

