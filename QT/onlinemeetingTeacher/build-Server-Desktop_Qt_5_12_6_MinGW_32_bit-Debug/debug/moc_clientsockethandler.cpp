/****************************************************************************
** Meta object code from reading C++ file 'clientsockethandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/clientsockethandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientsockethandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_clientSocketHandler_t {
    QByteArrayData data[12];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_clientSocketHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_clientSocketHandler_t qt_meta_stringdata_clientSocketHandler = {
    {
QT_MOC_LITERAL(0, 0, 19), // "clientSocketHandler"
QT_MOC_LITERAL(1, 20, 10), // "privateMsg"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "recver"
QT_MOC_LITERAL(4, 39, 15), // "messageProtocal"
QT_MOC_LITERAL(5, 55, 4), // "pack"
QT_MOC_LITERAL(6, 60, 11), // "privateFile"
QT_MOC_LITERAL(7, 72, 13), // "createMeeting"
QT_MOC_LITERAL(8, 86, 11), // "joinMeeting"
QT_MOC_LITERAL(9, 98, 11), // "QTcpSocket*"
QT_MOC_LITERAL(10, 110, 4), // "user"
QT_MOC_LITERAL(11, 115, 11) // "onReadyRead"

    },
    "clientSocketHandler\0privateMsg\0\0recver\0"
    "messageProtocal\0pack\0privateFile\0"
    "createMeeting\0joinMeeting\0QTcpSocket*\0"
    "user\0onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clientSocketHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    2,   44,    2, 0x06 /* Public */,
       7,    1,   49,    2, 0x06 /* Public */,
       8,    2,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 4,   10,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void clientSocketHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<clientSocketHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->privateMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 1: _t->privateFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 2: _t->createMeeting((*reinterpret_cast< messageProtocal(*)>(_a[1]))); break;
        case 3: _t->joinMeeting((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< messageProtocal(*)>(_a[2]))); break;
        case 4: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
            using _t = void (clientSocketHandler::*)(QString , messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&clientSocketHandler::privateMsg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (clientSocketHandler::*)(QString , messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&clientSocketHandler::privateFile)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (clientSocketHandler::*)(messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&clientSocketHandler::createMeeting)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (clientSocketHandler::*)(QTcpSocket * , messageProtocal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&clientSocketHandler::joinMeeting)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject clientSocketHandler::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_clientSocketHandler.data,
    qt_meta_data_clientSocketHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *clientSocketHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clientSocketHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_clientSocketHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int clientSocketHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void clientSocketHandler::privateMsg(QString _t1, messageProtocal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void clientSocketHandler::privateFile(QString _t1, messageProtocal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void clientSocketHandler::createMeeting(messageProtocal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void clientSocketHandler::joinMeeting(QTcpSocket * _t1, messageProtocal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
