/********************************************************************************
** Form generated from reading UI file 'quest5.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEST5_H
#define UI_QUEST5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_quest5
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *quest5)
    {
        if (quest5->objectName().isEmpty())
            quest5->setObjectName(QString::fromUtf8("quest5"));
        quest5->resize(400, 300);
        verticalLayout = new QVBoxLayout(quest5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(quest5);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(quest5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(quest5);

        QMetaObject::connectSlotsByName(quest5);
    } // setupUi

    void retranslateUi(QWidget *quest5)
    {
        quest5->setWindowTitle(QApplication::translate("quest5", "Form", nullptr));
        label->setText(QApplication::translate("quest5", "time", nullptr));
        pushButton->setText(QApplication::translate("quest5", "\346\214\211\344\270\213\344\274\232\345\207\272\347\216\260\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class quest5: public Ui_quest5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEST5_H
