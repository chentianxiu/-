/********************************************************************************
** Form generated from reading UI file 'createmeetingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEMEETINGDIALOG_H
#define UI_CREATEMEETINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_createMeetingDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *meetingName_LE;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QListWidget *selectList_LW;
    QVBoxLayout *verticalLayout;
    QPushButton *addMember_PB;
    QPushButton *removeMember_PB;
    QListWidget *addList_LW;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *createMeetingDialog)
    {
        if (createMeetingDialog->objectName().isEmpty())
            createMeetingDialog->setObjectName(QString::fromUtf8("createMeetingDialog"));
        createMeetingDialog->resize(506, 397);
        verticalLayout_2 = new QVBoxLayout(createMeetingDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(createMeetingDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        meetingName_LE = new QLineEdit(createMeetingDialog);
        meetingName_LE->setObjectName(QString::fromUtf8("meetingName_LE"));

        verticalLayout_2->addWidget(meetingName_LE);

        line = new QFrame(createMeetingDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        selectList_LW = new QListWidget(createMeetingDialog);
        selectList_LW->setObjectName(QString::fromUtf8("selectList_LW"));

        horizontalLayout->addWidget(selectList_LW);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addMember_PB = new QPushButton(createMeetingDialog);
        addMember_PB->setObjectName(QString::fromUtf8("addMember_PB"));

        verticalLayout->addWidget(addMember_PB);

        removeMember_PB = new QPushButton(createMeetingDialog);
        removeMember_PB->setObjectName(QString::fromUtf8("removeMember_PB"));

        verticalLayout->addWidget(removeMember_PB);


        horizontalLayout->addLayout(verticalLayout);

        addList_LW = new QListWidget(createMeetingDialog);
        addList_LW->setObjectName(QString::fromUtf8("addList_LW"));

        horizontalLayout->addWidget(addList_LW);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(createMeetingDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(createMeetingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), createMeetingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), createMeetingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(createMeetingDialog);
    } // setupUi

    void retranslateUi(QDialog *createMeetingDialog)
    {
        createMeetingDialog->setWindowTitle(QApplication::translate("createMeetingDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("createMeetingDialog", "\344\274\232\350\256\256\345\220\215", nullptr));
        addMember_PB->setText(QApplication::translate("createMeetingDialog", "+", nullptr));
        removeMember_PB->setText(QApplication::translate("createMeetingDialog", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createMeetingDialog: public Ui_createMeetingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEMEETINGDIALOG_H
