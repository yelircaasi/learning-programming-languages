SOURCES += \
    meinwidget.cpp \
    main.cpp

FORMS += \
    meinwidget.ui

HEADERS += \
    meinwidget.h

QT += core gui widgets

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXX = g++-6
