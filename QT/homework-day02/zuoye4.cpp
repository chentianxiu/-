#include "zuoye4.h"
#include "ui_zuoye4.h"

zuoye4::zuoye4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zuoye4)
{
    ui->setupUi(this);

    //开启鼠标追踪
    this->setMouseTracking(true);
    ui->label->setMouseTracking(true);
}

zuoye4::~zuoye4()
{
    delete ui;
}

void zuoye4::mouseMoveEvent(QMouseEvent *event)
{
    QRect labelRect = ui->label->geometry();

    //判断鼠标是否在label中
    if(labelRect.contains(event->pos()))
    {
        ui->label->setText("B");
    }
    else {
        ui->label->setText("A");
    }


}
