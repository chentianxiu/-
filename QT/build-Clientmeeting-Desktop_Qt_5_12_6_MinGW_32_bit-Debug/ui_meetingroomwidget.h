/********************************************************************************
** Form generated from reading UI file 'meetingroomwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEETINGROOMWIDGET_H
#define UI_MEETINGROOMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_meetingRoomWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *meetingName_LB;
    QLabel *host_LB;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QTableWidget *memberList_TW;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *camera_cb;
    QCheckBox *mic_cb;
    QTextBrowser *msgOutput_TB;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *msgInput_LE;
    QPushButton *sendMsg_PB;

    void setupUi(QWidget *meetingRoomWidget)
    {
        if (meetingRoomWidget->objectName().isEmpty())
            meetingRoomWidget->setObjectName(QString::fromUtf8("meetingRoomWidget"));
        meetingRoomWidget->resize(622, 464);
        verticalLayout = new QVBoxLayout(meetingRoomWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        meetingName_LB = new QLabel(meetingRoomWidget);
        meetingName_LB->setObjectName(QString::fromUtf8("meetingName_LB"));

        horizontalLayout->addWidget(meetingName_LB);

        host_LB = new QLabel(meetingRoomWidget);
        host_LB->setObjectName(QString::fromUtf8("host_LB"));

        horizontalLayout->addWidget(host_LB);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(meetingRoomWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 20, 20);"));

        horizontalLayout_4->addWidget(label);

        memberList_TW = new QTableWidget(meetingRoomWidget);
        if (memberList_TW->columnCount() < 2)
            memberList_TW->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        memberList_TW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        memberList_TW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        memberList_TW->setObjectName(QString::fromUtf8("memberList_TW"));

        horizontalLayout_4->addWidget(memberList_TW);

        horizontalLayout_4->setStretch(0, 10);
        horizontalLayout_4->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        camera_cb = new QCheckBox(meetingRoomWidget);
        camera_cb->setObjectName(QString::fromUtf8("camera_cb"));

        horizontalLayout_3->addWidget(camera_cb);

        mic_cb = new QCheckBox(meetingRoomWidget);
        mic_cb->setObjectName(QString::fromUtf8("mic_cb"));

        horizontalLayout_3->addWidget(mic_cb);


        verticalLayout->addLayout(horizontalLayout_3);

        msgOutput_TB = new QTextBrowser(meetingRoomWidget);
        msgOutput_TB->setObjectName(QString::fromUtf8("msgOutput_TB"));

        verticalLayout->addWidget(msgOutput_TB);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        msgInput_LE = new QLineEdit(meetingRoomWidget);
        msgInput_LE->setObjectName(QString::fromUtf8("msgInput_LE"));

        horizontalLayout_2->addWidget(msgInput_LE);

        sendMsg_PB = new QPushButton(meetingRoomWidget);
        sendMsg_PB->setObjectName(QString::fromUtf8("sendMsg_PB"));

        horizontalLayout_2->addWidget(sendMsg_PB);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 20);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 1);

        retranslateUi(meetingRoomWidget);

        QMetaObject::connectSlotsByName(meetingRoomWidget);
    } // setupUi

    void retranslateUi(QWidget *meetingRoomWidget)
    {
        meetingRoomWidget->setWindowTitle(QApplication::translate("meetingRoomWidget", "Form", nullptr));
        meetingName_LB->setText(QApplication::translate("meetingRoomWidget", "\344\274\232\350\256\256\345\220\215\347\247\260", nullptr));
        host_LB->setText(QApplication::translate("meetingRoomWidget", "\344\270\273\346\214\201\344\272\272", nullptr));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = memberList_TW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("meetingRoomWidget", "\346\210\220\345\221\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = memberList_TW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("meetingRoomWidget", "\347\212\266\346\200\201", nullptr));
        camera_cb->setText(QApplication::translate("meetingRoomWidget", "\346\221\204\345\203\217\345\244\264", nullptr));
        mic_cb->setText(QApplication::translate("meetingRoomWidget", "\351\272\246\345\205\213\351\243\216", nullptr));
        sendMsg_PB->setText(QApplication::translate("meetingRoomWidget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class meetingRoomWidget: public Ui_meetingRoomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEETINGROOMWIDGET_H
