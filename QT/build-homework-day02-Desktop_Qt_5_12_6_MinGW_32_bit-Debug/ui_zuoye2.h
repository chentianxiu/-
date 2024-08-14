/********************************************************************************
** Form generated from reading UI file 'zuoye2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZUOYE2_H
#define UI_ZUOYE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zuoye2
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *zuoye2)
    {
        if (zuoye2->objectName().isEmpty())
            zuoye2->setObjectName(QString::fromUtf8("zuoye2"));
        zuoye2->resize(400, 300);
        QFont font;
        font.setPointSize(23);
        zuoye2->setFont(font);
        verticalLayout = new QVBoxLayout(zuoye2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(zuoye2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(121, 51));
        label->setMouseTracking(false);

        verticalLayout->addWidget(label);


        retranslateUi(zuoye2);

        QMetaObject::connectSlotsByName(zuoye2);
    } // setupUi

    void retranslateUi(QWidget *zuoye2)
    {
        zuoye2->setWindowTitle(QApplication::translate("zuoye2", "Form", nullptr));
        label->setText(QApplication::translate("zuoye2", "<html><head/><body><p><span style=\" font-size:26pt;\">A</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zuoye2: public Ui_zuoye2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZUOYE2_H
