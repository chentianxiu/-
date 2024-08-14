/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWidget
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *UserWidget)
    {
        if (UserWidget->objectName().isEmpty())
            UserWidget->setObjectName(QString::fromUtf8("UserWidget"));
        UserWidget->resize(908, 604);
        label = new QLabel(UserWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 80, 431, 161));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        pushButton = new QPushButton(UserWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(810, 10, 75, 23));

        retranslateUi(UserWidget);

        QMetaObject::connectSlotsByName(UserWidget);
    } // setupUi

    void retranslateUi(QWidget *UserWidget)
    {
        UserWidget->setWindowTitle(QApplication::translate("UserWidget", "Form", nullptr));
        label->setText(QApplication::translate("UserWidget", "\347\224\250\346\210\267\347\225\214\351\235\242", nullptr));
        pushButton->setText(QApplication::translate("UserWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWidget: public Ui_UserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
