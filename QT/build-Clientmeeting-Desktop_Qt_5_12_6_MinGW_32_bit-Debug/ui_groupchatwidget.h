/********************************************************************************
** Form generated from reading UI file 'groupchatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATWIDGET_H
#define UI_GROUPCHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupchatwidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *groupName;
    QListWidget *msgOutput_LW;
    QVBoxLayout *verticalLayout_3;
    QLabel *groupmember;
    QListWidget *grouplist_LW;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *msginput_PTE;
    QVBoxLayout *verticalLayout;
    QPushButton *send_PB;
    QPushButton *uploadFile_PB;

    void setupUi(QWidget *groupchatwidget)
    {
        if (groupchatwidget->objectName().isEmpty())
            groupchatwidget->setObjectName(QString::fromUtf8("groupchatwidget"));
        groupchatwidget->resize(507, 389);
        verticalLayout_4 = new QVBoxLayout(groupchatwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupName = new QLabel(groupchatwidget);
        groupName->setObjectName(QString::fromUtf8("groupName"));

        verticalLayout_2->addWidget(groupName);

        msgOutput_LW = new QListWidget(groupchatwidget);
        msgOutput_LW->setObjectName(QString::fromUtf8("msgOutput_LW"));

        verticalLayout_2->addWidget(msgOutput_LW);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupmember = new QLabel(groupchatwidget);
        groupmember->setObjectName(QString::fromUtf8("groupmember"));

        verticalLayout_3->addWidget(groupmember);

        grouplist_LW = new QListWidget(groupchatwidget);
        grouplist_LW->setObjectName(QString::fromUtf8("grouplist_LW"));

        verticalLayout_3->addWidget(grouplist_LW);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 8);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        msginput_PTE = new QPlainTextEdit(groupchatwidget);
        msginput_PTE->setObjectName(QString::fromUtf8("msginput_PTE"));

        horizontalLayout->addWidget(msginput_PTE);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        send_PB = new QPushButton(groupchatwidget);
        send_PB->setObjectName(QString::fromUtf8("send_PB"));

        verticalLayout->addWidget(send_PB);

        uploadFile_PB = new QPushButton(groupchatwidget);
        uploadFile_PB->setObjectName(QString::fromUtf8("uploadFile_PB"));

        verticalLayout->addWidget(uploadFile_PB);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_4->setStretch(0, 10);
        verticalLayout_4->setStretch(1, 1);

        retranslateUi(groupchatwidget);

        QMetaObject::connectSlotsByName(groupchatwidget);
    } // setupUi

    void retranslateUi(QWidget *groupchatwidget)
    {
        groupchatwidget->setWindowTitle(QApplication::translate("groupchatwidget", "Form", nullptr));
        groupName->setText(QApplication::translate("groupchatwidget", "\347\276\244\345\220\215", nullptr));
        groupmember->setText(QApplication::translate("groupchatwidget", "\347\276\244\346\210\220\345\221\230", nullptr));
        send_PB->setText(QApplication::translate("groupchatwidget", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        uploadFile_PB->setText(QApplication::translate("groupchatwidget", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupchatwidget: public Ui_groupchatwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATWIDGET_H
