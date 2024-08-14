#include "creategroupdialog.h"
#include "ui_creategroupdialog.h"
#include <QMessageBox>

CreateGroupDialog::CreateGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGroupDialog)
{
    ui->setupUi(this);
    //this->hide();
}

CreateGroupDialog::~CreateGroupDialog()
{
    delete ui;
}

void CreateGroupDialog::setSelectList(QStringList list)
{
    ui->selectList_LW->clear();
    ui->selectList_LW->addItems(list);
    ui->addList_LW->clear();
}

void CreateGroupDialog::on_moveRight_PB_clicked()
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


void CreateGroupDialog::on_moveLeft_PB_clicked()
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

void CreateGroupDialog::on_buttonBox_accepted()
{
     QStringList members;
     QString groupName = ui->groupName_LE->text();
     if(groupName=="")
     {
           QMessageBox::warning(this,"创建群组","组名不能为空");
           return;
     }
     for(int i=0;i<ui->addList_LW->count();i++)
     {
         members.append( ui->addList_LW->item(i)->text() );
     }
     emit this->creategroup(groupName,members);
}
