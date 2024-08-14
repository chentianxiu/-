#include "widget.h"
#include "ui_widget.h"
#include <unistd.h>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
    if(thread != nullptr)
    {
        thread->terminate(); //结束线程
        thread->wait(); //等待线程结束
        thread->deleteLater(); //释放线程对象
    }
}


void Widget::on_pushButton_clicked()
{
    thread = new myThread(this); //生成线程对象
    connect(thread,&myThread::addMsg,this,&Widget::on_addMsg); //连接信号和槽
    thread->start();//启动线程-->线程里调用run函数
}

void Widget::on_addMsg()
{
    ui->textEdit->append("hello world");
}
