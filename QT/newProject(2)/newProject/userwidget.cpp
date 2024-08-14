#include "userwidget.h"
#include "ui_userwidget.h"
#include <QMessageBox>

UserWidget::UserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidget)
{
    ui->setupUi(this);
}

UserWidget::~UserWidget()
{
    delete ui;
}

void UserWidget::on_pushButton_clicked()
{
    int ret = QMessageBox::question(this,"退出","是否要退出登录",QMessageBox::Ok|QMessageBox::Cancel);
    if(ret == QMessageBox::Ok)
    {
        this->hide();
        emit this->logout();
    }
}
