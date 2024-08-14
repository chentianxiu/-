/********************************************************************************
** Form generated from reading UI file 'quest6.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEST6_H
#define UI_QUEST6_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_quest6
{
public:
    QVBoxLayout *verticalLayout;
    QSlider *verticalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *quest6)
    {
        if (quest6->objectName().isEmpty())
            quest6->setObjectName(QString::fromUtf8("quest6"));
        quest6->resize(400, 300);
        verticalLayout = new QVBoxLayout(quest6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSlider = new QSlider(quest6);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(verticalSlider);

        spinBox = new QSpinBox(quest6);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout->addWidget(spinBox);


        retranslateUi(quest6);

        QMetaObject::connectSlotsByName(quest6);
    } // setupUi

    void retranslateUi(QWidget *quest6)
    {
        quest6->setWindowTitle(QApplication::translate("quest6", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class quest6: public Ui_quest6 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEST6_H
