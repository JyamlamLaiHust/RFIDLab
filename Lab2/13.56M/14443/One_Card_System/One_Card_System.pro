#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T16:12:15
#
#-------------------------------------------------

QT       += core gui \
        sql\
        serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = One_Card_System
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    database/registertablemodel.cpp \
    database/writeofftablemodel.cpp \
    database/recordtablemodel.cpp \
    database/persontablemodel.cpp \
    database/dbmanager.cpp \
    tools/tools.cpp \
    pages/welcom/mainpage.cpp \
    pages/tables/tableinfopages.cpp \
    pages/login/loginpage.cpp \
    database/admintablemodel.cpp \
    pages/registor/registorwidget.cpp \
    serialThread/serialportthread.cpp \
    pages/connect/settingsdialog.cpp \
    pages/export/exportdatas.cpp \
    pages/changepwd/changepassword.cpp \
    pages/writeoff/writeoffperson.cpp \
    pages/consume/consumepage.cpp \
    pages/registor/dialogcardconfig.cpp \
    pages/recharge/rechargedialog.cpp \
    database/rechargetablemodel.cpp

HEADERS  += mainwindow.h \
    database/database_api.h \
    database/registertablemodel.h \
    database/writeofftablemodel.h \
    database/recordtablemodel.h \
    database/persontablemodel.h \
    database/dbmanager.h \
    tools/tools.h \
    pages/welcom/mainpage.h \
    pages/tables/tableinfopages.h \
    pages/pages.h \
    pages/login/loginpage.h \
    database/admintablemodel.h \
    pages/registor/registorwidget.h \
    serialThread/serialportthread.h \
    pages/connect/settingsdialog.h \
    inc/m1356dll.h \
    inc/m1356dll_global.h \
    pages/export/exportdatas.h \
    pages/changepwd/changepassword.h \
    pages/writeoff/writeoffperson.h \
    pages/consume/consumepage.h \
    pages/registor/dialogcardconfig.h \
    pages/recharge/rechargedialog.h \
    database/rechargetablemodel.h

FORMS    += mainwindow.ui \
    pages/welcom/mainpage.ui \
    pages/tables/tableinfopages.ui \
    pages/login/loginpage.ui \
    pages/registor/registorwidget.ui \
    pages/connect/settingsdialog.ui \
    pages/export/exportdatas.ui \
    pages/changepwd/changepassword.ui \
    pages/writeoff/writeoffperson.ui \
    pages/consume/consumepage.ui \
    pages/registor/dialogcardconfig.ui \
    pages/recharge/rechargedialog.ui

RC_FILE = OneCard.rc
OTHER_FILES += OneCard.rc

RESOURCES += \
    resource/res.qrc

QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

win32: LIBS += -L$$PWD/lib/ -lM1356Dll

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/M1356Dll.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/lib/libM1356Dll.a
