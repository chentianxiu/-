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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreat_New;
    QAction *actionSave_as;
    QAction *actionPencil;
    QAction *actionLine;
    QAction *actionRect;
    QAction *actionEillpse;
    QAction *actionPloygon;
    QAction *actionSet_Color;
    QAction *actionSet_Width;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *FileMenu;
    QMenu *ToolsMenu;
    QMenu *PenSetMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionCreat_New = new QAction(MainWindow);
        actionCreat_New->setObjectName(QString::fromUtf8("actionCreat_New"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionPencil = new QAction(MainWindow);
        actionPencil->setObjectName(QString::fromUtf8("actionPencil"));
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        actionRect = new QAction(MainWindow);
        actionRect->setObjectName(QString::fromUtf8("actionRect"));
        actionEillpse = new QAction(MainWindow);
        actionEillpse->setObjectName(QString::fromUtf8("actionEillpse"));
        actionPloygon = new QAction(MainWindow);
        actionPloygon->setObjectName(QString::fromUtf8("actionPloygon"));
        actionSet_Color = new QAction(MainWindow);
        actionSet_Color->setObjectName(QString::fromUtf8("actionSet_Color"));
        actionSet_Width = new QAction(MainWindow);
        actionSet_Width->setObjectName(QString::fromUtf8("actionSet_Width"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        FileMenu = new QMenu(menubar);
        FileMenu->setObjectName(QString::fromUtf8("FileMenu"));
        ToolsMenu = new QMenu(menubar);
        ToolsMenu->setObjectName(QString::fromUtf8("ToolsMenu"));
        PenSetMenu = new QMenu(menubar);
        PenSetMenu->setObjectName(QString::fromUtf8("PenSetMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(FileMenu->menuAction());
        menubar->addAction(ToolsMenu->menuAction());
        menubar->addAction(PenSetMenu->menuAction());
        FileMenu->addAction(actionCreat_New);
        FileMenu->addAction(actionSave_as);
        ToolsMenu->addAction(actionPencil);
        ToolsMenu->addAction(actionLine);
        ToolsMenu->addAction(actionRect);
        ToolsMenu->addAction(actionEillpse);
        ToolsMenu->addAction(actionPloygon);
        PenSetMenu->addAction(actionSet_Color);
        PenSetMenu->addAction(actionSet_Width);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCreat_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
        actionSave_as->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        actionPencil->setText(QApplication::translate("MainWindow", "\351\223\205\347\254\224", nullptr));
        actionLine->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277", nullptr));
        actionRect->setText(QApplication::translate("MainWindow", "\347\237\251\345\275\242", nullptr));
        actionEillpse->setText(QApplication::translate("MainWindow", "\346\244\255\345\234\206\345\275\242", nullptr));
        actionPloygon->setText(QApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242", nullptr));
        actionSet_Color->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\347\224\273\347\254\224\351\242\234\350\211\262", nullptr));
        actionSet_Width->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\347\224\273\347\254\224\347\262\227\347\273\206", nullptr));
        FileMenu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        ToolsMenu->setTitle(QApplication::translate("MainWindow", "\347\273\230\345\210\266\345\267\245\345\205\267", nullptr));
        PenSetMenu->setTitle(QApplication::translate("MainWindow", "\347\224\273\347\254\224\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
