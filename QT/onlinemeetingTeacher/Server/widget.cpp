#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    loadConfigure();
    server = new ServerMananger(address,port,this); //生成服务器管理器

}

Widget::~Widget()
{
    delete ui;
}

void Widget::loadConfigure()
{
    QFile file(":/network/configure/configure.json");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray arry = file.readAll();
        QJsonObject object = QJsonDocument::fromJson(arry).object();
        address = object["NetworkSettings"].toObject()["IPAddress"].toString();
        port = object["NetWorkSettings"].toObject()["Port"].toInt();
    }
}

