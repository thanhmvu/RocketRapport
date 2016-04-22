TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += sql
LIBS += -lncurses

SOURCES += main.cpp \
    screenui.cpp \
    choiceui.cpp \
    mainmenuui.cpp \
    blogui.cpp \
    tweetui.cpp \
    chatui.cpp \
    loginui.cpp \
    scrapbookui.cpp \
    profileui.cpp \
    ../model/system.cpp \
    ../model/account.cpp \
    ../model/chat.cpp \
    ../model/message.cpp \
    ../model/group.cpp \
    ../model/comment.cpp \
    ../model/dbmanager.cpp \
    ../model/blog.cpp \
    ../model/blogpost.cpp \
    ../model/tweet.cpp \
    ../model/tweetpost.cpp \
    ../model/scrapbook.cpp \
    ../model/feed.cpp \
    ../model/post.cpp

HEADERS += \
    screenui.h \
    choiceui.h \
    mainmenuui.h \
    blogui.h \
    tweetui.h \
    chatui.h \
    loginui.h \
    scrapbookui.h \
    profileui.h \
    ../model/*.h
