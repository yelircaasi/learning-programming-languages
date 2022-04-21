SOURCES += \
    main.cpp \
    dialog.cpp

FORMS += \
    dialog.ui

HEADERS += \
    dialog.hpp

QT += core gui widgets

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXX = g++-6
