#include "widget.h"
#include "ui_widget.h"
#include<QPropertyAnimation>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pa = new QPropertyAnimation(ui->label,"geometry");
    pa->setDuration(1000);//延迟，时间,1000毫秒
    connect(pa,&QPropertyAnimation::finished,this,&Widget::ActionFinished);
}

Widget::~Widget()
{
    delete ui;
    delete pa;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    TargetPos = event->pos();
    QLabel *p = new QLabel("T",this);
    p->move(TargetPos);
    p->show();
    ways.append(QPair<QLabel*,QPoint>(p,TargetPos));

    if(!isMove)
    {
        startAnimation();
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    QPoint pos = ui->label->pos();
    switch(event->key())
    {
    case Qt::Key_Up:
        pos -= QPoint(0,10);
        break;
    case Qt::Key_Left:
        pos -= QPoint(10,0);
        break;
    case Qt::Key_Right:
        pos += QPoint(10,0);
        break;
    case Qt::Key_Down:
        pos += QPoint(0,10);
        break;
    default:
        break;
    }
    ui->label->move(pos);
}

void Widget::ActionFinished()
{
    QLabel* p = ways.first().first;
    ways.removeFirst();
    delete  p;
    if(!ways.isEmpty())
    {
        startAnimation();
    }
    else
    {
        isMove = false;
    }
}

void Widget::startAnimation()
{
    QRect start = ui->label->geometry();
    QRect end(ways.first().second,start.size());
    pa->setStartValue(start);
    pa->setEndValue(end);
    pa->start();
    isMove = true;
}

