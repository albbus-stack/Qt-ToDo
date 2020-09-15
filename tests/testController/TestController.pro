QT += testlib

QT -= gui

TARGET = tst_testcontroller
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    tst_testcontroller.cpp \
    controller.cpp \
    list.cpp

HEADERS += \
    headers\controller.h \
    headers\list.h
