#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //开启鼠标追踪
    this->setMouseTracking(true);
    ui->label->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event) //鼠标移动
{
    QRect labelRect = ui->label->geometry(); //获取label的范围

    //判断鼠标是否在label中
    if(labelRect.contains(event->pos()))
    {
        ui->label->setText("B"); //成立显示B
    }
    else
    {
        ui->label->setText("A"); //不成立显示A
    }
}

