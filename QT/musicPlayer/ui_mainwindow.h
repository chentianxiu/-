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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionaddMusic;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *songList_LW;
    QVBoxLayout *verticalLayout;
    QLabel *songTitle_LB;
    QListWidget *lrycis_LW;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSlider;
    QLabel *SongTime_LB;
    QHBoxLayout *horizontalLayout;
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
        MainWindow->resize(800, 600);
        actionaddMusic = new QAction(MainWindow);
        actionaddMusic->setObjectName(QString::fromUtf8("actionaddMusic"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        songList_LW = new QListWidget(centralwidget);
        songList_LW->setObjectName(QString::fromUtf8("songList_LW"));

        horizontalLayout_3->addWidget(songList_LW);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        songTitle_LB = new QLabel(centralwidget);
        songTitle_LB->setObjectName(QString::fromUtf8("songTitle_LB"));

        verticalLayout->addWidget(songTitle_LB);

        lrycis_LW = new QListWidget(centralwidget);
        lrycis_LW->setObjectName(QString::fromUtf8("lrycis_LW"));

        verticalLayout->addWidget(lrycis_LW);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(1, 20);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        SongTime_LB = new QLabel(centralwidget);
        SongTime_LB->setObjectName(QString::fromUtf8("SongTime_LB"));

        horizontalLayout_2->addWidget(SongTime_LB);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        prev_PB = new QPushButton(centralwidget);
        prev_PB->setObjectName(QString::fromUtf8("prev_PB"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        prev_PB->setIcon(icon);
        prev_PB->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(prev_PB);

        songControl_PB = new QPushButton(centralwidget);
        songControl_PB->setObjectName(QString::fromUtf8("songControl_PB"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        songControl_PB->setIcon(icon1);
        songControl_PB->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(songControl_PB);

        next_PB = new QPushButton(centralwidget);
        next_PB->setObjectName(QString::fromUtf8("next_PB"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        next_PB->setIcon(icon2);
        next_PB->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(next_PB);

        LoopMode_PB = new QPushButton(centralwidget);
        LoopMode_PB->setObjectName(QString::fromUtf8("LoopMode_PB"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/loop.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoopMode_PB->setIcon(icon3);
        LoopMode_PB->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(LoopMode_PB);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(1, 2);
        verticalLayout_2->setStretch(2, 2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionaddMusic);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionaddMusic->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
        songTitle_LB->setText(QString());
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
