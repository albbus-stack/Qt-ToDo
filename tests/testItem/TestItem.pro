QT += testlib

QT -= gui

TARGET = tst_testitem
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    tst_testitem.cpp

HEADERS += \
    item.h
