/****************************************************************************
** Meta object code from reading C++ file 'dialogcardconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pages/registor/dialogcardconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogcardconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogCardConfig_t {
    QByteArrayData data[12];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogCardConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogCardConfig_t qt_meta_stringdata_DialogCardConfig = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DialogCardConfig"
QT_MOC_LITERAL(1, 17, 37), // "on_lineEdit_Pwd_cursorPositio..."
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 4), // "arg1"
QT_MOC_LITERAL(4, 61, 4), // "arg2"
QT_MOC_LITERAL(5, 66, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(6, 86, 7), // "checked"
QT_MOC_LITERAL(7, 94, 19), // "on_btn_Init_clicked"
QT_MOC_LITERAL(8, 114, 22), // "on_btn_MemData_clicked"
QT_MOC_LITERAL(9, 137, 13), // "onDecodeFrame"
QT_MOC_LITERAL(10, 151, 5), // "bytes"
QT_MOC_LITERAL(11, 157, 21) // "on_btn_Return_clicked"

    },
    "DialogCardConfig\0on_lineEdit_Pwd_cursorPositionChanged\0"
    "\0arg1\0arg2\0on_checkBox_clicked\0checked\0"
    "on_btn_Init_clicked\0on_btn_MemData_clicked\0"
    "onDecodeFrame\0bytes\0on_btn_Return_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogCardConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x08 /* Private */,
       5,    1,   49,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,
       9,    1,   54,    2, 0x08 /* Private */,
      11,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void,

       0        // eod
};

void DialogCardConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogCardConfig *_t = static_cast<DialogCardConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_lineEdit_Pwd_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_btn_Init_clicked(); break;
        case 3: _t->on_btn_MemData_clicked(); break;
        case 4: _t->onDecodeFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->on_btn_Return_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject DialogCardConfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogCardConfig.data,
      qt_meta_data_DialogCardConfig,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogCardConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogCardConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogCardConfig.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogCardConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
