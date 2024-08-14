/********************************************************************************
** Form generated from reading UI file 'childwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILDWINDOW_H
#define UI_CHILDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_childWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuchild;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *childWindow)
    {
        if (childWindow->objectName().isEmpty())
            childWindow->setObjectName(QString::fromUtf8("childWindow"));
        childWindow->resize(334, 273);
        centralwidget = new QWidget(childWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 80, 80, 71));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 80, 80, 71));
        childWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(childWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 334, 17));
        menuchild = new QMenu(menubar);
        menuchild->setObjectName(QString::fromUtf8("menuchild"));
        childWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(childWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        childWindow->setStatusBar(statusbar);

        menubar->addAction(menuchild->menuAction());

        retranslateUi(childWindow);

        QMetaObject::connectSlotsByName(childWindow);
    } // setupUi

    void retranslateUi(QMainWindow *childWindow)
    {
        childWindow->setWindowTitle(QApplication::translate("childWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("childWindow", "back", nullptr));
        pushButton_2->setText(QApplication::translate("childWindow", "close", nullptr));
        menuchild->setTitle(QApplication::translate("childWindow", "child", nullptr));
    } // retranslateUi

};

namespace Ui {
    class childWindow: public Ui_childWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILDWINDOW_H
