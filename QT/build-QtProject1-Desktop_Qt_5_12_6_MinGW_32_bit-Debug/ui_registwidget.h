/********************************************************************************
** Form generated from reading UI file 'registwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTWIDGET_H
#define UI_REGISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registwidget
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *username;
    QLineEdit *pwd;
    QLineEdit *pwd2;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *registwidget)
    {
        if (registwidget->objectName().isEmpty())
            registwidget->setObjectName(QString::fromUtf8("registwidget"));
        registwidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(registwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        username = new QLineEdit(registwidget);
        username->setObjectName(QString::fromUtf8("username"));

        verticalLayout->addWidget(username);

        pwd = new QLineEdit(registwidget);
        pwd->setObjectName(QString::fromUtf8("pwd"));

        verticalLayout->addWidget(pwd);

        pwd2 = new QLineEdit(registwidget);
        pwd2->setObjectName(QString::fromUtf8("pwd2"));

        verticalLayout->addWidget(pwd2);

        buttonBox = new QDialogButtonBox(registwidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(registwidget);

        QMetaObject::connectSlotsByName(registwidget);
    } // setupUi

    void retranslateUi(QWidget *registwidget)
    {
        registwidget->setWindowTitle(QApplication::translate("registwidget", "Form", nullptr));
        username->setPlaceholderText(QApplication::translate("registwidget", "\350\256\276\347\275\256\347\224\250\346\210\267\345\220\215", nullptr));
        pwd->setPlaceholderText(QApplication::translate("registwidget", "\350\256\276\347\275\256\345\257\206\347\240\201", nullptr));
        pwd2->setPlaceholderText(QApplication::translate("registwidget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registwidget: public Ui_registwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTWIDGET_H
