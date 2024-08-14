/********************************************************************************
** Form generated from reading UI file 'menuwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGET_H
#define UI_MENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menuwidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QListWidget *friendList_LW;
    QPushButton *addFriend_PB;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *groupList_LW;
    QPushButton *addmeber_PB;
    QPushButton *creategroup_PB;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QListWidget *meetingList_LW;
    QPushButton *createMeeting_PB;
    QFrame *frame;
    QTableWidget *fileList_TW;

    void setupUi(QWidget *menuwidget)
    {
        if (menuwidget->objectName().isEmpty())
            menuwidget->setObjectName(QString::fromUtf8("menuwidget"));
        menuwidget->resize(678, 431);
        verticalLayout_4 = new QVBoxLayout(menuwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(menuwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        friendList_LW = new QListWidget(tab);
        friendList_LW->setObjectName(QString::fromUtf8("friendList_LW"));

        verticalLayout->addWidget(friendList_LW);

        addFriend_PB = new QPushButton(tab);
        addFriend_PB->setObjectName(QString::fromUtf8("addFriend_PB"));

        verticalLayout->addWidget(addFriend_PB);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupList_LW = new QListWidget(tab_2);
        groupList_LW->setObjectName(QString::fromUtf8("groupList_LW"));

        verticalLayout_2->addWidget(groupList_LW);

        addmeber_PB = new QPushButton(tab_2);
        addmeber_PB->setObjectName(QString::fromUtf8("addmeber_PB"));

        verticalLayout_2->addWidget(addmeber_PB);

        creategroup_PB = new QPushButton(tab_2);
        creategroup_PB->setObjectName(QString::fromUtf8("creategroup_PB"));

        verticalLayout_2->addWidget(creategroup_PB);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        meetingList_LW = new QListWidget(tab_3);
        meetingList_LW->setObjectName(QString::fromUtf8("meetingList_LW"));

        verticalLayout_3->addWidget(meetingList_LW);

        createMeeting_PB = new QPushButton(tab_3);
        createMeeting_PB->setObjectName(QString::fromUtf8("createMeeting_PB"));

        verticalLayout_3->addWidget(createMeeting_PB);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        frame = new QFrame(menuwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 10);

        verticalLayout_4->addLayout(horizontalLayout);

        fileList_TW = new QTableWidget(menuwidget);
        if (fileList_TW->columnCount() < 3)
            fileList_TW->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        fileList_TW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        fileList_TW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        fileList_TW->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        fileList_TW->setObjectName(QString::fromUtf8("fileList_TW"));
        fileList_TW->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_4->addWidget(fileList_TW);

        verticalLayout_4->setStretch(0, 5);
        verticalLayout_4->setStretch(1, 1);

        retranslateUi(menuwidget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(menuwidget);
    } // setupUi

    void retranslateUi(QWidget *menuwidget)
    {
        menuwidget->setWindowTitle(QApplication::translate("menuwidget", "Form", nullptr));
        addFriend_PB->setText(QApplication::translate("menuwidget", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("menuwidget", "\345\245\275\345\217\213", nullptr));
        addmeber_PB->setText(QApplication::translate("menuwidget", "\346\267\273\345\212\240\346\210\220\345\221\230", nullptr));
        creategroup_PB->setText(QApplication::translate("menuwidget", "\345\210\233\345\273\272\345\260\217\347\273\204", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("menuwidget", "\350\256\250\350\256\272\347\273\204", nullptr));
        createMeeting_PB->setText(QApplication::translate("menuwidget", "\345\210\233\345\273\272\344\274\232\350\256\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("menuwidget", "\344\274\232\350\256\256\345\210\227\350\241\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem = fileList_TW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("menuwidget", "\345\217\221\351\200\201\350\200\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = fileList_TW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("menuwidget", "\346\216\245\346\224\266\350\200\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = fileList_TW->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("menuwidget", "\346\226\207\344\273\266\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuwidget: public Ui_menuwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
