/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[435];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_actionadd_file_triggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 18), // "on_currentSongShow"
QT_MOC_LITERAL(4, 59, 13), // "QMediaContent"
QT_MOC_LITERAL(5, 73, 7), // "content"
QT_MOC_LITERAL(6, 81, 21), // "on_currentSongLrcShow"
QT_MOC_LITERAL(7, 103, 4), // "name"
QT_MOC_LITERAL(8, 108, 25), // "on_currentSongLrcLineShow"
QT_MOC_LITERAL(9, 134, 20), // "on_PB_status_clicked"
QT_MOC_LITERAL(10, 155, 22), // "on_PB_previous_clicked"
QT_MOC_LITERAL(11, 178, 18), // "on_PB_next_clicked"
QT_MOC_LITERAL(12, 197, 20), // "on_PB_switch_clicked"
QT_MOC_LITERAL(13, 218, 19), // "on_PB_switchChanged"
QT_MOC_LITERAL(14, 238, 28), // "QMediaPlaylist::PlaybackMode"
QT_MOC_LITERAL(15, 267, 4), // "stat"
QT_MOC_LITERAL(16, 272, 24), // "on_HS_time_sliderPressed"
QT_MOC_LITERAL(17, 297, 25), // "on_HS_time_sliderReleased"
QT_MOC_LITERAL(18, 323, 23), // "on_MediaPositionChanged"
QT_MOC_LITERAL(19, 347, 8), // "position"
QT_MOC_LITERAL(20, 356, 28), // "on_LW_song_itemDoubleClicked"
QT_MOC_LITERAL(21, 385, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(22, 402, 4), // "item"
QT_MOC_LITERAL(23, 407, 27) // "on_LW_irc_itemDoubleClicked"

    },
    "MainWindow\0on_actionadd_file_triggered\0"
    "\0on_currentSongShow\0QMediaContent\0"
    "content\0on_currentSongLrcShow\0name\0"
    "on_currentSongLrcLineShow\0"
    "on_PB_status_clicked\0on_PB_previous_clicked\0"
    "on_PB_next_clicked\0on_PB_switch_clicked\0"
    "on_PB_switchChanged\0QMediaPlaylist::PlaybackMode\0"
    "stat\0on_HS_time_sliderPressed\0"
    "on_HS_time_sliderReleased\0"
    "on_MediaPositionChanged\0position\0"
    "on_LW_song_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_LW_irc_itemDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    1,   85,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    1,   96,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,
      17,    0,  100,    2, 0x08 /* Private */,
      18,    1,  101,    2, 0x08 /* Private */,
      20,    1,  104,    2, 0x08 /* Private */,
      23,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionadd_file_triggered(); break;
        case 1: _t->on_currentSongShow((*reinterpret_cast< QMediaContent(*)>(_a[1]))); break;
        case 2: _t->on_currentSongLrcShow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_currentSongLrcLineShow(); break;
        case 4: _t->on_PB_status_clicked(); break;
        case 5: _t->on_PB_previous_clicked(); break;
        case 6: _t->on_PB_next_clicked(); break;
        case 7: _t->on_PB_switch_clicked(); break;
        case 8: _t->on_PB_switchChanged((*reinterpret_cast< QMediaPlaylist::PlaybackMode(*)>(_a[1]))); break;
        case 9: _t->on_HS_time_sliderPressed(); break;
        case 10: _t->on_HS_time_sliderReleased(); break;
        case 11: _t->on_MediaPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 12: _t->on_LW_song_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 13: _t->on_LW_irc_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaContent >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlaylist::PlaybackMode >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
