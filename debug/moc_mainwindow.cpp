/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 8),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 5),
QT_MOC_LITERAL(4, 27, 16),
QT_MOC_LITERAL(5, 44, 10),
QT_MOC_LITERAL(6, 55, 6),
QT_MOC_LITERAL(7, 62, 15),
QT_MOC_LITERAL(8, 78, 13),
QT_MOC_LITERAL(9, 92, 7),
QT_MOC_LITERAL(10, 100, 18),
QT_MOC_LITERAL(11, 119, 9),
QT_MOC_LITERAL(12, 129, 25),
QT_MOC_LITERAL(13, 155, 16),
QT_MOC_LITERAL(14, 172, 6),
QT_MOC_LITERAL(15, 179, 23),
QT_MOC_LITERAL(16, 203, 23),
QT_MOC_LITERAL(17, 227, 23),
QT_MOC_LITERAL(18, 251, 22),
QT_MOC_LITERAL(19, 274, 25),
QT_MOC_LITERAL(20, 300, 4),
QT_MOC_LITERAL(21, 305, 26),
QT_MOC_LITERAL(22, 332, 4),
QT_MOC_LITERAL(23, 337, 24)
    },
    "MainWindow\0resetBox\0\0okBox\0sendSemesterName\0"
    "MyNetwork*\0myPost\0sendHolidayName\0"
    "sendClassName\0sendGPA\0updateGlobalObject\0"
    "sendEvent\0on_holidayChanges_clicked\0"
    "QAbstractButton*\0button\0on_createCourse_clicked\0"
    "on_calculateGPA_clicked\0on_createButton_clicked\0"
    "on_createEvent_clicked\0on_calendarWidget_clicked\0"
    "date\0on_eventText_linkActivated\0link\0"
    "on_eventText_linkHovered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08,
       3,    0,   95,    2, 0x08,
       4,    1,   96,    2, 0x08,
       7,    1,   99,    2, 0x08,
       8,    1,  102,    2, 0x08,
       9,    1,  105,    2, 0x08,
      10,    1,  108,    2, 0x08,
      11,    1,  111,    2, 0x08,
      12,    1,  114,    2, 0x08,
      15,    0,  117,    2, 0x08,
      16,    0,  118,    2, 0x08,
      17,    0,  119,    2, 0x08,
      18,    0,  120,    2, 0x08,
      19,    1,  121,    2, 0x08,
      21,    1,  124,    2, 0x08,
      23,    1,  127,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->resetBox(); break;
        case 1: _t->okBox(); break;
        case 2: _t->sendSemesterName((*reinterpret_cast< MyNetwork*(*)>(_a[1]))); break;
        case 3: _t->sendHolidayName((*reinterpret_cast< MyNetwork*(*)>(_a[1]))); break;
        case 4: _t->sendClassName((*reinterpret_cast< MyNetwork*(*)>(_a[1]))); break;
        case 5: _t->sendGPA((*reinterpret_cast< MyNetwork*(*)>(_a[1]))); break;
        case 6: _t->updateGlobalObject((*reinterpret_cast< MyNetwork*(*)>(_a[1]))); break;
        case 7: _t->sendEvent((*reinterpret_cast< MyNetwork*(*)>(_a[1]))); break;
        case 8: _t->on_createCourse_clicked(); break;
        case 9: _t->on_calculateGPA_clicked(); break;
        case 10: _t->on_createButton_clicked(); break;
        case 11: _t->on_createEvent_clicked(); break;
        case 12: _t->on_calendarWidget_clicked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 13: _t->on_eventText_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_eventText_linkHovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyNetwork* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyNetwork* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyNetwork* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyNetwork* >(); break;
            }
            break;
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
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
