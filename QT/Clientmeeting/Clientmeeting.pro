QT       += core gui
QT       += network

QT       += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

CONFIG += mobility

MOBILITY += multimedia

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfrienddialog.cpp \
    creategroupdialog.cpp \
    createmeetingdialog.cpp \
    groupchatwidget.cpp \
    loginwidget.cpp \
    main.cpp \
    meetingroomwidget.cpp \
    menuwidget.cpp \
    messageprotocal.cpp \
    privatechatwidget.cpp \
    regist.cpp \
    videorecver.cpp \
    videosurface.cpp \
    widget.cpp

HEADERS += \
    AudioPack.h \
    addfrienddialog.h \
    creategroupdialog.h \
    createmeetingdialog.h \
    groupchatwidget.h \
    loginwidget.h \
    meetingroomwidget.h \
    menuwidget.h \
    messageprotocal.h \
    pack.h \
    privatechatwidget.h \
    regist.h \
    videorecver.h \
    videosurface.h \
    widget.h

FORMS += \
    addfrienddialog.ui \
    creategroupdialog.ui \
    createmeetingdialog.ui \
    groupchatwidget.ui \
    loginwidget.ui \
    meetingroomwidget.ui \
    menuwidget.ui \
    privatechatwidget.ui \
    regist.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
