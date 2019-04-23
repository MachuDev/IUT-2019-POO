TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    cexception.cpp \
    TestFailure.cpp

HEADERS += \
    cstcoderr.h \
    cexception.h
