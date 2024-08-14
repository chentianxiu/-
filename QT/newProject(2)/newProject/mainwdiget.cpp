#include "mainwdiget.h"
#include "ui_mainwdiget.h"
#include <QMessageBox>
#include "dbhelper.h"

mainWdiget::mainWdiget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainWdiget)
{
    ui->setupUi(this);  //设计界面初始化
    this->ui->Name_LE->setPlaceholderText("请输入用户名");
    this->ui->Pswd_LE->setPlaceholderText("请输入密码");
    this->ui->Pswd_LE->setEchoMode(QLineEdit::Password);

    uw_p = new UserWidget; //生成用户窗口实例

    connect(ui->Login_PB,&QAbstractButton::clicked,this,&mainWdiget::on_LoginClicked); //连接登录点击的信号和槽函数
    connect(uw_p,&UserWidget::logout,this,&mainWdiget::show);   //连接退出登录的信号和槽

    rw_p = new registWidget;//生成注册窗口实例
    connect(rw_p,&registWidget::userRegisted,this,&mainWdiget::on_userRegisted);


}

mainWdiget::~mainWdiget()
{
    delete ui;
}


void mainWdiget::on_Regist_LE_clicked()
{
    rw_p->show();
}

void mainWdiget::on_userRegisted(QString name, QString pswd)
{
    if(!dbhelper::getInstance()->addNewUser(name,pswd))
    {
        QMessageBox::warning(this,"用户注册","该用户已存在");
    }
    else
    {
        QMessageBox::information(this,"用户注册","注册成功"); //弹出提示框
    }
}

void mainWdiget::on_LoginClicked()
{
    QString name = ui->Name_LE->text();
    QString pswd = ui->Pswd_LE->text();
    if(name.isEmpty() || pswd.isEmpty())
    {
        QMessageBox::warning(this,"用户登录","密码或者用户名不能为空");
        return ;
    }

    if(!dbhelper::getInstance()->fineUser(name,pswd))
    {
        QMessageBox::warning(this,"用户登录","用户名或密码错误");
    }
    else
    {
        QMessageBox::information(this,"用户登录","登录成功");
        ui->Pswd_LE->clear(); //清理密码信息
        uw_p->show();
        this->hide();
    }

}


void mainWdiget::on_checkBox_stateChanged(int state)
{
    if(state == Qt::Checked)
    {
        ui->Pswd_LE->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->Pswd_LE->setEchoMode(QLineEdit::Normal);
    }
}
