/********************************************************************************
** Form generated from reading UI file 'addfriedndialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEDNDIALOG_H
#define UI_ADDFRIEDNDIALOG_H

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

class Ui_addFriednDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *addName_PB;
    QHBoxLayout *horizontalLayout;
    QListWidget *selectList_LW;
    QVBoxLayout *verticalLayout;
    QPushButton *moveRight_PB;
    QSpacerItem *verticalSpacer;
    QPushButton *moveLeft_PB;
    QListWidget *addList_LW;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addFriednDialog)
    {
        if (addFriednDialog->objectName().isEmpty())
            addFriednDialog->setObjectName(QString::fromUtf8("addFriednDialog"));
        addFriednDialog->resize(541, 412);
        verticalLayout_2 = new QVBoxLayout(addFriednDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(addFriednDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        addName_PB = new QPushButton(addFriednDialog);
        addName_PB->setObjectName(QString::fromUtf8("addName_PB"));

        horizontalLayout_2->addWidget(addName_PB);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        selectList_LW = new QListWidget(addFriednDialog);
        selectList_LW->setObjectName(QString::fromUtf8("selectList_LW"));

        horizontalLayout->addWidget(selectList_LW);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        moveRight_PB = new QPushButton(addFriednDialog);
        moveRight_PB->setObjectName(QString::fromUtf8("moveRight_PB"));

        verticalLayout->addWidget(moveRight_PB);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moveLeft_PB = new QPushButton(addFriednDialog);
        moveLeft_PB->setObjectName(QString::fromUtf8("moveLeft_PB"));

        verticalLayout->addWidget(moveLeft_PB);


        horizontalLayout->addLayout(verticalLayout);

        addList_LW = new QListWidget(addFriednDialog);
        addList_LW->setObjectName(QString::fromUtf8("addList_LW"));

        horizontalLayout->addWidget(addList_LW);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(addFriednDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(addFriednDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), addFriednDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addFriednDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(addFriednDialog);
    } // setupUi

    void retranslateUi(QDialog *addFriednDialog)
    {
        addFriednDialog->setWindowTitle(QApplication::translate("addFriednDialog", "Dialog", nullptr));
        addName_PB->setText(QApplication::translate("addFriednDialog", "\346\267\273\345\212\240", nullptr));
        moveRight_PB->setText(QApplication::translate("addFriednDialog", ">>>", nullptr));
        moveLeft_PB->setText(QApplication::translate("addFriednDialog", "<<<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addFriednDialog: public Ui_addFriednDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEDNDIALOG_H
