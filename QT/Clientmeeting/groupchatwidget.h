#ifndef GROUPCHATWIDGET_H
#define GROUPCHATWIDGET_H

#include <QWidget>

namespace Ui {
class groupchatwidget;
}

class groupchatwidget : public QWidget
{
    Q_OBJECT

public:
    explicit groupchatwidget(QString groupname,QStringList grouplist,QWidget *parent = nullptr);
    ~groupchatwidget();

    void addNewMsg(QString sender,QString message);

    void setgroupmemberslist(QStringList members);



signals:
    void sendMsg(QString groupname,QString msg);//向外面发信号

    void uploadFile(QString groupname,QString filepath,QString filename);//上传文件的信号函数


private slots:
    void on_send_PB_clicked();//群聊发送消息

    void on_uploadFile_PB_clicked();//群聊上传文件

private:
    Ui::groupchatwidget *ui;

    QString groupname;
    QStringList groupmembers;
};

#endif // GROUPCHATWIDGET_H
