#-------------------------------------------------
#
# Project created by QtCreator 2016-09-23T16:40:01
#
#-------------------------------------------------

QT       += core gui\
        sql\
        serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = M125KDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tools.cpp \
    database.cpp \
    recordtablemodel.cpp

HEADERS  += mainwindow.h \
    tools.h \
    database.h \
    recordtablemodel.h

FORMS    += mainwindow.ui

win32: LIBS += -L$$PWD/lib/ -lM125Dll

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
