#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T17:02:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = launch
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++11 

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        coordinates.cpp \
        terrain.cpp \
        map.cpp \
        game.cpp \
	settler.cpp \
        building.cpp \
        house.cpp \
        tree.cpp \
        warehouse.cpp

HEADERS += \
        mainwindow.h \
        coordinates.h \
        terrain.h \
        map.h \
        game.h \
	settler.h \
        building.h \
        house.h \
        tree.h \
        warehouse.h

FORMS +=
