#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QMessageBox>


LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::on_login_PB_clicked()
{
    QString name = ui->nameInput_LE->text();
    QString pswd = ui->pswdInput_LE->text();
    if(name.isEmpty()||pswd.isEmpty())
    {
        QMessageBox::warning(this,"登录","用户名和密码不能为空");
        return;
    }

    emit userLogin(name,pswd);

}
