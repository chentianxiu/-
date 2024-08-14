/****************************************************************************
** Meta object code from reading C++ file 'servermananger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/servermananger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servermananger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerMananger_t {
    QByteArrayData data[12];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerMananger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerMananger_t qt_meta_stringdata_ServerMananger = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ServerMananger"
QT_MOC_LITERAL(1, 15, 15), // "onNewConnection"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "onPrivateMsg"
QT_MOC_LITERAL(4, 45, 6), // "recver"
QT_MOC_LITERAL(5, 52, 15), // "messageProtocal"
QT_MOC_LITERAL(6, 68, 4), // "pack"
QT_MOC_LITERAL(7, 73, 13), // "onPrivateFile"
QT_MOC_LITERAL(8, 87, 15), // "onCreateMeeting"
QT_MOC_LITERAL(9, 103, 13), // "onJoinMeeting"
QT_MOC_LITERAL(10, 117, 11), // "QTcpSocket*"
QT_MOC_LITERAL(11, 129, 4) // "user"

    },
    "ServerMananger\0onNewConnection\0\0"
    "onPrivateMsg\0recver\0messageProtocal\0"
    "pack\0onPrivateFile\0onCreateMeeting\0"
    "onJoinMeeting\0QTcpSocket*\0user"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerMananger[] = {

 // content:
       8,       // revision
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
       3,    2,   40,    2, 0x08 /* Private */,
       7,    2,   45,    2, 0x08 /* Private */,
       8,    1,   50,    2, 0x08 /* Private */,
       9,    2,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 5,   11,    6,

       0        // eod
};

void ServerMananger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerMananger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewConnection(); break;
        case 1: _t->onPrivateMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 2: _t->onPrivateFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 3: _t->onCreateMeeting((*reinterpret_cast< messageProtocal(*)>(_a[1]))); break;
        case 4: _t->onJoinMeeting((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerMananger::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ServerMananger.data,
    qt_meta_data_ServerMananger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ServerMananger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerMananger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerMananger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerMananger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
