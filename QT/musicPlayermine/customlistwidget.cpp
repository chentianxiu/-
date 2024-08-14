// CustomListWidget.cpp

#include "customlistwidget.h"

CustomListWidget::CustomListWidget(QWidget *parent)
    : QListWidget(parent)
{
}

void CustomListWidget::wheelEvent(QWheelEvent *event)
{
    emit wheelScrolled();
    QListWidget::wheelEvent(event); // 调用基类实现以确保正常行为
}
