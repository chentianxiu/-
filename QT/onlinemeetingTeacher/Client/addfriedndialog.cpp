#include "addfriedndialog.h"
#include "ui_addfriedndialog.h"
#include <QDebug>

addFriednDialog::addFriednDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addFriednDialog)
{
    ui->setupUi(this);
    this->hide();
}

addFriednDialog::~addFriednDialog()
{
    delete ui;
}

void addFriednDialog::setSelectList(QStringList text)
{
    ui->selectList_LW->clear();
    ui->selectList_LW->addItems(text);
}

void addFriednDialog::on_moveRight_PB_clicked()
{
    qDebug()<<111;
    int row = ui->selectList_LW->currentRow();
    if(row<0)
    {
        return;
    }
    QListWidgetItem* item = ui->selectList_LW->takeItem(row);
    ui->selectList_LW->removeItemWidget(item);
    ui->addList_LW->addItem(item);

}

void addFriednDialog::on_moveLeft_PB_clicked()
{
    QListWidgetItem* item = ui->addList_LW->currentItem();
    if(item == nullptr)
    {
        return ;
    }
    ui->selectList_LW->addItem(item);
    ui->addList_LW->removeItemWidget(item);

}

void addFriednDialog::on_addName_PB_clicked()
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

void addFriednDialog::on_buttonBox_accepted()
{
    QStringList friends;
    for(int i=0;i<ui->addList_LW->count();i++)
    {
        friends.append( ui->addList_LW->item(i)->text() );
    }
    emit this->addfriends(friends);
}
