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
    QByteArrayData data[25];
    char stringdata0[481];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_actionaddmusic_triggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 25), // "on_songControl_PB_clicked"
QT_MOC_LITERAL(4, 66, 18), // "on_prev_PB_clicked"
QT_MOC_LITERAL(5, 85, 18), // "on_next_PB_clicked"
QT_MOC_LITERAL(6, 104, 22), // "on_LoopMode_PB_clicked"
QT_MOC_LITERAL(7, 127, 21), // "onPlayBackModeChanged"
QT_MOC_LITERAL(8, 149, 28), // "QMediaPlaylist::PlaybackMode"
QT_MOC_LITERAL(9, 178, 4), // "stat"
QT_MOC_LITERAL(10, 183, 33), // "on_horizontalSlider_sliderPre..."
QT_MOC_LITERAL(11, 217, 34), // "on_horizontalSlider_sliderRel..."
QT_MOC_LITERAL(12, 252, 28), // "on_songList_LW_doubleClicked"
QT_MOC_LITERAL(13, 281, 11), // "QModelIndex"
QT_MOC_LITERAL(14, 293, 5), // "index"
QT_MOC_LITERAL(15, 299, 21), // "onCurrentMediaChanged"
QT_MOC_LITERAL(16, 321, 13), // "QMediaContent"
QT_MOC_LITERAL(17, 335, 7), // "content"
QT_MOC_LITERAL(18, 343, 28), // "onMediaPlayerPositionChanged"
QT_MOC_LITERAL(19, 372, 8), // "position"
QT_MOC_LITERAL(20, 381, 9), // "onTimeOut"
QT_MOC_LITERAL(21, 391, 24), // "on_deleteSong_PB_clicked"
QT_MOC_LITERAL(22, 416, 26), // "on_lrycis_LW_doubleClicked"
QT_MOC_LITERAL(23, 443, 25), // "pauseTimerForThreeSeconds"
QT_MOC_LITERAL(24, 469, 11) // "resumeTimer"

    },
    "MainWindow\0on_actionaddmusic_triggered\0"
    "\0on_songControl_PB_clicked\0"
    "on_prev_PB_clicked\0on_next_PB_clicked\0"
    "on_LoopMode_PB_clicked\0onPlayBackModeChanged\0"
    "QMediaPlaylist::PlaybackMode\0stat\0"
    "on_horizontalSlider_sliderPressed\0"
    "on_horizontalSlider_sliderReleased\0"
    "on_songList_LW_doubleClicked\0QModelIndex\0"
    "index\0onCurrentMediaChanged\0QMediaContent\0"
    "content\0onMediaPlayerPositionChanged\0"
    "position\0onTimeOut\0on_deleteSong_PB_clicked\0"
    "on_lrycis_LW_doubleClicked\0"
    "pauseTimerForThreeSeconds\0resumeTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    1,   99,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    1,  104,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      18,    1,  110,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,
      21,    0,  114,    2, 0x08 /* Private */,
      22,    1,  115,    2, 0x08 /* Private */,
      23,    0,  118,    2, 0x08 /* Private */,
      24,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::LongLong,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionaddmusic_triggered(); break;
        case 1: _t->on_songControl_PB_clicked(); break;
        case 2: _t->on_prev_PB_clicked(); break;
        case 3: _t->on_next_PB_clicked(); break;
        case 4: _t->on_LoopMode_PB_clicked(); break;
        case 5: _t->onPlayBackModeChanged((*reinterpret_cast< QMediaPlaylist::PlaybackMode(*)>(_a[1]))); break;
        case 6: _t->on_horizontalSlider_sliderPressed(); break;
        case 7: _t->on_horizontalSlider_sliderReleased(); break;
        case 8: _t->on_songList_LW_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->onCurrentMediaChanged((*reinterpret_cast< const QMediaContent(*)>(_a[1]))); break;
        case 10: _t->onMediaPlayerPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 11: _t->onTimeOut(); break;
        case 12: _t->on_deleteSong_PB_clicked(); break;
        case 13: _t->on_lrycis_LW_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->pauseTimerForThreeSeconds(); break;
        case 15: _t->resumeTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlaylist::PlaybackMode >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaContent >(); break;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
