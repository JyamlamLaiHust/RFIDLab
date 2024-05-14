#-------------------------------------------------
#
# Project created by QtCreator 2016-08-29T14:27:22
#
#-------------------------------------------------

QT       += core gui serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 900M
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    uhf_thread.cpp \
    sqlite.cpp \
    tools.cpp \
    regist_widget.cpp

HEADERS  += widget.h \
    inc/m900dll.h \
    inc/m900dll_global.h \
    uhf_thread.h \
    widget_text.h \
    sqlite.h \
    tools.h \
    regist_widget.h

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lM900Dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lM900Dlld
else:unix: LIBS += -L$$PWD/lib/ -lM900Dll

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libM900Dll.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libM900Dlld.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/M900Dll.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/M900Dlld.lib
else:unix: PRE_TARGETDEPS += $$PWD/lib/libM900Dll.a

RESOURCES += \
    900m.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lM900Dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lM900Dlld
else:unix: LIBS += -L$$PWD/lib/ -lM900Dll

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/libM900Dll.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/libM900Dlld.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/M900Dll.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/M900Dlld.lib
else:unix: PRE_TARGETDEPS += $$PWD/lib/libM900Dll.a
