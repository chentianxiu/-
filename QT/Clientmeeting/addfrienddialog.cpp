#include "addfrienddialog.h"
#include "ui_addfrienddialog.h"
#include <QDebug>

addfriendDialog::addfriendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addfriendDialog)
{
    ui->setupUi(this);
}

addfriendDialog::~addfriendDialog()
{
    delete ui;
}

void addfriendDialog::setSelectList(QStringList text)//设置列表显示
{
    ui->selectList_LW->clear();
    ui->selectList_LW->addItems(text);
    ui->addList_LW->clear();
}

void addfriendDialog::on_addName_PB_clicked()//点击增加好友按钮
{
    QString name = ui->lineEdit->text();
    if(name.isEmpty())
    {
        return;
    }
    QList<QListWidgetItem*> list = ui->addList_LW->findItems(name,Qt::MatchExactly);
    if(list.isEmpty())
    {
        return;
    }
    QListWidgetItem* item = list.first();//查找，然后只要找到的列表中的第一个
    ui->addList_LW->addItem(item);
    ui->selectList_LW->removeItemWidget(item);
}

void addfriendDialog::on_moveRight_PB_clicked()//点击右移按钮
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

void addfriendDialog::on_moveLeft_PB_clicked()//点击左移按钮
{
    int row = ui->addList_LW->currentRow();
    if(row<0)
    {
        return;
    }
    QListWidgetItem* item = ui->addList_LW->takeItem(row);
    ui->addList_LW->removeItemWidget(item);
    ui->selectList_LW->addItem(item);
}

void addfriendDialog::on_buttonBox_accepted()//点击下面的ok按钮
{
    QStringList friends;
    for(int i=0;i<ui->addList_LW->count();i++)
    {
        friends.append( ui->addList_LW->item(i)->text() );
    }
    emit this->addfriends(friends);//向主窗口发送需要添加的好友的列表
}
