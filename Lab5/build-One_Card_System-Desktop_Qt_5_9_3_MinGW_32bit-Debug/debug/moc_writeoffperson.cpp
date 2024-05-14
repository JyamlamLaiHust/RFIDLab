/****************************************************************************
** Meta object code from reading C++ file 'writeoffperson.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../One_Card_System/pages/writeoff/writeoffperson.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'writeoffperson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WriteOffPerson_t {
    QByteArrayData data[7];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WriteOffPerson_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WriteOffPerson_t qt_meta_stringdata_WriteOffPerson = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WriteOffPerson"
QT_MOC_LITERAL(1, 15, 21), // "on_btn_LogOff_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "on_btn_Return_clicked"
QT_MOC_LITERAL(4, 60, 24), // "on_btn_Inventory_clicked"
QT_MOC_LITERAL(5, 85, 16), // "on_tagIdReceived"
QT_MOC_LITERAL(6, 102, 5) // "tagId"

    },
    "WriteOffPerson\0on_btn_LogOff_clicked\0"
    "\0on_btn_Return_clicked\0on_btn_Inventory_clicked\0"
    "on_tagIdReceived\0tagId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WriteOffPerson[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void WriteOffPerson::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WriteOffPerson *_t = static_cast<WriteOffPerson *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_LogOff_clicked(); break;
        case 1: _t->on_btn_Return_clicked(); break;
        case 2: _t->on_btn_Inventory_clicked(); break;
        case 3: _t->on_tagIdReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WriteOffPerson::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WriteOffPerson.data,
      qt_meta_data_WriteOffPerson,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WriteOffPerson::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WriteOffPerson::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WriteOffPerson.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int WriteOffPerson::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
