/********************************************************************************
** Form generated from reading UI file 'dairy4.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAIRY4_H
#define UI_DAIRY4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dairy4
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *dairy4)
    {
        if (dairy4->objectName().isEmpty())
            dairy4->setObjectName(QString::fromUtf8("dairy4"));
        dairy4->resize(400, 300);
        verticalLayout = new QVBoxLayout(dairy4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calendarWidget = new QCalendarWidget(dairy4);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        pushButton_2 = new QPushButton(dairy4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(dairy4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(dairy4);

        QMetaObject::connectSlotsByName(dairy4);
    } // setupUi

    void retranslateUi(QWidget *dairy4)
    {
        dairy4->setWindowTitle(QApplication::translate("dairy4", "Form", nullptr));
        pushButton_2->setText(QApplication::translate("dairy4", "close", nullptr));
        pushButton->setText(QApplication::translate("dairy4", "today", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dairy4: public Ui_dairy4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAIRY4_H
