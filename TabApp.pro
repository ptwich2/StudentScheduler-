#-------------------------------------------------
#
# Project created by QtCreator 2013-10-18T11:30:32
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TabApp
TEMPLATE = app


SOURCES += main.cpp\
        home.cpp \
    welcomepage.cpp \
    mainwindow.cpp \
    mynetwork.cpp \
    event.cpp

HEADERS  += home.h \
    welcomepage.h \
    mainwindow.h \
    mynetwork.h \
    event.h

FORMS    += home.ui \
    welcomepage.ui \
    mainwindow.ui \
    event.ui
