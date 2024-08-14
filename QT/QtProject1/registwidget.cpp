#include "registwidget.h"
#include "ui_registwidget.h"
#include<QMessageBox>

registwidget::registwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registwidget)
{
    ui->setupUi(this);
}

registwidget::~registwidget()
{
    delete ui;
}

void registwidget::on_buttonBox_accepted()
{
    QString name = ui->username->text(); //用户名
    QString pswd = ui->pwd->text(); //密码
    QString pswd2 = ui->pwd2->text();//确认的密码
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"新用户注册","用户名不能为空");
    }
    else if(pswd.isEmpty())
    {
        QMessageBox::warning(this,"新用户注册","密码不能为空");
    }
    else if(pswd2 != pswd)
    {
        QMessageBox::warning(this,"新用户注册","两次密码不一致");
    }
    else
    {
        this->hide(); //隐藏自己
        clearInfo(); //清除输入的数据
        emit userRegisted(name,pswd);
}
}

void registwidget::clearInfo()
{
    ui->username->clear();
    ui->pwd->clear();
    ui->pwd2->clear();
}
