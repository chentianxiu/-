/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[399];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_actionaddMusic_triggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 25), // "on_songControl_PB_clicked"
QT_MOC_LITERAL(4, 66, 18), // "on_next_PB_clicked"
QT_MOC_LITERAL(5, 85, 18), // "on_prev_PB_clicked"
QT_MOC_LITERAL(6, 104, 21), // "onCurrentMediaChanged"
QT_MOC_LITERAL(7, 126, 13), // "QMediaContent"
QT_MOC_LITERAL(8, 140, 7), // "content"
QT_MOC_LITERAL(9, 148, 22), // "on_LoopMode_PB_clicked"
QT_MOC_LITERAL(10, 171, 21), // "onPlayBackModeChanged"
QT_MOC_LITERAL(11, 193, 28), // "QMediaPlaylist::PlaybackMode"
QT_MOC_LITERAL(12, 222, 4), // "stat"
QT_MOC_LITERAL(13, 227, 28), // "onMediaPlayerPositionChanged"
QT_MOC_LITERAL(14, 256, 8), // "position"
QT_MOC_LITERAL(15, 265, 34), // "on_horizontalSlider_sliderRel..."
QT_MOC_LITERAL(16, 300, 33), // "on_horizontalSlider_sliderPre..."
QT_MOC_LITERAL(17, 334, 32), // "on_songList_LW_itemDoubleClicked"
QT_MOC_LITERAL(18, 367, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(19, 384, 4), // "item"
QT_MOC_LITERAL(20, 389, 9) // "onTimeOut"

    },
    "MainWindow\0on_actionaddMusic_triggered\0"
    "\0on_songControl_PB_clicked\0"
    "on_next_PB_clicked\0on_prev_PB_clicked\0"
    "onCurrentMediaChanged\0QMediaContent\0"
    "content\0on_LoopMode_PB_clicked\0"
    "onPlayBackModeChanged\0"
    "QMediaPlaylist::PlaybackMode\0stat\0"
    "onMediaPlayerPositionChanged\0position\0"
    "on_horizontalSlider_sliderReleased\0"
    "on_horizontalSlider_sliderPressed\0"
    "on_songList_LW_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0onTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    1,   82,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,
      15,    0,   88,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,
      17,    1,   90,    2, 0x08 /* Private */,
      20,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionaddMusic_triggered(); break;
        case 1: _t->on_songControl_PB_clicked(); break;
        case 2: _t->on_next_PB_clicked(); break;
        case 3: _t->on_prev_PB_clicked(); break;
        case 4: _t->onCurrentMediaChanged((*reinterpret_cast< const QMediaContent(*)>(_a[1]))); break;
        case 5: _t->on_LoopMode_PB_clicked(); break;
        case 6: _t->onPlayBackModeChanged((*reinterpret_cast< QMediaPlaylist::PlaybackMode(*)>(_a[1]))); break;
        case 7: _t->onMediaPlayerPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSlider_sliderReleased(); break;
        case 9: _t->on_horizontalSlider_sliderPressed(); break;
        case 10: _t->on_songList_LW_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->onTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaContent >(); break;
            }
            break;
        case 6:
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
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
