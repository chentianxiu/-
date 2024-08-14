#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
        socket = new QUdpSocket(this);

        connect(socket,&QUdpSocket::readyRead,this,&Widget::on_ReadyRead);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString ip = ui->IP_LE->text();
    QString port =ui->Port_LE->text();

    if(ip.isEmpty() || port.isEmpty())
    {
        return;
    }

//    if(socket!=nullptr)
//    {
//        delete socket;
//    }

    socket->close();

    socket->bind(QHostAddress(ip),port.toInt());
}

void Widget::on_ReadyRead()
{
    char data[1024] = {};
    socket->readDatagram(data,1024);
    ui->textEdit->append(data);
}
