SOURCES += \
    main.cpp \
    mywidget.cpp \
    mydialog.cpp


HEADERS += \
    mywidget.hpp \
    mydialog.hpp

QT += core gui widgets

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXX = g++-6
