#include "zuoye2.h"
#include "ui_zuoye2.h"

zuoye2::zuoye2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zuoye2)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignCenter);
}

zuoye2::~zuoye2()
{
    delete ui;
}

void zuoye2::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    //判断是否是字母或者数字

    if ((key >= Qt::Key_A && key <= Qt::Key_Z) || (key >= Qt::Key_0 && key <= Qt::Key_9))
    {
        ui->label->setText(event->text());//设置对应的字符串
    }else{
        ui->label->clear();
    }
}
