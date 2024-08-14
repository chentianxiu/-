#include "createmeetingdialog.h"
#include "ui_createmeetingdialog.h"

createMeetingDialog::createMeetingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createMeetingDialog)
{
    ui->setupUi(this);
    this->hide();
}

createMeetingDialog::~createMeetingDialog()
{
    delete ui;
}

void createMeetingDialog::setSelectList(QStringList list)
{
    ui->selectList_LW->clear();
    ui->selectList_LW->addItems(list);
}

void createMeetingDialog::prepareMeetingName(QString name)
{
    ui->meetingName_LE->setText(name);
}

QString createMeetingDialog::getMeetingName()
{
    return ui->meetingName_LE->text();
}

QStringList createMeetingDialog::getmemberList()
{
    QStringList members;
    for(int i=0;i<ui->addList_LW->count();i++)
    {
        members.append( ui->addList_LW->item(i)->text() );
    }
    return members;
}

void createMeetingDialog::on_addMember_PB_clicked()
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

void createMeetingDialog::on_removeMember_PB_clicked()
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
