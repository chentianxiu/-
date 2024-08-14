#ifndef CREATEGROUPDIALOG_H
#define CREATEGROUPDIALOG_H

#include <QDialog>

namespace Ui {
class CreateGroupDialog;
}

class CreateGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGroupDialog(QWidget *parent = nullptr);
    ~CreateGroupDialog();

    void setSelectList(QStringList text);//传进来的好友列表

signals:
    void creategroup(QString groupName,QStringList members);

private slots:
    void on_moveRight_PB_clicked();

    void on_moveLeft_PB_clicked();

    void on_buttonBox_accepted();

private:
    Ui::CreateGroupDialog *ui;
};

#endif // CREATEGROUPDIALOG_H
