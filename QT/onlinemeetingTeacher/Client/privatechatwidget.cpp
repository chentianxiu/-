#include "privatechatwidget.h"
#include "ui_privatechatwidget.h"

#include <QFileDialog>
#include <QFileInfo>

privateChatWidget::privateChatWidget(QString friendName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::privateChatWidget),
    friendName(friendName)
{
    ui->setupUi(this);
    ui->friendName->setText(friendName); //设置好友名字
}

privateChatWidget::~privateChatWidget()
{
    delete ui;
}

void privateChatWidget::addNewMsg(QString message)
{
    QListWidgetItem* item = new QListWidgetItem(message);
    item->setTextAlignment(Qt::AlignLeft);
    ui->msgOutput_LW->addItem(item);
}

void privateChatWidget::on_send_PB_clicked()
{
    QString msg = ui->msgInput_PTE->toPlainText();
    if(msg.isEmpty())
    {
        return;
    }

    emit sendMsg(friendName,msg);

    QListWidgetItem* item = new QListWidgetItem(msg);
    item->setTextAlignment(Qt::AlignRight);
    ui->msgOutput_LW->addItem(item);
}

void privateChatWidget::on_uploadFile_PB_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择要上传的文件","./","文本文件(*.txt)");
    QFileInfo info(filePath);
    if(info.isFile())
    {
        emit uploadFile(this->friendName,filePath,info.baseName());
    }
}
