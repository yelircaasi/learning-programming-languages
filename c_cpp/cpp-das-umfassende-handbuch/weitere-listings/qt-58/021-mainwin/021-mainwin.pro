SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dialog.cpp

HEADERS += \
    mainwindow.hpp \
    dialog.hpp

FORMS += \
    dialog.ui

RESOURCES += \
    icons.qrc

QT += core gui widgets

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXX = g++-6

