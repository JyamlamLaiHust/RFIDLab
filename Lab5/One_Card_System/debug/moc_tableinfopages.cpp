/****************************************************************************
** Meta object code from reading C++ file 'tableinfopages.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pages/tables/tableinfopages.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableinfopages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TableInfoPages_t {
    QByteArrayData data[14];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TableInfoPages_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TableInfoPages_t qt_meta_stringdata_TableInfoPages = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TableInfoPages"
QT_MOC_LITERAL(1, 15, 20), // "on_btn_Query_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "currentAction"
QT_MOC_LITERAL(4, 51, 8), // "QAction*"
QT_MOC_LITERAL(5, 60, 6), // "action"
QT_MOC_LITERAL(6, 67, 15), // "updateTableView"
QT_MOC_LITERAL(7, 83, 15), // "QSqlTableModel*"
QT_MOC_LITERAL(8, 99, 5), // "model"
QT_MOC_LITERAL(9, 105, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(10, 137, 4), // "text"
QT_MOC_LITERAL(11, 142, 24), // "on_btn_Enventory_clicked"
QT_MOC_LITERAL(12, 167, 16), // "on_tagIdReceived"
QT_MOC_LITERAL(13, 184, 5) // "tagId"

    },
    "TableInfoPages\0on_btn_Query_clicked\0"
    "\0currentAction\0QAction*\0action\0"
    "updateTableView\0QSqlTableModel*\0model\0"
    "on_comboBox_currentIndexChanged\0text\0"
    "on_btn_Enventory_clicked\0on_tagIdReceived\0"
    "tagId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableInfoPages[] = {

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
       3,    1,   45,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       9,    1,   51,    2, 0x08 /* Private */,
      11,    0,   54,    2, 0x08 /* Private */,
      12,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void TableInfoPages::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TableInfoPages *_t = static_cast<TableInfoPages *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_Query_clicked(); break;
        case 1: _t->currentAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->updateTableView((*reinterpret_cast< QSqlTableModel*(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_btn_Enventory_clicked(); break;
        case 5: _t->on_tagIdReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSqlTableModel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject TableInfoPages::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TableInfoPages.data,
      qt_meta_data_TableInfoPages,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TableInfoPages::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableInfoPages::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TableInfoPages.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TableInfoPages::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
