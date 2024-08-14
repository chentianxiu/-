#include "widget.h"
#include "ui_widget.h"
#include <QByteArray>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::AnyIPv4,8888); //设置服务器监听操作
    connect(server,&QTcpServer::newConnection,this,&Widget::onNewConnection); //连接请求信号和槽
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onNewConnection()
{
    socket = server->nextPendingConnection(); //同意连接并保留客户端的套接字
    connect(socket,&QTcpSocket::readyRead,this,&Widget::onReadyRead);
    connect(socket,&QTcpSocket::disconnected,this,&Widget::onDisconnect);
    QString str = "客户端"+socket->peerAddress().toString() +":"+ QString::number(socket->peerPort())+"建立连接";
    ui->textBrowser->append(str);
}

void Widget::onReadyRead()
{
    QByteArray bytes = socket->read(1024);
    ui->textBrowser->append(bytes);
}

void Widget::onDisconnect()
{
    ui->textBrowser->append("客户端断开连接");
    socket->close();
}

