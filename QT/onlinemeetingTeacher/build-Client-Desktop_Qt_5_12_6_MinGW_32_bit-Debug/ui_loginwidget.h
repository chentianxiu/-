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

class Ui_LoginWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameInput_LE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *pswdInput_LE;
    QPushButton *login_PB;
    QPushButton *regist_PB;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(359, 126);
        verticalLayout = new QVBoxLayout(LoginWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LoginWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameInput_LE = new QLineEdit(LoginWidget);
        nameInput_LE->setObjectName(QString::fromUtf8("nameInput_LE"));

        horizontalLayout->addWidget(nameInput_LE);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(LoginWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pswdInput_LE = new QLineEdit(LoginWidget);
        pswdInput_LE->setObjectName(QString::fromUtf8("pswdInput_LE"));

        horizontalLayout_2->addWidget(pswdInput_LE);


        verticalLayout->addLayout(horizontalLayout_2);

        login_PB = new QPushButton(LoginWidget);
        login_PB->setObjectName(QString::fromUtf8("login_PB"));

        verticalLayout->addWidget(login_PB);

        regist_PB = new QPushButton(LoginWidget);
        regist_PB->setObjectName(QString::fromUtf8("regist_PB"));

        verticalLayout->addWidget(regist_PB);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "Form", nullptr));
        label->setText(QApplication::translate("LoginWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("LoginWidget", "\345\257\206\347\240\201", nullptr));
        login_PB->setText(QApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        regist_PB->setText(QApplication::translate("LoginWidget", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
