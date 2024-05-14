/****************************************************************************
** Meta object code from reading C++ file 'registorwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../One_Card_System/pages/registor/registorwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registorwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RegistorWidget_t {
    QByteArrayData data[10];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RegistorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RegistorWidget_t qt_meta_stringdata_RegistorWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RegistorWidget"
QT_MOC_LITERAL(1, 15, 23), // "on_btn_Register_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20), // "on_btn_Reset_clicked"
QT_MOC_LITERAL(4, 61, 24), // "on_btn_Inventory_clicked"
QT_MOC_LITERAL(5, 86, 22), // "on_btn_Refresh_clicked"
QT_MOC_LITERAL(6, 109, 40), // "on_comboBox_UserType_currentI..."
QT_MOC_LITERAL(7, 150, 4), // "arg1"
QT_MOC_LITERAL(8, 155, 16), // "on_tagIdReceived"
QT_MOC_LITERAL(9, 172, 5) // "tagId"

    },
    "RegistorWidget\0on_btn_Register_clicked\0"
    "\0on_btn_Reset_clicked\0on_btn_Inventory_clicked\0"
    "on_btn_Refresh_clicked\0"
    "on_comboBox_UserType_currentIndexChanged\0"
    "arg1\0on_tagIdReceived\0tagId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegistorWidget[] = {

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
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void RegistorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RegistorWidget *_t = static_cast<RegistorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_Register_clicked(); break;
        case 1: _t->on_btn_Reset_clicked(); break;
        case 2: _t->on_btn_Inventory_clicked(); break;
        case 3: _t->on_btn_Refresh_clicked(); break;
        case 4: _t->on_comboBox_UserType_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_tagIdReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RegistorWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RegistorWidget.data,
      qt_meta_data_RegistorWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RegistorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegistorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RegistorWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RegistorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
