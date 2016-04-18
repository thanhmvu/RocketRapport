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
    profileui.cpp

HEADERS += \
    screenui.h \
    choiceui.h \
    mainmenuui.h \
    blogui.h \
    tweetui.h \
    chatui.h \
    loginui.h \
    scrapbookui.h \
    profileui.h
