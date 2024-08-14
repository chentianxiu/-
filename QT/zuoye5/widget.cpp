#include "widget.h"
#include "ui_widget.h"
#include "mytextedit.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->installEventFilter(ui->textEdit);//给textEdit安装事件过滤器

    connect(ui->textEdit,&myTextEdit::keyPressed,this,&Widget::onKeyPressed);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onKeyPressed(QPoint pos)
{
    ui->pushButton->move(ui->pushButton->pos()+pos);
}

