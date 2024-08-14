#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket,&QTcpSocket::readyRead,this,&Widget::on_ReadyRead);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked() //连接
{
    QString ip = ui->ip_LE->text();
    QString port = ui->port_LE->text();


    if(ui->pushButton->text()=="连接")
    {
        if(ip.isEmpty() || port.isEmpty())
        {
            return;
        }
        socket->connectToHost(QHostAddress(ip),port.toInt());
        ui->pushButton->setText("断开连接");
    }
    else
    {
        socket->disconnectFromHost(); //断开连接
        ui->pushButton->setText("连接");
    }

}

void Widget::on_pushButton_2_clicked() //发送
{
    QString msg = ui->msg_LE->text();
    if(msg.isEmpty())
    {
        return;
    }

    socket->write(msg.toUtf8());
}

void Widget::on_ReadyRead()
{
    QByteArray bytes = socket->read(1024);
    ui->textBrowser->append(bytes);
}
