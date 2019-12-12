/****************************************************************************
** Meta object code from reading C++ file 'addnewobjectdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CourseWorkOOP/addnewobjectdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addnewobjectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddNewObjectDialog_t {
    QByteArrayData data[8];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddNewObjectDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddNewObjectDialog_t qt_meta_stringdata_AddNewObjectDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AddNewObjectDialog"
QT_MOC_LITERAL(1, 19, 37), // "on_openFileExplorerPushButton..."
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 29), // "on_addMoviePushButton_clicked"
QT_MOC_LITERAL(4, 88, 27), // "on_cancelPushButton_clicked"
QT_MOC_LITERAL(5, 116, 37), // "on_setDescriptionTextEdit_tex..."
QT_MOC_LITERAL(6, 154, 30), // "on_setNameTextEdit_textChanged"
QT_MOC_LITERAL(7, 185, 4) // "arg1"

    },
    "AddNewObjectDialog\0"
    "on_openFileExplorerPushButton_clicked\0"
    "\0on_addMoviePushButton_clicked\0"
    "on_cancelPushButton_clicked\0"
    "on_setDescriptionTextEdit_textChanged\0"
    "on_setNameTextEdit_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddNewObjectDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void AddNewObjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddNewObjectDialog *_t = static_cast<AddNewObjectDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_openFileExplorerPushButton_clicked(); break;
        case 1: _t->on_addMoviePushButton_clicked(); break;
        case 2: _t->on_cancelPushButton_clicked(); break;
        case 3: _t->on_setDescriptionTextEdit_textChanged(); break;
        case 4: _t->on_setNameTextEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AddNewObjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddNewObjectDialog.data,
      qt_meta_data_AddNewObjectDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AddNewObjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddNewObjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddNewObjectDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddNewObjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
