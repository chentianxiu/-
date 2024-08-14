#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMap>
#include"userwidget.h"
#include"registwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_regist_PB_clicked();

    void on_LoginClicked();

    void on_userRegisted(QString name,QString pswd);//用户注册界面传过来的用户信息

    void on_checkBox_stateChanged(int arg1);//对勾按钮的设置


private:
    Ui::Widget *ui;
    userwidget* uw_p;//用户登录后的窗口
    registwidget* rw_p;//注册窗口
    //QMap<QString,QString> userList;//创建一个容器存储用户列表
};
#endif // WIDGET_H
