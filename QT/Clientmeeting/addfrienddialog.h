#ifndef ADDFRIENDDIALOG_H
#define ADDFRIENDDIALOG_H

#include <QDialog>

namespace Ui {
class addfriendDialog;
}

class addfriendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addfriendDialog(QWidget *parent = nullptr);
    ~addfriendDialog();

    void setSelectList(QStringList text);//列表显示
signals:
    void addfriends(QStringList friends);//向主窗口发送添加好友的信息列表

private slots:
    void on_addName_PB_clicked();//点击增加好友按钮

    void on_moveRight_PB_clicked();//点击右移按钮

    void on_moveLeft_PB_clicked();//点击左移按钮

    void on_buttonBox_accepted();//点击下面的ok按钮

private:
    Ui::addfriendDialog *ui;
};

#endif // ADDFRIENDDIALOG_H
