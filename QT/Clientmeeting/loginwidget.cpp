#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QMessageBox>

loginwidget::loginwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwidget)
{
    ui->setupUi(this);
    //rw_p->hide();
    //connect(rw_p,&regist::userRegist,this,&loginwidget::ONUserRegist);//注册页面发信号
}

loginwidget::~loginwidget()
{
    delete ui;
}

void loginwidget::on_login_PB_clicked()//登录点击按钮
{
    QString name = ui->nameinput_LE->text();
    QString pswd = ui->pswdinput_LE->text();
    if(name.isEmpty()||pswd.isEmpty())
    {
        QMessageBox::warning(this,"登录","用户名和密码不能为空");
        return;
    }

    emit userLogin(name,pswd);
}

void loginwidget::on_regist_PB_clicked()
{
    this->hide();
    emit userRegist();
}

//void loginwidget::ONUserRegist(QString name, QString pswd)
//{
//    emit userRegist(name,pswd);//向widget发送注册信息;
//}


