/********************************************************************************
** Form generated from reading UI file 'privatechatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATECHATWIDGET_H
#define UI_PRIVATECHATWIDGET_H

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

class Ui_privatechatwidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *friendName;
    QListWidget *msgOutput_LW;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *msginput_PTE;
    QVBoxLayout *verticalLayout;
    QPushButton *send_PB;
    QPushButton *uploadFile_PB;

    void setupUi(QWidget *privatechatwidget)
    {
        if (privatechatwidget->objectName().isEmpty())
            privatechatwidget->setObjectName(QString::fromUtf8("privatechatwidget"));
        privatechatwidget->resize(424, 400);
        verticalLayout_2 = new QVBoxLayout(privatechatwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        friendName = new QLabel(privatechatwidget);
        friendName->setObjectName(QString::fromUtf8("friendName"));

        verticalLayout_2->addWidget(friendName);

        msgOutput_LW = new QListWidget(privatechatwidget);
        msgOutput_LW->setObjectName(QString::fromUtf8("msgOutput_LW"));

        verticalLayout_2->addWidget(msgOutput_LW);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        msginput_PTE = new QPlainTextEdit(privatechatwidget);
        msginput_PTE->setObjectName(QString::fromUtf8("msginput_PTE"));

        horizontalLayout->addWidget(msginput_PTE);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        send_PB = new QPushButton(privatechatwidget);
        send_PB->setObjectName(QString::fromUtf8("send_PB"));

        verticalLayout->addWidget(send_PB);

        uploadFile_PB = new QPushButton(privatechatwidget);
        uploadFile_PB->setObjectName(QString::fromUtf8("uploadFile_PB"));

        verticalLayout->addWidget(uploadFile_PB);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 10);
        verticalLayout_2->setStretch(2, 1);

        retranslateUi(privatechatwidget);

        QMetaObject::connectSlotsByName(privatechatwidget);
    } // setupUi

    void retranslateUi(QWidget *privatechatwidget)
    {
        privatechatwidget->setWindowTitle(QApplication::translate("privatechatwidget", "Form", nullptr));
        friendName->setText(QString());
        send_PB->setText(QApplication::translate("privatechatwidget", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        uploadFile_PB->setText(QApplication::translate("privatechatwidget", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class privatechatwidget: public Ui_privatechatwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATECHATWIDGET_H
