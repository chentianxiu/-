/********************************************************************************
** Form generated from reading UI file 'regist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regist
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameinput_LE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *pswdinput_LE;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *rpswdinput_LE;
    QPushButton *regist_PB;

    void setupUi(QWidget *regist)
    {
        if (regist->objectName().isEmpty())
            regist->setObjectName(QString::fromUtf8("regist"));
        regist->resize(349, 175);
        verticalLayout = new QVBoxLayout(regist);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(regist);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameinput_LE = new QLineEdit(regist);
        nameinput_LE->setObjectName(QString::fromUtf8("nameinput_LE"));

        horizontalLayout->addWidget(nameinput_LE);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(regist);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pswdinput_LE = new QLineEdit(regist);
        pswdinput_LE->setObjectName(QString::fromUtf8("pswdinput_LE"));

        horizontalLayout_2->addWidget(pswdinput_LE);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(regist);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        rpswdinput_LE = new QLineEdit(regist);
        rpswdinput_LE->setObjectName(QString::fromUtf8("rpswdinput_LE"));

        horizontalLayout_3->addWidget(rpswdinput_LE);


        verticalLayout->addLayout(horizontalLayout_3);

        regist_PB = new QPushButton(regist);
        regist_PB->setObjectName(QString::fromUtf8("regist_PB"));

        verticalLayout->addWidget(regist_PB);


        retranslateUi(regist);

        QMetaObject::connectSlotsByName(regist);
    } // setupUi

    void retranslateUi(QWidget *regist)
    {
        regist->setWindowTitle(QApplication::translate("regist", "Form", nullptr));
        label->setText(QApplication::translate("regist", "\345\241\253\345\206\231\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("regist", "\345\241\253\345\206\231\345\257\206\347\240\201", nullptr));
        label_3->setText(QApplication::translate("regist", "\351\207\215\345\244\215\345\257\206\347\240\201", nullptr));
        regist_PB->setText(QApplication::translate("regist", "\347\241\256\350\256\244\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regist: public Ui_regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
