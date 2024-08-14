/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customlistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionaddmusic;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QListWidget *songList_LW;
    QPushButton *deleteSong_PB;
    QVBoxLayout *verticalLayout;
    QLabel *songTitle_LB;
    CustomListWidget *lrycis_LW;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSlider;
    QLabel *SongTime_LB;
    QSplitter *splitter;
    QPushButton *prev_PB;
    QPushButton *songControl_PB;
    QPushButton *next_PB;
    QPushButton *LoopMode_PB;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 600);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionaddmusic = new QAction(MainWindow);
        actionaddmusic->setObjectName(QString::fromUtf8("actionaddmusic"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        songList_LW = new QListWidget(centralwidget);
        songList_LW->setObjectName(QString::fromUtf8("songList_LW"));

        verticalLayout_2->addWidget(songList_LW);

        deleteSong_PB = new QPushButton(centralwidget);
        deleteSong_PB->setObjectName(QString::fromUtf8("deleteSong_PB"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteSong_PB->setIcon(icon);

        verticalLayout_2->addWidget(deleteSong_PB);

        verticalLayout_2->setStretch(0, 8);
        verticalLayout_2->setStretch(1, 2);

        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        songTitle_LB = new QLabel(centralwidget);
        songTitle_LB->setObjectName(QString::fromUtf8("songTitle_LB"));
        songTitle_LB->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(songTitle_LB);

        lrycis_LW = new CustomListWidget(centralwidget);
        lrycis_LW->setObjectName(QString::fromUtf8("lrycis_LW"));
        lrycis_LW->setFocusPolicy(Qt::StrongFocus);

        verticalLayout->addWidget(lrycis_LW);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        SongTime_LB = new QLabel(centralwidget);
        SongTime_LB->setObjectName(QString::fromUtf8("SongTime_LB"));

        horizontalLayout_2->addWidget(SongTime_LB);


        verticalLayout_3->addLayout(horizontalLayout_2);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        prev_PB = new QPushButton(splitter);
        prev_PB->setObjectName(QString::fromUtf8("prev_PB"));
        prev_PB->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        prev_PB->setIcon(icon1);
        prev_PB->setIconSize(QSize(30, 30));
        splitter->addWidget(prev_PB);
        songControl_PB = new QPushButton(splitter);
        songControl_PB->setObjectName(QString::fromUtf8("songControl_PB"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        songControl_PB->setIcon(icon2);
        songControl_PB->setIconSize(QSize(30, 30));
        splitter->addWidget(songControl_PB);
        next_PB = new QPushButton(splitter);
        next_PB->setObjectName(QString::fromUtf8("next_PB"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        next_PB->setIcon(icon3);
        next_PB->setIconSize(QSize(30, 30));
        splitter->addWidget(next_PB);
        LoopMode_PB = new QPushButton(splitter);
        LoopMode_PB->setObjectName(QString::fromUtf8("LoopMode_PB"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/loop.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoopMode_PB->setIcon(icon4);
        LoopMode_PB->setIconSize(QSize(30, 30));
        splitter->addWidget(LoopMode_PB);

        verticalLayout_3->addWidget(splitter);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 17));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionaddmusic);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionaddmusic->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
        deleteSong_PB->setText(QString());
        songTitle_LB->setText(QApplication::translate("MainWindow", "\346\255\214\346\233\262\344\277\241\346\201\257", nullptr));
        SongTime_LB->setText(QApplication::translate("MainWindow", "00:00/00:00", nullptr));
        prev_PB->setText(QString());
        songControl_PB->setText(QString());
        next_PB->setText(QString());
        LoopMode_PB->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
