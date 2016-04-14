TEMPLATE = app
CONFIG += console c++11
QT += sql

SOURCES += main.cpp \
    system.cpp \
    account.cpp \
    post.cpp \
    dbtable.cpp \
    dbtool.cpp \
    scrapbook.cpp \
    pastguest.cpp \
    currentguest.cpp \
    groupadmin.cpp \
    systemadmin.cpp \
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
    dbtablerranch.cpp \
    dbmanager.cpp

HEADERS += \
    system.h \
    account.h \
    post.h \
    dbtable.h \
    dbtool.h \
    scrapbook.h \
    pastguest.h \
    currentguest.h \
    groupadmin.h \
    systemadmin.h \
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
    dbtablerranch.h \
    dbmanager.h

LIBS += -l sqlite3

