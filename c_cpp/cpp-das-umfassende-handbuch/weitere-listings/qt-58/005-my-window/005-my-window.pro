SOURCES += \
    main.cpp \
    my_window.cpp


HEADERS += \
    my_window.hpp

QT += core gui widgets

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXX = g++-6
