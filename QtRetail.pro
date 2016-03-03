#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T12:24:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtRetail
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sqlite3.c

HEADERS  += mainwindow.h \
    sqlite3ext.h \
    sqlite3.h

FORMS    += mainwindow.ui

LIBS += -lpthread
LIBS += -ldl


