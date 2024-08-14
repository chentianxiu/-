#include "createmeetingdialog.h"
#include "ui_createmeetingdialog.h"

createmeetingDialog::createmeetingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createmeetingDialog)
{
    ui->setupUi(this);
    this->hide();
}

createmeetingDialog::~createmeetingDialog()
{
    delete ui;
}

void createmeetingDialog::setSelectList(QStringList list)//列表人选
{
    ui->selectList_LW->clear();
    ui->selectList_LW->addItems(list);
    ui->addList_LW->clear();
}

void createmeetingDialog::prepareMeetingName(QString name)//会议名称
{
    ui->meetingName_LE->setText(name);
}

QString createmeetingDialog::getMeetingName()//获取会议名称
{
    return ui->meetingName_LE->text();
}

QStringList createmeetingDialog::getmemberList()//获取会议成员列表
{
    QStringList members;
    for(int i=0;i<ui->addList_LW->count();i++)
    {
        members.append( ui->addList_LW->item(i)->text() );
    }
    return members;
}

void createmeetingDialog::on_addMember_PB_clicked()
{
    int row = ui->selectList_LW->currentRow();
    if(row<0)
    {
        return;
    }
    QListWidgetItem* item = ui->selectList_LW->takeItem(row);
    ui->selectList_LW->removeItemWidget(item);
    ui->addList_LW->addItem(item);
}

void createmeetingDialog::on_removeMember_PB_clicked()
{
    int row = ui->addList_LW->currentRow();
    if(row<0)
    {
        return ;
    }
    QListWidgetItem* item = ui->addList_LW->takeItem(row);
    ui->addList_LW->removeItemWidget(item);
    ui->selectList_LW->addItem(item);
}


