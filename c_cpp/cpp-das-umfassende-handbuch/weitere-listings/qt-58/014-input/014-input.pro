SOURCES += \
    main.cpp \
    mywidget.cpp


HEADERS += \
    mywidget.hpp

QT += core gui widgets

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXX = g++-6
