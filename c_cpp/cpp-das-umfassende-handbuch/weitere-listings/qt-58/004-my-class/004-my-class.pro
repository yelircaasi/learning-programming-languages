SOURCES += \
    my_class.cpp \
    main.cpp


HEADERS += \
    my_class.hpp

QT += core gui widgets

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXX = g++-6
