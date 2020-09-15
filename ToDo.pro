QT       += core gui
QT +=   quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToDo
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

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
