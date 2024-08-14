#ifndef MAINWDIGET_H
#define MAINWDIGET_H

#include <QWidget>
#include <QMap>
#include "userwidget.h"
#include "registwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWdiget; }
QT_END_NAMESPACE

class mainWdiget : public QWidget
{
    Q_OBJECT

public:
    mainWdiget(QWidget *parent = nullptr);
    ~mainWdiget();

private slots:
    void on_Regist_LE_clicked();
    void on_userRegisted(QString name,QString pswd);
    void on_LoginClicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::mainWdiget *ui;
    UserWidget* uw_p; //用户登录后的窗口
    registWidget* rw_p;//注册窗口

};
#endif // MAINWDIGET_H
