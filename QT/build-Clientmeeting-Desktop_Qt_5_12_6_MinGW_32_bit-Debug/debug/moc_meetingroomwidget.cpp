/****************************************************************************
** Meta object code from reading C++ file 'meetingroomwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Clientmeeting/meetingroomwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'meetingroomwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_meetingRoomWidget_t {
    QByteArrayData data[14];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_meetingRoomWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_meetingRoomWidget_t qt_meta_stringdata_meetingRoomWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "meetingRoomWidget"
QT_MOC_LITERAL(1, 18, 21), // "on_sendMsg_PB_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 25), // "on_camera_cb_stateChanged"
QT_MOC_LITERAL(4, 67, 4), // "arg1"
QT_MOC_LITERAL(5, 72, 19), // "on_TextmsgReadyRead"
QT_MOC_LITERAL(6, 92, 15), // "on_videoChanged"
QT_MOC_LITERAL(7, 108, 11), // "QVideoFrame"
QT_MOC_LITERAL(8, 120, 8), // "curframe"
QT_MOC_LITERAL(9, 129, 12), // "on_setPixmap"
QT_MOC_LITERAL(10, 142, 5), // "image"
QT_MOC_LITERAL(11, 148, 22), // "on_mic_cb_stateChanged"
QT_MOC_LITERAL(12, 171, 21), // "captureDataFromDevice"
QT_MOC_LITERAL(13, 193, 11) // "onReadyRead"

    },
    "meetingRoomWidget\0on_sendMsg_PB_clicked\0"
    "\0on_camera_cb_stateChanged\0arg1\0"
    "on_TextmsgReadyRead\0on_videoChanged\0"
    "QVideoFrame\0curframe\0on_setPixmap\0"
    "image\0on_mic_cb_stateChanged\0"
    "captureDataFromDevice\0onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_meetingRoomWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    1,   59,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QImage,   10,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void meetingRoomWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<meetingRoomWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sendMsg_PB_clicked(); break;
        case 1: _t->on_camera_cb_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_TextmsgReadyRead(); break;
        case 3: _t->on_videoChanged((*reinterpret_cast< QVideoFrame(*)>(_a[1]))); break;
        case 4: _t->on_setPixmap((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->on_mic_cb_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->captureDataFromDevice(); break;
        case 7: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoFrame >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject meetingRoomWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_meetingRoomWidget.data,
    qt_meta_data_meetingRoomWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *meetingRoomWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *meetingRoomWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_meetingRoomWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int meetingRoomWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
