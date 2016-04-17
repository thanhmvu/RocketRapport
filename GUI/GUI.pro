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
    ../model/account.cpp \
    ../model/dbmanager.cpp \
    ../model/blog.cpp \
    ../model/tweet.cpp \
    ../model/scrapbook.cpp \
    mainmenu.cpp \
    profilegui.cpp \
    bloggui.cpp \
    tweetgui.cpp \
    chatgui.cpp \
    scrapbookgui.cpp

HEADERS  += login.h\
    ../model/system.h \
    ../model/account.h \
    ../model/dbmanager.h \
    ../model/*.h \
    mainmenu.h \
    profilegui.h \
    bloggui.h \
    tweetgui.h \
    chatgui.h \
    scrapbookgui.h

FORMS    += login.ui \
    mainmenu.ui \
    profilegui.ui \
    bloggui.ui \
    tweetgui.ui \
    chatgui.ui \
    scrapbookgui.ui

RESOURCES += \
    images.qrc
