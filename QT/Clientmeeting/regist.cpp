#include "regist.h"
#include "ui_regist.h"
#include <QMessageBox>

regist::regist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regist)
{
    ui->setupUi(this);
    this->hide();
}

regist::~regist()
{
    delete ui;
}

void regist::on_regist_PB_clicked()
{
    QString name = ui->nameinput_LE->text();
    QString pswd = ui->pswdinput_LE->text();
    QString rpswd = ui->rpswdinput_LE->text();
    if(name.isEmpty()||pswd.isEmpty()||rpswd.isEmpty())
    {
        QMessageBox::warning(this,"注册","用户名和密码不能为空");
        return;
    }
    if(pswd!=rpswd)
    {
        QMessageBox::warning(this,"注册","两次密码不一致");
    }
    emit userRegist(name,pswd);
}
