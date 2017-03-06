/****************************************************************************
** Meta object code from reading C++ file 'mywidget2.h'
**
** Created: Tue Feb 28 18:15:58 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mywidget2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWidget2[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      35,   10,   10,   10, 0x08,
      54,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyWidget2[] = {
    "MyWidget2\0\0on_textchanged(QString)\0"
    "on_radio_clicked()\0on_check_clicked()\0"
};

const QMetaObject MyWidget2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidget2,
      qt_meta_data_MyWidget2, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWidget2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWidget2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWidget2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidget2))
        return static_cast<void*>(const_cast< MyWidget2*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWidget2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_textchanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_radio_clicked(); break;
        case 2: on_check_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
