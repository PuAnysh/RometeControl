#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T09:31:13
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RemoteControl_client
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


SOURCES += main.cpp\
        widget.cpp \
    controlwidget.cpp \
    tcppasswd.cpp \
    client/algo.cpp \
    client/cmdthread.cpp \
    client/controlpanel.cpp \
    client/mapthread.cpp \
    client/values.cpp

HEADERS  += widget.h \
    controlwidget.h \
    tcppasswd.h \
    client/algo.h \
    client/cmdthread.h \
    client/consts.h \
    client/controlpanel.h \
    client/mapthread.h \
    client/values.h

#LIBS     +=User32.LIB

