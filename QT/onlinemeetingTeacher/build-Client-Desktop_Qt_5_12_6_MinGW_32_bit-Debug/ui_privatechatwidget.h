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

class Ui_privateChatWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *friendName;
    QListWidget *msgOutput_LW;
    QPushButton *uploadFile_PB;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *msgInput_PTE;
    QPushButton *send_PB;

    void setupUi(QWidget *privateChatWidget)
    {
        if (privateChatWidget->objectName().isEmpty())
            privateChatWidget->setObjectName(QString::fromUtf8("privateChatWidget"));
        privateChatWidget->resize(758, 548);
        verticalLayout = new QVBoxLayout(privateChatWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        friendName = new QLabel(privateChatWidget);
        friendName->setObjectName(QString::fromUtf8("friendName"));

        verticalLayout->addWidget(friendName);

        msgOutput_LW = new QListWidget(privateChatWidget);
        msgOutput_LW->setObjectName(QString::fromUtf8("msgOutput_LW"));

        verticalLayout->addWidget(msgOutput_LW);

        uploadFile_PB = new QPushButton(privateChatWidget);
        uploadFile_PB->setObjectName(QString::fromUtf8("uploadFile_PB"));

        verticalLayout->addWidget(uploadFile_PB, 0, Qt::AlignLeft);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        msgInput_PTE = new QPlainTextEdit(privateChatWidget);
        msgInput_PTE->setObjectName(QString::fromUtf8("msgInput_PTE"));

        horizontalLayout->addWidget(msgInput_PTE);

        send_PB = new QPushButton(privateChatWidget);
        send_PB->setObjectName(QString::fromUtf8("send_PB"));

        horizontalLayout->addWidget(send_PB);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(3, 3);

        retranslateUi(privateChatWidget);

        QMetaObject::connectSlotsByName(privateChatWidget);
    } // setupUi

    void retranslateUi(QWidget *privateChatWidget)
    {
        privateChatWidget->setWindowTitle(QApplication::translate("privateChatWidget", "Form", nullptr));
        friendName->setText(QString());
        uploadFile_PB->setText(QApplication::translate("privateChatWidget", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
        send_PB->setText(QApplication::translate("privateChatWidget", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class privateChatWidget: public Ui_privateChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATECHATWIDGET_H
