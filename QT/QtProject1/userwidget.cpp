#include "userwidget.h"
#include "ui_userwidget.h"
#include<QMessageBox>

userwidget::userwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userwidget)
{
    ui->setupUi(this);
}

userwidget::~userwidget()
{
    delete ui;
}

void userwidget::on_pushButton_clicked()
{
    int ret = QMessageBox::question(this,"退出","是否要退出登录",QMessageBox::Ok|QMessageBox::Cancel);
    if(ret == QMessageBox::Ok)
    {
        this->hide();
        emit this->logout();
    }
}
