#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
     server = new servermanager(this); //生成服务器管理器
}

Widget::~Widget()
{
    delete ui;
}

