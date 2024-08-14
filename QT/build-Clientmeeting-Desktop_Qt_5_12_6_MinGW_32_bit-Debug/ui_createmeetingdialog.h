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

class Ui_createmeetingDialog
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

    void setupUi(QDialog *createmeetingDialog)
    {
        if (createmeetingDialog->objectName().isEmpty())
            createmeetingDialog->setObjectName(QString::fromUtf8("createmeetingDialog"));
        createmeetingDialog->resize(458, 363);
        verticalLayout_2 = new QVBoxLayout(createmeetingDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(createmeetingDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        meetingName_LE = new QLineEdit(createmeetingDialog);
        meetingName_LE->setObjectName(QString::fromUtf8("meetingName_LE"));

        verticalLayout_2->addWidget(meetingName_LE);

        line = new QFrame(createmeetingDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        selectList_LW = new QListWidget(createmeetingDialog);
        selectList_LW->setObjectName(QString::fromUtf8("selectList_LW"));

        horizontalLayout->addWidget(selectList_LW);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addMember_PB = new QPushButton(createmeetingDialog);
        addMember_PB->setObjectName(QString::fromUtf8("addMember_PB"));

        verticalLayout->addWidget(addMember_PB);

        removeMember_PB = new QPushButton(createmeetingDialog);
        removeMember_PB->setObjectName(QString::fromUtf8("removeMember_PB"));

        verticalLayout->addWidget(removeMember_PB);


        horizontalLayout->addLayout(verticalLayout);

        addList_LW = new QListWidget(createmeetingDialog);
        addList_LW->setObjectName(QString::fromUtf8("addList_LW"));

        horizontalLayout->addWidget(addList_LW);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(createmeetingDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(createmeetingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), createmeetingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), createmeetingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(createmeetingDialog);
    } // setupUi

    void retranslateUi(QDialog *createmeetingDialog)
    {
        createmeetingDialog->setWindowTitle(QApplication::translate("createmeetingDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("createmeetingDialog", "\344\274\232\350\256\256\345\220\215", nullptr));
        addMember_PB->setText(QApplication::translate("createmeetingDialog", "+", nullptr));
        removeMember_PB->setText(QApplication::translate("createmeetingDialog", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createmeetingDialog: public Ui_createmeetingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEMEETINGDIALOG_H
