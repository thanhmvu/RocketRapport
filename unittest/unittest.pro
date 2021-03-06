TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += sql

SOURCES += main.cpp \
    testscripting.cpp \
    systemunittest.cpp \
    ../model/system.cpp\
    ../model/dbmanager.cpp\
    ../model/account.cpp\
    ../model/group.cpp\
    ../model/scrapbook.cpp\
    ../model/scrapbookpost.cpp \
    ../model/tweet.cpp\
    ../model/tweetpost.cpp \
    ../model/comment.cpp \
    ../model/blog.cpp \
    ../model/blogpost.cpp \
    ../model/chat.cpp \
    ../model/message.cpp \
    ../model/feed.cpp \
    ../model/post.cpp \
    dbmanagertest.cpp \
    accounttest.cpp \
    chattest.cpp \
    blogtest.cpp \
    tweettest.cpp \
    feedtest.cpp \
    grouptest.cpp

INCLUDEPATH += googletest                       \
               googletest/src                   \
               googletest/src/gtest             \
               googletest/include               \
               googletest/include/gtest         \
               googletest/include/gtest/internal

SOURCES += "googletest/src/gtest.cc"            \
           "googletest/src/gtest-death-test.cc" \
           "googletest/src/gtest-filepath.cc"   \
           "googletest/src/gtest-port.cc"       \
           "googletest/src/gtest-printers.cc"   \
           "googletest/src/gtest-test-part.cc"  \
           "googletest/src/gtest-typed-test.cc"

LIBS +=  -L/usr/lib -Wall -Wextra -pthread

LIBS += -l sqlite3



HEADERS += \
    ../model/system.h \
    ../model/dbmanager.h\
    ../model/account.h\
    ../model/scrapbook.h\
    ../model/tweet.h\
    ../model/blog.h\
    ../model/chat.h \
    ../model/*.h \


