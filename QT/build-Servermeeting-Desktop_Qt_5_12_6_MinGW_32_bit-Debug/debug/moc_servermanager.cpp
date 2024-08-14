/****************************************************************************
** Meta object code from reading C++ file 'servermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Servermeeting/servermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_servermanager_t {
    QByteArrayData data[19];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_servermanager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_servermanager_t qt_meta_stringdata_servermanager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "servermanager"
QT_MOC_LITERAL(1, 14, 15), // "onNewConnection"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "onPrivateMsg"
QT_MOC_LITERAL(4, 44, 6), // "recver"
QT_MOC_LITERAL(5, 51, 15), // "messageProtocal"
QT_MOC_LITERAL(6, 67, 4), // "pack"
QT_MOC_LITERAL(7, 72, 10), // "ongroupMsg"
QT_MOC_LITERAL(8, 83, 9), // "groupname"
QT_MOC_LITERAL(9, 93, 20), // "onClientDisconnected"
QT_MOC_LITERAL(10, 114, 4), // "name"
QT_MOC_LITERAL(11, 119, 12), // "onaddFriends"
QT_MOC_LITERAL(12, 132, 13), // "onPrivateFile"
QT_MOC_LITERAL(13, 146, 11), // "ongroupFile"
QT_MOC_LITERAL(14, 158, 13), // "oncreategroup"
QT_MOC_LITERAL(15, 172, 15), // "onCreateMeeting"
QT_MOC_LITERAL(16, 188, 13), // "onJoinMeeting"
QT_MOC_LITERAL(17, 202, 11), // "QTcpSocket*"
QT_MOC_LITERAL(18, 214, 4) // "user"

    },
    "servermanager\0onNewConnection\0\0"
    "onPrivateMsg\0recver\0messageProtocal\0"
    "pack\0ongroupMsg\0groupname\0"
    "onClientDisconnected\0name\0onaddFriends\0"
    "onPrivateFile\0ongroupFile\0oncreategroup\0"
    "onCreateMeeting\0onJoinMeeting\0QTcpSocket*\0"
    "user"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_servermanager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    2,   65,    2, 0x0a /* Public */,
       7,    2,   70,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x0a /* Public */,
      11,    1,   78,    2, 0x0a /* Public */,
      12,    2,   81,    2, 0x0a /* Public */,
      13,    2,   86,    2, 0x0a /* Public */,
      14,    1,   91,    2, 0x0a /* Public */,
      15,    1,   94,    2, 0x0a /* Public */,
      16,    2,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    8,    6,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    8,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 5,   18,    6,

       0        // eod
};

void servermanager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<servermanager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewConnection(); break;
        case 1: _t->onPrivateMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 2: _t->ongroupMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 3: _t->onClientDisconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onaddFriends((*reinterpret_cast< messageProtocal(*)>(_a[1]))); break;
        case 5: _t->onPrivateFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 6: _t->ongroupFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 7: _t->oncreategroup((*reinterpret_cast< messageProtocal(*)>(_a[1]))); break;
        case 8: _t->onCreateMeeting((*reinterpret_cast< messageProtocal(*)>(_a[1]))); break;
        case 9: _t->onJoinMeeting((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject servermanager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_servermanager.data,
    qt_meta_data_servermanager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *servermanager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *servermanager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_servermanager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int servermanager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
