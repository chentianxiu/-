#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "regist.h"

namespace Ui {
class loginwidget;
}

class loginwidget : public QWidget
{
    Q_OBJECT

public:
    explicit loginwidget(QWidget *parent = nullptr);
    ~loginwidget();

signals:
    void userLogin(QString name,QString pswd);
    void userRegist();

private slots:
    void on_login_PB_clicked();

    void on_regist_PB_clicked();//注册点击按钮
    //void ONUserRegist(QString name,QString pswd);//接收到来自注册页面的信息

private:
    Ui::loginwidget *ui;
    //regist * rw_p;
};

#endif // LOGINWIDGET_H
