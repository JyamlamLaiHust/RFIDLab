/****************************************************************************
** Meta object code from reading C++ file 'consumepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pages/consume/consumepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consumepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConsumePage_t {
    QByteArrayData data[22];
    char stringdata0[370];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConsumePage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConsumePage_t qt_meta_stringdata_ConsumePage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ConsumePage"
QT_MOC_LITERAL(1, 12, 7), // "calcOps"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "updateTime"
QT_MOC_LITERAL(4, 32, 17), // "on_cardIdReceived"
QT_MOC_LITERAL(5, 50, 5), // "tagId"
QT_MOC_LITERAL(6, 56, 13), // "onDecodeFrame"
QT_MOC_LITERAL(7, 70, 5), // "bytes"
QT_MOC_LITERAL(8, 76, 17), // "on_btn_OK_clicked"
QT_MOC_LITERAL(9, 94, 10), // "readCardId"
QT_MOC_LITERAL(10, 105, 7), // "clicked"
QT_MOC_LITERAL(11, 113, 43), // "on_comboBox_supermarket_curre..."
QT_MOC_LITERAL(12, 157, 5), // "index"
QT_MOC_LITERAL(13, 163, 18), // "on_btn_OK2_clicked"
QT_MOC_LITERAL(14, 182, 18), // "on_btn_OK1_clicked"
QT_MOC_LITERAL(15, 201, 18), // "on_btn_OK3_clicked"
QT_MOC_LITERAL(16, 220, 12), // "on_readValue"
QT_MOC_LITERAL(17, 233, 5), // "value"
QT_MOC_LITERAL(18, 239, 6), // "cardId"
QT_MOC_LITERAL(19, 246, 40), // "on_comboBox_foodName_currentI..."
QT_MOC_LITERAL(20, 287, 41), // "on_comboBox_goodsName_current..."
QT_MOC_LITERAL(21, 329, 40) // "on_comboBox_castType_currentI..."

    },
    "ConsumePage\0calcOps\0\0updateTime\0"
    "on_cardIdReceived\0tagId\0onDecodeFrame\0"
    "bytes\0on_btn_OK_clicked\0readCardId\0"
    "clicked\0on_comboBox_supermarket_currentIndexChanged\0"
    "index\0on_btn_OK2_clicked\0on_btn_OK1_clicked\0"
    "on_btn_OK3_clicked\0on_readValue\0value\0"
    "cardId\0on_comboBox_foodName_currentIndexChanged\0"
    "on_comboBox_goodsName_currentIndexChanged\0"
    "on_comboBox_castType_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConsumePage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   87,    2, 0x0a /* Public */,
       4,    1,   88,    2, 0x0a /* Public */,
       6,    1,   91,    2, 0x0a /* Public */,
       8,    0,   94,    2, 0x08 /* Private */,
       9,    1,   95,    2, 0x08 /* Private */,
      11,    1,   98,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    2,  104,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,
      20,    1,  112,    2, 0x08 /* Private */,
      21,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void ConsumePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConsumePage *_t = static_cast<ConsumePage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->calcOps((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->updateTime(); break;
        case 2: _t->on_cardIdReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onDecodeFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->on_btn_OK_clicked(); break;
        case 5: _t->readCardId((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_supermarket_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_btn_OK2_clicked(); break;
        case 8: _t->on_btn_OK1_clicked(); break;
        case 9: _t->on_btn_OK3_clicked(); break;
        case 10: _t->on_readValue((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->on_comboBox_foodName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_comboBox_goodsName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_comboBox_castType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ConsumePage::*_t)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConsumePage::calcOps)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ConsumePage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConsumePage.data,
      qt_meta_data_ConsumePage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConsumePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConsumePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConsumePage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ConsumePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ConsumePage::calcOps(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
