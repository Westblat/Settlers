/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameWindow_t {
    QByteArrayData data[16];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWindow_t qt_meta_stringdata_GameWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameWindow"
QT_MOC_LITERAL(1, 11, 12), // "ShowMainMenu"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "refresh"
QT_MOC_LITERAL(4, 33, 12), // "moveSettlers"
QT_MOC_LITERAL(5, 46, 16), // "refreshBuildings"
QT_MOC_LITERAL(6, 63, 18), // "selectBuildingType"
QT_MOC_LITERAL(7, 82, 4), // "type"
QT_MOC_LITERAL(8, 87, 15), // "getSiteLocation"
QT_MOC_LITERAL(9, 103, 1), // "x"
QT_MOC_LITERAL(10, 105, 1), // "y"
QT_MOC_LITERAL(11, 107, 6), // "cancel"
QT_MOC_LITERAL(12, 114, 11), // "giveCommand"
QT_MOC_LITERAL(13, 126, 1), // "n"
QT_MOC_LITERAL(14, 128, 13), // "selectCommand"
QT_MOC_LITERAL(15, 142, 3) // "cmd"

    },
    "GameWindow\0ShowMainMenu\0\0refresh\0"
    "moveSettlers\0refreshBuildings\0"
    "selectBuildingType\0type\0getSiteLocation\0"
    "x\0y\0cancel\0giveCommand\0n\0selectCommand\0"
    "cmd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWindow[] = {

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
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    1,   63,    2, 0x0a /* Public */,
       8,    2,   66,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,
      12,    1,   72,    2, 0x0a /* Public */,
      14,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void GameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameWindow *_t = static_cast<GameWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowMainMenu(); break;
        case 1: _t->refresh(); break;
        case 2: _t->moveSettlers(); break;
        case 3: _t->refreshBuildings(); break;
        case 4: _t->selectBuildingType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->getSiteLocation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->cancel(); break;
        case 7: _t->giveCommand((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->selectCommand((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GameWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameWindow.data,
      qt_meta_data_GameWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow.stringdata0))
        return static_cast<void*>(const_cast< GameWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
