/********************************************************************************
** Form generated from reading UI file 'addfrienddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDDIALOG_H
#define UI_ADDFRIENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addfriendDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *addName_PB;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *selectList_LW;
    QVBoxLayout *verticalLayout;
    QPushButton *moveRight_PB;
    QSpacerItem *verticalSpacer;
    QPushButton *moveLeft_PB;
    QListWidget *addList_LW;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addfriendDialog)
    {
        if (addfriendDialog->objectName().isEmpty())
            addfriendDialog->setObjectName(QString::fromUtf8("addfriendDialog"));
        addfriendDialog->resize(372, 408);
        verticalLayout_2 = new QVBoxLayout(addfriendDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(addfriendDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        addName_PB = new QPushButton(addfriendDialog);
        addName_PB->setObjectName(QString::fromUtf8("addName_PB"));

        horizontalLayout->addWidget(addName_PB);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        selectList_LW = new QListWidget(addfriendDialog);
        selectList_LW->setObjectName(QString::fromUtf8("selectList_LW"));

        horizontalLayout_2->addWidget(selectList_LW);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        moveRight_PB = new QPushButton(addfriendDialog);
        moveRight_PB->setObjectName(QString::fromUtf8("moveRight_PB"));

        verticalLayout->addWidget(moveRight_PB);

        verticalSpacer = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moveLeft_PB = new QPushButton(addfriendDialog);
        moveLeft_PB->setObjectName(QString::fromUtf8("moveLeft_PB"));

        verticalLayout->addWidget(moveLeft_PB);


        horizontalLayout_2->addLayout(verticalLayout);

        addList_LW = new QListWidget(addfriendDialog);
        addList_LW->setObjectName(QString::fromUtf8("addList_LW"));

        horizontalLayout_2->addWidget(addList_LW);


        verticalLayout_2->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(addfriendDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(addfriendDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), addfriendDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addfriendDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(addfriendDialog);
    } // setupUi

    void retranslateUi(QDialog *addfriendDialog)
    {
        addfriendDialog->setWindowTitle(QApplication::translate("addfriendDialog", "Dialog", nullptr));
        addName_PB->setText(QApplication::translate("addfriendDialog", "\346\267\273\345\212\240", nullptr));
        moveRight_PB->setText(QApplication::translate("addfriendDialog", ">>>", nullptr));
        moveLeft_PB->setText(QApplication::translate("addfriendDialog", "<<<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addfriendDialog: public Ui_addfriendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDDIALOG_H
