#ifndef PRIVATECHATWIDGET_H
#define PRIVATECHATWIDGET_H

#include <QWidget>

namespace Ui {
class privatechatwidget;
}

class privatechatwidget : public QWidget
{
    Q_OBJECT

public:
    explicit privatechatwidget(QString friendName,QWidget *parent = nullptr);//需要传个朋友名字进来
    ~privatechatwidget();

    void addNewMsg(QString message);//接收消息

signals:
    void sendMsg(QString recver,QString msg);//每次发消息给widget发信号，方便传到服务器上

    void uploadFile(QString recver,QString filepath,QString filename);//传到menu，menu再传到widget

private slots:
    void on_send_PB_clicked();//点击发送消息


    void on_uploadFile_PB_clicked();//上传文件槽函数

private:
    Ui::privatechatwidget *ui;
    QString friendName;
};

#endif // PRIVATECHATWIDGET_H
