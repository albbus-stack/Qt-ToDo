#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T22:22:32
#
#-------------------------------------------------

QT       += core gui
QT +=   quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToDo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    add.cpp \
    calendar.cpp \
    edit.cpp \
    list.cpp \
    main.cpp \
    controller.cpp \
    window.cpp

HEADERS += \
    add.h \
    calendar.h \
    edit.h \
    list.h \
    item.h \
    subject.h \
    observer.h \
    controller.h \
    window.h

FORMS += \
    add.ui \
    calendar.ui \
    edit.ui \
    window.ui

RESOURCES += \
    resources.qrc
