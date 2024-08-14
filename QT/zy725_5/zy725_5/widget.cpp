#include "widget.h"
#include "ui_widget.h"
#include "mytextedit.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->installEventFilter(ui->textEdit); //安装事件过滤器->textEdit
    connect(ui->textEdit,&myTextEdit::keyPressed,this,&Widget::onKeyPressed);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
        ui->pushButton->move(ui->pushButton->pos() - QPoint(0,10));  //上
        break;
    case Qt::Key_A:
        ui->pushButton->move(ui->pushButton->pos() - QPoint(10,0));  //左
        break;
    case Qt::Key_S:
        ui->pushButton->move(ui->pushButton->pos() + QPoint(0,10));  //下
        break;
    case Qt::Key_D:
        ui->pushButton->move(ui->pushButton->pos() + QPoint(10,0));  //右
        break;
    default:
        break;
    }
}

void Widget::onKeyPressed(QPoint pos)
{
    ui->pushButton->move(ui->pushButton->pos()+pos);
}

