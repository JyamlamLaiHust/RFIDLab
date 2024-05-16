#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T08:33:44
#
#-------------------------------------------------

QT       += core gui serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1356M
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    usermanage.cpp \
    booksmanage.cpp \
    tools.cpp \
    sqlite.cpp \
    uhf_thread.cpp \
    borrow_return.cpp \
    record.cpp \
    m1356dll.cpp

HEADERS  += widget.h \
    usermanage.h \
    booksmanage.h \
    inc/m1356dll.h \
    inc/m1356dll_global.h \
    tools.h \
    sqlite.h \
    uhf_thread.h \
    borrow_return.h \
    record.h \
    m1356dll_global.h \
    m1356dll.h



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lM1356Dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lM1356Dlld
else:unix: LIBS += -L$$PWD/lib/ -lM1356Dll

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libM1356Dll.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libM1356Dlld.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/M1356Dll.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/M1356Dlld.lib
else:unix: PRE_TARGETDEPS += $$PWD/lib/libM1356Dll.a

RESOURCES += \
    1356m.qrc
