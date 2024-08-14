#include "widget.h"
#include "ui_widget.h"

#include <QTableWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //表格设置
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("IP地址"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("端口"));

    //建立服务器管理器
    m_server = new ServerManager(this);
    connect(m_server,&ServerManager::newConnection,this,&Widget::onNewConnection);
    connect(m_server,&ServerManager::disConnection,this,&Widget::onDisConnection);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::onNewConnection(QString ip,QString port) //有新连接时
{
    //在表格中添加 客户端的信息(地址)
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(ip));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(port));
}

void Widget::onDisConnection(QString ip, QString port)
{
    QList<QTableWidgetItem*> list = ui->tableWidget->findItems(ip,Qt::MatchExactly);
    for(auto it: list)
    {
        int row = ui->tableWidget->row(it);
        if(ui->tableWidget->item(row,1)->text() == port)
        {
            ui->tableWidget->removeRow(row);
            break;
        }
    }

}

