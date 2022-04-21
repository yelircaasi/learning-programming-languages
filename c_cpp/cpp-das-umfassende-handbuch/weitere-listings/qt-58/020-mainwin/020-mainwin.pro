#-------------------------------------------------
#
# Project created by QtCreator 2017-06-19T14:58:17
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = 020-mainwin
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.hpp \
    dialog.hpp

FORMS    += mainwindow.ui \
    dialog.ui

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXX = g++-6

RESOURCES += \
    icons/icons.qrc
