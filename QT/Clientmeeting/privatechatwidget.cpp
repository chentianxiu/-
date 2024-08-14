#include "privatechatwidget.h"
#include "ui_privatechatwidget.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>

privatechatwidget::privatechatwidget(QString friendName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::privatechatwidget),
    friendName(friendName)
{
    ui->setupUi(this);
    ui->friendName->setText(friendName);
}

privatechatwidget::~privatechatwidget()
{
    delete ui;
}

void privatechatwidget::addNewMsg(QString message)//接收消息
{
    //qDebug()<<message;
    QListWidgetItem* item = new QListWidgetItem(message);
    item->setTextAlignment(Qt::AlignLeft);//消息显示在左边
    ui->msgOutput_LW->addItem(item);
}

void privatechatwidget::on_send_PB_clicked()//点击发送消息按钮
{
    QString msg = ui->msginput_PTE->toPlainText();//获取消息
    if(msg.isEmpty())
    {
        return;
    }

    emit sendMsg(friendName,msg);//将信号发送出去


    //将消息显示在页面
    QListWidgetItem* item = new QListWidgetItem(msg);
    item->setTextAlignment(Qt::AlignRight);//显示在右边
    ui->msgOutput_LW->addItem(item);
}

void privatechatwidget::on_uploadFile_PB_clicked()//上传文件
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择要上传的文件","./","文本文件(*.txt)");
    QFileInfo info(filePath);
    if(info.isFile())
    {
        emit uploadFile(this->friendName,filePath,info.baseName());
    }
}
