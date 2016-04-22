#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T01:16:39
#
#-------------------------------------------------
CONFIG += console C++11
QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp\
    ../model/system.cpp \
    ../model/chat.cpp \
    ../model/message.cpp \
    ../model/account.cpp \
    ../model/group.cpp \
    ../model/dbmanager.cpp \
    ../model/blog.cpp \
    ../model/blogpost.cpp \
    ../model/tweet.cpp \
    ../model/tweetpost.cpp \
    ../model/scrapbook.cpp \
    ../model/comment.cpp \
    ../model/feed.cpp \
    ../model/post.cpp \
    mainmenu.cpp \
    profilegui.cpp \
    bloggui.cpp \
    tweetgui.cpp \
    chatgui.cpp \
    scrapbookgui.cpp \
    groupgui.cpp

HEADERS  += login.h\
    ../model/*.h \
    mainmenu.h \
    profilegui.h \
    bloggui.h \
    tweetgui.h \
    chatgui.h \
    scrapbookgui.h \
    groupgui.h

FORMS    += login.ui \
    mainmenu.ui \
    profilegui.ui \
    bloggui.ui \
    tweetgui.ui \
    chatgui.ui \
    scrapbookgui.ui \
    groupgui.ui

RESOURCES += \
    images.qrc
