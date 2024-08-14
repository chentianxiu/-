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

class Ui_registWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *registWidget)
    {
        if (registWidget->objectName().isEmpty())
            registWidget->setObjectName(QString::fromUtf8("registWidget"));
        registWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(registWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(registWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(registWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(registWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        buttonBox = new QDialogButtonBox(registWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(registWidget);

        QMetaObject::connectSlotsByName(registWidget);
    } // setupUi

    void retranslateUi(QWidget *registWidget)
    {
        registWidget->setWindowTitle(QApplication::translate("registWidget", "Form", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("registWidget", "\350\256\276\347\275\256\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("registWidget", "\350\256\276\347\275\256\345\257\206\347\240\201", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("registWidget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registWidget: public Ui_registWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTWIDGET_H
