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
    QAction *actionadd_file;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *LW_song;
    QListWidget *LW_irc;
    QLabel *LA_name;
    QHBoxLayout *horizontalLayout_2;
    QSlider *HS_time;
    QLabel *LA_time;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PB_previous;
    QPushButton *PB_status;
    QPushButton *PB_next;
    QPushButton *PB_switch;
    QMenuBar *menubar;
    QMenu *Menu_top1;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionadd_file = new QAction(MainWindow);
        actionadd_file->setObjectName(QString::fromUtf8("actionadd_file"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        LW_song = new QListWidget(centralwidget);
        LW_song->setObjectName(QString::fromUtf8("LW_song"));
        LW_song->setMinimumSize(QSize(0, 0));
        LW_song->setMaximumSize(QSize(220, 16777215));

        horizontalLayout->addWidget(LW_song);

        LW_irc = new QListWidget(centralwidget);
        LW_irc->setObjectName(QString::fromUtf8("LW_irc"));

        horizontalLayout->addWidget(LW_irc);


        verticalLayout->addLayout(horizontalLayout);

        LA_name = new QLabel(centralwidget);
        LA_name->setObjectName(QString::fromUtf8("LA_name"));
        LA_name->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(LA_name);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 5, -1, 5);
        HS_time = new QSlider(centralwidget);
        HS_time->setObjectName(QString::fromUtf8("HS_time"));
        HS_time->setMaximum(500);
        HS_time->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(HS_time);

        LA_time = new QLabel(centralwidget);
        LA_time->setObjectName(QString::fromUtf8("LA_time"));

        horizontalLayout_2->addWidget(LA_time);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 10, -1, 10);
        PB_previous = new QPushButton(centralwidget);
        PB_previous->setObjectName(QString::fromUtf8("PB_previous"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        PB_previous->setIcon(icon);

        horizontalLayout_3->addWidget(PB_previous);

        PB_status = new QPushButton(centralwidget);
        PB_status->setObjectName(QString::fromUtf8("PB_status"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        PB_status->setIcon(icon1);

        horizontalLayout_3->addWidget(PB_status);

        PB_next = new QPushButton(centralwidget);
        PB_next->setObjectName(QString::fromUtf8("PB_next"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        PB_next->setIcon(icon2);

        horizontalLayout_3->addWidget(PB_next);

        PB_switch = new QPushButton(centralwidget);
        PB_switch->setObjectName(QString::fromUtf8("PB_switch"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/loop.png"), QSize(), QIcon::Normal, QIcon::Off);
        PB_switch->setIcon(icon3);

        horizontalLayout_3->addWidget(PB_switch);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Menu_top1 = new QMenu(menubar);
        Menu_top1->setObjectName(QString::fromUtf8("Menu_top1"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(Menu_top1->menuAction());
        Menu_top1->addAction(actionadd_file);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionadd_file->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266", nullptr));
#ifndef QT_NO_TOOLTIP
        actionadd_file->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
        LA_name->setText(QString());
        LA_time->setText(QApplication::translate("MainWindow", "00:00/00:00", nullptr));
        PB_previous->setText(QString());
        PB_status->setText(QString());
        PB_next->setText(QString());
        PB_switch->setText(QString());
        Menu_top1->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
