/****************************************************************************
** Meta object code from reading C++ file 'rechargedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pages/recharge/rechargedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rechargedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RechargeDialog_t {
    QByteArrayData data[12];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RechargeDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RechargeDialog_t qt_meta_stringdata_RechargeDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RechargeDialog"
QT_MOC_LITERAL(1, 15, 7), // "calcOps"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "on_cardIdReceived"
QT_MOC_LITERAL(4, 42, 5), // "tagId"
QT_MOC_LITERAL(5, 48, 23), // "on_btn_recharge_clicked"
QT_MOC_LITERAL(6, 72, 21), // "on_btn_return_clicked"
QT_MOC_LITERAL(7, 94, 20), // "on_btn_clear_clicked"
QT_MOC_LITERAL(8, 115, 24), // "on_btn_inventory_clicked"
QT_MOC_LITERAL(9, 140, 12), // "on_readValue"
QT_MOC_LITERAL(10, 153, 13), // "onDecodeFrame"
QT_MOC_LITERAL(11, 167, 5) // "bytes"

    },
    "RechargeDialog\0calcOps\0\0on_cardIdReceived\0"
    "tagId\0on_btn_recharge_clicked\0"
    "on_btn_return_clicked\0on_btn_clear_clicked\0"
    "on_btn_inventory_clicked\0on_readValue\0"
    "onDecodeFrame\0bytes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RechargeDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   57,    2, 0x0a /* Public */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::QByteArray,   11,

       0        // eod
};

void RechargeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RechargeDialog *_t = static_cast<RechargeDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->calcOps((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->on_cardIdReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_btn_recharge_clicked(); break;
        case 3: _t->on_btn_return_clicked(); break;
        case 4: _t->on_btn_clear_clicked(); break;
        case 5: _t->on_btn_inventory_clicked(); break;
        case 6: _t->on_readValue((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->onDecodeFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RechargeDialog::*_t)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RechargeDialog::calcOps)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RechargeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RechargeDialog.data,
      qt_meta_data_RechargeDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RechargeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RechargeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RechargeDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RechargeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void RechargeDialog::calcOps(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
