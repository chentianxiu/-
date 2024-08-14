/********************************************************************************
** Form generated from reading UI file 'mainwdiget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWDIGET_H
#define UI_MAINWDIGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWdiget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *Name_LE;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Pswd_LE;
    QCheckBox *checkBox;
    QPushButton *Login_PB;
    QPushButton *Regist_LE;

    void setupUi(QWidget *mainWdiget)
    {
        if (mainWdiget->objectName().isEmpty())
            mainWdiget->setObjectName(QString::fromUtf8("mainWdiget"));
        mainWdiget->resize(433, 431);
        verticalLayout = new QVBoxLayout(mainWdiget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(mainWdiget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        Name_LE = new QLineEdit(mainWdiget);
        Name_LE->setObjectName(QString::fromUtf8("Name_LE"));

        verticalLayout->addWidget(Name_LE);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Pswd_LE = new QLineEdit(mainWdiget);
        Pswd_LE->setObjectName(QString::fromUtf8("Pswd_LE"));

        horizontalLayout->addWidget(Pswd_LE);

        checkBox = new QCheckBox(mainWdiget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        horizontalLayout->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout);

        Login_PB = new QPushButton(mainWdiget);
        Login_PB->setObjectName(QString::fromUtf8("Login_PB"));

        verticalLayout->addWidget(Login_PB);

        Regist_LE = new QPushButton(mainWdiget);
        Regist_LE->setObjectName(QString::fromUtf8("Regist_LE"));

        verticalLayout->addWidget(Regist_LE);


        retranslateUi(mainWdiget);

        QMetaObject::connectSlotsByName(mainWdiget);
    } // setupUi

    void retranslateUi(QWidget *mainWdiget)
    {
        mainWdiget->setWindowTitle(QApplication::translate("mainWdiget", "mainWdiget", nullptr));
        label->setText(QApplication::translate("mainWdiget", "\347\231\273\345\275\225", nullptr));
        checkBox->setText(QApplication::translate("mainWdiget", "\345\257\206\347\240\201\351\232\220\350\227\217", nullptr));
        Login_PB->setText(QApplication::translate("mainWdiget", "\347\231\273\345\275\225", nullptr));
        Regist_LE->setText(QApplication::translate("mainWdiget", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWdiget: public Ui_mainWdiget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWDIGET_H
