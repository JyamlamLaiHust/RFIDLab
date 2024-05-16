/****************************************************************************
** Meta object code from reading C++ file 'serialportthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../One_Card_System/serialThread/serialportthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortThread_t {
    QByteArrayData data[12];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortThread_t qt_meta_stringdata_SerialPortThread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SerialPortThread"
QT_MOC_LITERAL(1, 17, 7), // "sendMsg"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "char*"
QT_MOC_LITERAL(4, 32, 4), // "data"
QT_MOC_LITERAL(5, 37, 8), // "frameLen"
QT_MOC_LITERAL(6, 46, 11), // "receivedMsg"
QT_MOC_LITERAL(7, 58, 13), // "wirteMsgError"
QT_MOC_LITERAL(8, 72, 3), // "msg"
QT_MOC_LITERAL(9, 76, 11), // "hasResponse"
QT_MOC_LITERAL(10, 88, 7), // "onError"
QT_MOC_LITERAL(11, 96, 9) // "stopTimer"

    },
    "SerialPortThread\0sendMsg\0\0char*\0data\0"
    "frameLen\0receivedMsg\0wirteMsgError\0"
    "msg\0hasResponse\0onError\0stopTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,
       7,    1,   52,    2, 0x06 /* Public */,
       9,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   56,    2, 0x0a /* Public */,
      11,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SerialPortThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortThread *_t = static_cast<SerialPortThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMsg((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->receivedMsg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->wirteMsgError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->hasResponse(); break;
        case 4: _t->onError(); break;
        case 5: _t->stopTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SerialPortThread::*_t)(char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortThread::sendMsg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SerialPortThread::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortThread::receivedMsg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SerialPortThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortThread::wirteMsgError)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SerialPortThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortThread::hasResponse)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SerialPortThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SerialPortThread.data,
      qt_meta_data_SerialPortThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialPortThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SerialPortThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SerialPortThread::sendMsg(char * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialPortThread::receivedMsg(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialPortThread::wirteMsgError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialPortThread::hasResponse()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
