TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += sql

SOURCES += main.cpp \
    testscripting.cpp \
    systemunittest.cpp \
    dbtoolunittest.cpp \
    ../model/dbtool.cpp \
    ../model/dbtablerranch.cpp \
    ../model/dbtable.cpp \
    dbtabletest.cpp

INCLUDEPATH += googletest                       \
               googletest/src                   \
               googletest/src/gtest             \
               googletest/include               \
               googletest/include/gtest         \
               googletest/include/gtest/internal

LIBS +=  -L/usr/lib -Wall -Wextra -pthread

SOURCES += "googletest/src/gtest.cc"            \
           "googletest/src/gtest-death-test.cc" \
           "googletest/src/gtest-filepath.cc"   \
           "googletest/src/gtest-port.cc"       \
           "googletest/src/gtest-printers.cc"   \
           "googletest/src/gtest-test-part.cc"  \
           "googletest/src/gtest-typed-test.cc"

HEADERS += \
    ../model/system.h \
    ../model/dbtool.h \
    ../model/dbtable.h

LIBS += -l sqlite3

