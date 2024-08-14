#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString ip = ui->IP_LE->text();
    QString port = ui->port_LE->text();
    QString msg = ui->msg_LE->text();
    if(ip.isEmpty() || port.isEmpty() || msg.isEmpty())
    {
        return;
    }

    socket->writeDatagram(msg.toUtf8(),QHostAddress(ip),port.toInt());
}
