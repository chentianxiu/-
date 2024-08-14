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

class Ui_menuWidget
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
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QPushButton *meetinglist_PB;
    QListWidget *meetingList_LW;
    QPushButton *createMeeting_PB;
    QTableWidget *fileList_TW;

    void setupUi(QWidget *menuWidget)
    {
        if (menuWidget->objectName().isEmpty())
            menuWidget->setObjectName(QString::fromUtf8("menuWidget"));
        menuWidget->resize(634, 474);
        verticalLayout_4 = new QVBoxLayout(menuWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(menuWidget);
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

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        frame = new QFrame(menuWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        meetinglist_PB = new QPushButton(menuWidget);
        meetinglist_PB->setObjectName(QString::fromUtf8("meetinglist_PB"));

        horizontalLayout->addWidget(meetinglist_PB, 0, Qt::AlignTop);

        meetingList_LW = new QListWidget(menuWidget);
        meetingList_LW->setObjectName(QString::fromUtf8("meetingList_LW"));

        horizontalLayout->addWidget(meetingList_LW);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 20);

        verticalLayout_4->addLayout(horizontalLayout);

        createMeeting_PB = new QPushButton(menuWidget);
        createMeeting_PB->setObjectName(QString::fromUtf8("createMeeting_PB"));

        verticalLayout_4->addWidget(createMeeting_PB, 0, Qt::AlignRight);

        fileList_TW = new QTableWidget(menuWidget);
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

        verticalLayout_4->setStretch(0, 20);
        verticalLayout_4->setStretch(2, 5);

        retranslateUi(menuWidget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(menuWidget);
    } // setupUi

    void retranslateUi(QWidget *menuWidget)
    {
        menuWidget->setWindowTitle(QApplication::translate("menuWidget", "Form", nullptr));
        addFriend_PB->setText(QApplication::translate("menuWidget", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("menuWidget", "\345\245\275\345\217\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("menuWidget", "\350\256\250\350\256\272\347\273\204", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("menuWidget", "\346\226\207\344\273\266", nullptr));
        meetinglist_PB->setText(QApplication::translate("menuWidget", "\344\274\232\350\256\256\345\210\227\350\241\250", nullptr));
        createMeeting_PB->setText(QApplication::translate("menuWidget", " \345\210\233\345\273\272\344\274\232\350\256\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = fileList_TW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("menuWidget", "\345\217\221\351\200\201\350\200\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = fileList_TW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("menuWidget", "\346\216\245\345\217\227\350\200\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = fileList_TW->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("menuWidget", "\346\226\207\344\273\266\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuWidget: public Ui_menuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
