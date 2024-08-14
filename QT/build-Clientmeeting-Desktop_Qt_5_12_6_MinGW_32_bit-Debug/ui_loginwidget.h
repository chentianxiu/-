/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameinput_LE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *pswdinput_LE;
    QVBoxLayout *verticalLayout;
    QPushButton *login_PB;
    QPushButton *regist_PB;

    void setupUi(QWidget *loginwidget)
    {
        if (loginwidget->objectName().isEmpty())
            loginwidget->setObjectName(QString::fromUtf8("loginwidget"));
        loginwidget->resize(311, 214);
        verticalLayout_2 = new QVBoxLayout(loginwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(loginwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameinput_LE = new QLineEdit(loginwidget);
        nameinput_LE->setObjectName(QString::fromUtf8("nameinput_LE"));

        horizontalLayout->addWidget(nameinput_LE);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(loginwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pswdinput_LE = new QLineEdit(loginwidget);
        pswdinput_LE->setObjectName(QString::fromUtf8("pswdinput_LE"));

        horizontalLayout_2->addWidget(pswdinput_LE);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        login_PB = new QPushButton(loginwidget);
        login_PB->setObjectName(QString::fromUtf8("login_PB"));

        verticalLayout->addWidget(login_PB);

        regist_PB = new QPushButton(loginwidget);
        regist_PB->setObjectName(QString::fromUtf8("regist_PB"));

        verticalLayout->addWidget(regist_PB);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(loginwidget);

        QMetaObject::connectSlotsByName(loginwidget);
    } // setupUi

    void retranslateUi(QWidget *loginwidget)
    {
        loginwidget->setWindowTitle(QApplication::translate("loginwidget", "Form", nullptr));
        label->setText(QApplication::translate("loginwidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("loginwidget", "\345\257\206\347\240\201", nullptr));
        login_PB->setText(QApplication::translate("loginwidget", "\347\231\273\345\275\225", nullptr));
        regist_PB->setText(QApplication::translate("loginwidget", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwidget: public Ui_loginwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
