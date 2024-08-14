#include "groupchatwidget.h"
#include "ui_groupchatwidget.h"


#include <QFileDialog>
#include <QFileInfo>

groupchatwidget::groupchatwidget(QString groupname,QStringList grouplist,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::groupchatwidget),
    groupname(groupname),
    groupmembers(grouplist)
{
    ui->setupUi(this);
    ui->groupName->setText(groupname);//设置群名
}

groupchatwidget::~groupchatwidget()
{
    delete ui;
}

void groupchatwidget::addNewMsg(QString sender,QString message)
{
    QListWidgetItem* item = new QListWidgetItem(sender+":"+message);
    item->setTextAlignment(Qt::AlignLeft);
    ui->msgOutput_LW->addItem(item);
}

void groupchatwidget::setgroupmemberslist(QStringList members)
{
    // 清空当前的 listWidget
        ui->grouplist_LW->clear();

        // 遍历 QStringList，将每个成员添加到 listWidget 中
        foreach (const QString &member, members) {
            QListWidgetItem *item = new QListWidgetItem(member, ui->grouplist_LW);
            ui->grouplist_LW->addItem(item);
        }
}

void groupchatwidget::on_send_PB_clicked()//点击发送消息
{
    QString msg = ui->msginput_PTE->toPlainText();
    if(msg.isEmpty())
    {
        return;
    }

    emit sendMsg(groupname,msg);

    QListWidgetItem* item = new QListWidgetItem(msg);
    item->setTextAlignment(Qt::AlignRight);
    ui->msgOutput_LW->addItem(item);
}

void groupchatwidget::on_uploadFile_PB_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择要上传的文件","./","文本文件(*.txt)");
    QFileInfo info(filePath);
    if(info.isFile())
    {
        emit uploadFile(this->groupname,filePath,info.baseName());
    }
}
