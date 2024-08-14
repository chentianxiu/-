/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *username_LE;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *pwd_LE;
    QCheckBox *checkBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *regist_PB;
    QPushButton *login_PB;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(391, 366);
        Widget->setSizeIncrement(QSize(6, 6));
        Widget->setBaseSize(QSize(6, 6));
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(21);
        label->setFont(font);
        label->setScaledContents(false);

        verticalLayout_3->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        username_LE = new QLineEdit(Widget);
        username_LE->setObjectName(QString::fromUtf8("username_LE"));

        verticalLayout_2->addWidget(username_LE);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pwd_LE = new QLineEdit(Widget);
        pwd_LE->setObjectName(QString::fromUtf8("pwd_LE"));

        horizontalLayout_2->addWidget(pwd_LE);

        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);

        horizontalLayout_2->addWidget(checkBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(85, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        regist_PB = new QPushButton(Widget);
        regist_PB->setObjectName(QString::fromUtf8("regist_PB"));

        horizontalLayout->addWidget(regist_PB);


        verticalLayout->addLayout(horizontalLayout);

        login_PB = new QPushButton(Widget);
        login_PB->setObjectName(QString::fromUtf8("login_PB"));

        verticalLayout->addWidget(login_PB);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        username_LE->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        pwd_LE->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        checkBox->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\351\232\220\350\227\217", nullptr));
        regist_PB->setText(QApplication::translate("Widget", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\214\347\202\271\345\207\273\346\263\250\345\206\214", nullptr));
        login_PB->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
