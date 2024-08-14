/********************************************************************************
** Form generated from reading UI file 'creategroupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUPDIALOG_H
#define UI_CREATEGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateGroupDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *groupName_LE;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *selectList_LW;
    QVBoxLayout *verticalLayout;
    QPushButton *moveRight_PB;
    QPushButton *moveLeft_PB;
    QListWidget *addList_LW;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateGroupDialog)
    {
        if (CreateGroupDialog->objectName().isEmpty())
            CreateGroupDialog->setObjectName(QString::fromUtf8("CreateGroupDialog"));
        CreateGroupDialog->resize(461, 377);
        verticalLayout_2 = new QVBoxLayout(CreateGroupDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CreateGroupDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        groupName_LE = new QLineEdit(CreateGroupDialog);
        groupName_LE->setObjectName(QString::fromUtf8("groupName_LE"));

        horizontalLayout->addWidget(groupName_LE);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        selectList_LW = new QListWidget(CreateGroupDialog);
        selectList_LW->setObjectName(QString::fromUtf8("selectList_LW"));

        horizontalLayout_3->addWidget(selectList_LW);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        moveRight_PB = new QPushButton(CreateGroupDialog);
        moveRight_PB->setObjectName(QString::fromUtf8("moveRight_PB"));

        verticalLayout->addWidget(moveRight_PB);

        moveLeft_PB = new QPushButton(CreateGroupDialog);
        moveLeft_PB->setObjectName(QString::fromUtf8("moveLeft_PB"));

        verticalLayout->addWidget(moveLeft_PB);


        horizontalLayout_3->addLayout(verticalLayout);

        addList_LW = new QListWidget(CreateGroupDialog);
        addList_LW->setObjectName(QString::fromUtf8("addList_LW"));

        horizontalLayout_3->addWidget(addList_LW);


        verticalLayout_2->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(CreateGroupDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CreateGroupDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateGroupDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateGroupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateGroupDialog)
    {
        CreateGroupDialog->setWindowTitle(QApplication::translate("CreateGroupDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("CreateGroupDialog", "\350\256\250\350\256\272\347\273\204\345\220\215\345\255\227\345\241\253\345\206\231", nullptr));
        moveRight_PB->setText(QApplication::translate("CreateGroupDialog", "+", nullptr));
        moveLeft_PB->setText(QApplication::translate("CreateGroupDialog", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroupDialog: public Ui_CreateGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUPDIALOG_H
