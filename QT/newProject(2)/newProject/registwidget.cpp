#include "registwidget.h"
#include "ui_registwidget.h"
#include <QMessageBox>

registWidget::registWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registWidget)
{
    ui->setupUi(this);
}

registWidget::~registWidget()
{
    delete ui;
}

void registWidget::on_buttonBox_accepted()
{
    QString name = ui->lineEdit->text(); //用户名
    QString pswd = ui->lineEdit_2->text(); //密码
    QString pswd2 = ui->lineEdit_3->text();//确认的密码
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

void registWidget::clearInfo()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}
