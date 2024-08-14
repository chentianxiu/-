/****************************************************************************
** Meta object code from reading C++ file 'client_socket_handler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Servermeeting/client_socket_handler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client_socket_handler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client_socket_handler_t {
    QByteArrayData data[20];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client_socket_handler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client_socket_handler_t qt_meta_stringdata_client_socket_handler = {
    {
QT_MOC_LITERAL(0, 0, 21), // "client_socket_handler"
QT_MOC_LITERAL(1, 22, 10), // "privateMsg"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "recver"
QT_MOC_LITERAL(4, 41, 15), // "messageProtocal"
QT_MOC_LITERAL(5, 57, 4), // "pack"
QT_MOC_LITERAL(6, 62, 8), // "groupMsg"
QT_MOC_LITERAL(7, 71, 9), // "groupname"
QT_MOC_LITERAL(8, 81, 10), // "addFriends"
QT_MOC_LITERAL(9, 92, 18), // "clientDisconnected"
QT_MOC_LITERAL(10, 111, 4), // "name"
QT_MOC_LITERAL(11, 116, 11), // "privateFile"
QT_MOC_LITERAL(12, 128, 9), // "groupFile"
QT_MOC_LITERAL(13, 138, 11), // "creategroup"
QT_MOC_LITERAL(14, 150, 13), // "createMeeting"
QT_MOC_LITERAL(15, 164, 11), // "joinMeeting"
QT_MOC_LITERAL(16, 176, 11), // "QTcpSocket*"
QT_MOC_LITERAL(17, 188, 4), // "user"
QT_MOC_LITERAL(18, 193, 11), // "onReadyRead"
QT_MOC_LITERAL(19, 205, 14) // "onDisconnected"

    },
    "client_socket_handler\0privateMsg\0\0"
    "recver\0messageProtocal\0pack\0groupMsg\0"
    "groupname\0addFriends\0clientDisconnected\0"
    "name\0privateFile\0groupFile\0creategroup\0"
    "createMeeting\0joinMeeting\0QTcpSocket*\0"
    "user\0onReadyRead\0onDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client_socket_handler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       6,    2,   74,    2, 0x06 /* Public */,
       8,    1,   79,    2, 0x06 /* Public */,
       9,    1,   82,    2, 0x06 /* Public */,
      11,    2,   85,    2, 0x06 /* Public */,
      12,    2,   90,    2, 0x06 /* Public */,
      13,    1,   95,    2, 0x06 /* Public */,
      14,    1,   98,    2, 0x06 /* Public */,
      15,    2,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  106,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    7,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    7,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 4,   17,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void client_socket_handler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<client_socket_handler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->privateMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 1: _t->groupMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 2: _t->addFriends((*reinterpret_cast< messageProtocal(*)>(_a[1]))); break;
        case 3: _t->clientDisconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->privateFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 5: _t->groupFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 6: _t->creategroup((*reinterpret_cast< messageProtocal(*)>(_a[1]))); break;
        case 7: _t->createMeeting((*reinterpret_cast< messageProtocal(*)>(_a[1]))); break;
        case 8: _t->joinMeeting((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 9: _t->onReadyRead(); break;
        case 10: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (client_socket_handler::*)(QString , messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::privateMsg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (client_socket_handler::*)(QString , messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::groupMsg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (client_socket_handler::*)(messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::addFriends)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (client_socket_handler::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::clientDisconnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (client_socket_handler::*)(QString , messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::privateFile)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (client_socket_handler::*)(QString , messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::groupFile)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (client_socket_handler::*)(messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::creategroup)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (client_socket_handler::*)(messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::createMeeting)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (client_socket_handler::*)(QTcpSocket * , messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client_socket_handler::joinMeeting)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client_socket_handler::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_client_socket_handler.data,
    qt_meta_data_client_socket_handler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *client_socket_handler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client_socket_handler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client_socket_handler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int client_socket_handler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void client_socket_handler::privateMsg(QString _t1, messageProtocal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void client_socket_handler::groupMsg(QString _t1, messageProtocal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void client_socket_handler::addFriends(messageProtocal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void client_socket_handler::clientDisconnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void client_socket_handler::privateFile(QString _t1, messageProtocal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void client_socket_handler::groupFile(QString _t1, messageProtocal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void client_socket_handler::creategroup(messageProtocal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void client_socket_handler::createMeeting(messageProtocal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void client_socket_handler::joinMeeting(QTcpSocket * _t1, messageProtocal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
