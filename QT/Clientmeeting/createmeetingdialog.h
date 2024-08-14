#ifndef CREATEMEETINGDIALOG_H
#define CREATEMEETINGDIALOG_H

#include <QDialog>

namespace Ui {
class createmeetingDialog;
}

class createmeetingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createmeetingDialog(QWidget *parent = nullptr);
    ~createmeetingDialog();

    void setSelectList(QStringList list);//列表人选

    void prepareMeetingName(QString name);//会议名称

    QString getMeetingName();//获取会议名称

    QStringList getmemberList();//获取会议成员列表

private slots:
    void on_addMember_PB_clicked();

    void on_removeMember_PB_clicked();


private:
    Ui::createmeetingDialog *ui;
};

#endif // CREATEMEETINGDIALOG_H
