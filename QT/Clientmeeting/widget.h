#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTcpSocket>
#include "loginwidget.h"
#include "messageprotocal.h"
#include "menuwidget.h"


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
    void onReadyRead();
    void on_login(QString name,QString pswd);
    void on_regist(QString name,QString pswd);
    void showrw_p();//显示注册界面
    void on_addFriend(QStringList list);//添加好友
    void on_sendPrivateMsg(QString sender,QString recver,QString msg);//私聊发消息
    void on_uploadPrivateFile(QString sender,QString recver,QString filepath,QString filename);//上传文件

    void on_sendgroupMsg(QString sender,QString groupname,QString msg);//群聊发消息

    void on_uploadgroupFile(QString sender,QString groupname,QString filepath,QString filename);//群聊上传文件

    void on_downloadFile(QString sender,QString recver,QString filename);//下载文件

    void on_creategroup(QString groupName, QStringList members);//创建群组


    void on_createMeeting(QString host,QString meetingName,QStringList members);//创建会议

     void on_joinMeeting(QString host);//加入会议

     void on_needmembers(QString groupName);//获取小组成员


private:
    Ui::Widget *ui;
    QVBoxLayout * mainLayout;
    loginwidget* lw_p;//登录窗口
    regist * rw_p;//注册窗口
    menuwidget* mw_p;//主窗口

    QTcpSocket* socket;

    void resultHandler(messageProtocal& pack);
};
#endif // WIDGET_H
