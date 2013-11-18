/****************************************************************************
** Meta object code from reading C++ file 'welcomepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../welcomepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'welcomepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WelcomePage_t {
    QByteArrayData data[13];
    char stringdata[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WelcomePage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WelcomePage_t qt_meta_stringdata_WelcomePage = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 18),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 17),
QT_MOC_LITERAL(4, 50, 21),
QT_MOC_LITERAL(5, 72, 25),
QT_MOC_LITERAL(6, 98, 26),
QT_MOC_LITERAL(7, 125, 25),
QT_MOC_LITERAL(8, 151, 7),
QT_MOC_LITERAL(9, 159, 10),
QT_MOC_LITERAL(10, 170, 6),
QT_MOC_LITERAL(11, 177, 7),
QT_MOC_LITERAL(12, 185, 28)
    },
    "WelcomePage\0on_credits_clicked\0\0"
    "on_signIn_clicked\0on_pushButton_clicked\0"
    "on_forgetPassword_clicked\0"
    "on_createAnAccount_clicked\0"
    "on_password_returnPressed\0doThis1\0"
    "MyNetwork*\0myPost\0doThis2\0"
    "on_submitInCreateAcc_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WelcomePage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08,
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    0,   62,    2, 0x08,
       6,    0,   63,    2, 0x08,
       7,    0,   64,    2, 0x08,
       8,    1,   65,    2, 0x08,
      11,    1,   68,    2, 0x08,
      12,    0,   71,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void WelcomePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WelcomePage *_t = static_cast<WelcomePage *>(_o);
        switch (_id) {
        case 0: _t->on_credits_clicked(); break;
        case 1: _t->on_signIn_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_forgetPassword_clicked(); break;
        case 4: _t->on_createAnAccount_clicked(); break;
        case 5: _t->on_password_returnPressed(); break;
        case 6: _t->doThis1((*reinterpret_cast< MyNetwork*(*)>(_a[1]))); break;
        case 7: _t->doThis2((*reinterpret_cast< MyNetwork*(*)>(_a[1]))); break;
        case 8: _t->on_submitInCreateAcc_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyNetwork* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyNetwork* >(); break;
            }
            break;
        }
    }
}

const QMetaObject WelcomePage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WelcomePage.data,
      qt_meta_data_WelcomePage,  qt_static_metacall, 0, 0}
};


const QMetaObject *WelcomePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WelcomePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WelcomePage.stringdata))
        return static_cast<void*>(const_cast< WelcomePage*>(this));
    return QDialog::qt_metacast(_clname);
}

int WelcomePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
