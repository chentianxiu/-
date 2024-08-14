/********************************************************************************
** Form generated from reading UI file 'zuoye4.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZUOYE4_H
#define UI_ZUOYE4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zuoye4
{
public:
    QLabel *label;

    void setupUi(QWidget *zuoye4)
    {
        if (zuoye4->objectName().isEmpty())
            zuoye4->setObjectName(QString::fromUtf8("zuoye4"));
        zuoye4->resize(400, 300);
        label = new QLabel(zuoye4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 70, 151, 71));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 41);"));

        retranslateUi(zuoye4);

        QMetaObject::connectSlotsByName(zuoye4);
    } // setupUi

    void retranslateUi(QWidget *zuoye4)
    {
        zuoye4->setWindowTitle(QApplication::translate("zuoye4", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class zuoye4: public Ui_zuoye4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZUOYE4_H
