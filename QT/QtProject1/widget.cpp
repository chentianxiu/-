#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include "dbhelper.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);//设置界面初始化,必须放在上面(创建对象啥的)
    this->ui->username_LE->setPlaceholderText("请输入用户名");
    this->ui->pwd_LE->setPlaceholderText("请输入密码");
    this->ui->pwd_LE->setEchoMode(QLineEdit::Password);

    uw_p = new userwidget; //生成用户窗口实例

    //连接登录点击的信号和槽函数
    connect(ui->login_PB,&QAbstractButton::clicked,this,&Widget::on_LoginClicked);

    connect(uw_p,&userwidget::logout,this,&Widget::show);   //连接退出登录的信号和槽

    rw_p = new registwidget;//生成注册窗口实例
    connect(rw_p,&registwidget::userRegisted,this,&Widget::on_userRegisted);
}

Widget::~Widget()
{
    delete ui;
}

//点击注册按钮
void Widget::on_regist_PB_clicked()
{
    rw_p->show();
}

void Widget::on_LoginClicked()
{
    QString name = ui->username_LE->text();
    QString pswd = ui->pwd_LE->text();
    if(name.isEmpty() || pswd.isEmpty())
    {
        QMessageBox::warning(this,"用户登录","密码或者用户名不能为空");
        return ;
    }

    if(!dbhelper::getInstance()->findUser(name,pswd))
    {

        QMessageBox::warning(this,"用户登录","账号或者密码错误");
    }
    else
    {
        QMessageBox::information(this,"用户登录","登录成功");
        ui->pwd_LE->clear(); //清理密码信息
        uw_p->show();
        this->hide();
    }

}


void Widget::on_userRegisted(QString name, QString pswd)
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

void Widget::on_checkBox_stateChanged(int state)
{
    if(state == Qt::Checked)
    {
        ui->pwd_LE->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->pwd_LE->setEchoMode(QLineEdit::Normal);
    }
}

