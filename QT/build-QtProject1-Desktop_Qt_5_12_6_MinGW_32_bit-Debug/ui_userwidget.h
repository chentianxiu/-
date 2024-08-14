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

class Ui_userwidget
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *userwidget)
    {
        if (userwidget->objectName().isEmpty())
            userwidget->setObjectName(QString::fromUtf8("userwidget"));
        userwidget->resize(630, 367);
        label = new QLabel(userwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 241, 111));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        pushButton = new QPushButton(userwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 50, 80, 41));

        retranslateUi(userwidget);

        QMetaObject::connectSlotsByName(userwidget);
    } // setupUi

    void retranslateUi(QWidget *userwidget)
    {
        userwidget->setWindowTitle(QApplication::translate("userwidget", "Form", nullptr));
        label->setText(QApplication::translate("userwidget", "\347\224\250\346\210\267\347\225\214\351\235\242", nullptr));
        pushButton->setText(QApplication::translate("userwidget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userwidget: public Ui_userwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
