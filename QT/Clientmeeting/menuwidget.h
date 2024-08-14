#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QMap>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include<QDebug>
#include <QTableWidgetItem>
#include "addfrienddialog.h"
#include "privatechatwidget.h"
#include "creategroupdialog.h"
#include "createmeetingdialog.h"
#include "groupchatwidget.h"

namespace Ui {
class menuwidget;
}

class menuwidget : public QWidget
{
    Q_OBJECT

public:
    explicit menuwidget(QWidget *parent = nullptr);
    ~menuwidget();

    void setFriendList(const QStringList friends);//初始化添加好友的操作，添加到好友列表--在用户登录成功从数据包中获得

    void setLoginUserName(const QString &value);//在用户登录成功从数据包中获得

    void setOtherUser(const QStringList &value);//在用户登录成功从数据包中获得

    void setgroups(const QStringList grouplist);//在用户登录成功从数据包中获得

    QString getLoginUserName() const;//获取名字

    void setPrivateMsg(QString friendName,QString msg);//私聊消息

    void setgroupMsg(QString sender,QString groupname,QString msg);//群聊消息

    void setFileInfo(QString sender,QString recver,QString filename);//设置接收文件信息

    void setFiles(QStringList files);//设置初始界面的文件信息显示

    void addMeeting(QString meetingName, QString host);//设置会议列表

    void addgroupname(QString groupname,QStringList members);//增加群组列表
    void addnewfriends(QString name);//增加一个好友
    void addnewfriends(QStringList friends);//增加很多好友

    void setgroupmembers(QString groupname,QStringList members);//获取群的成员列表

signals:
    void addFriends(QStringList friends);//向widget发送需要添加的好友信息，与widget关联

    void creategroup(QString groupName, QStringList members);//向widget发送需要添加的群组信息

    void sendPrivateMsg(QString sender,QString recver,QString msg);//发信号给主窗口-私聊

    void uploadPrivateFile(QString sender,QString recver,QString filePath,QString filename);//发信号给主窗口-上传文件

    void downloadFile(QString Sender,QString recver,QString filename);//发信号给主窗口-下载文件

    void createMeeting(QString host,QString meetingName,QStringList members);//发信号给主窗口--增加会议

    void joinMeeting(QString Host);//发信号给主窗口--收到创建会议的消息后，加入会议消息发到主窗口

    void sendgroupMsg(QString sender,QString recver,QString msg);//发信号给主窗口-群聊
    void uploadgroupFile(QString sender,QString recver,QString filePath,QString filename);//发信号给主窗口-上传群鸟文件

    void needmembers(QString groupName);

private slots:
    void on_addFriend_PB_clicked();//点击添加好友按钮，将其他人员列表传入afd中
    void on_addFriends(QStringList friends);//添加好友，接收添加好友列表界面的信息，与afd关联

    void on_creategroup(QString groupName,QStringList members);//添加群组，接收cgd消息，

    void on_friendList_LW_itemClicked(QListWidgetItem *item);//点击左侧栏
    void onSendPrivateMsg(QString recver,QString msg);

    void onSendgroupMsg(QString groupname,QString msg);

    void onUploadPrivateFile(QString recver,QString filePath,QString filename);//上传文件在menu的处理函数，转发一遍信号

    void on_fileList_TW_cellDoubleClicked(int row, int column);

    void on_creategroup_PB_clicked();//点击创建群组


    void on_createMeeting_PB_clicked();//创建会议

    void on_createMeetingAccepted();//连接cmd_p和这边的信号

    void on_groupList_LW_itemClicked(QListWidgetItem *item);//点击群聊栏目

    //void onSendgroupmsg(QString groupname,QString msg);

    void onUploadgroupFile(QString groupname,QString filePath,QString filename);

    void on_meetingList_LW_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::menuwidget *ui;
    addfriendDialog afd; //添加用户增加好友对话框
    CreateGroupDialog cgd;//添加用户增加群组对话框
    QStringList otherUser;
    QStringList startgroupselectlist;//创建群组列表时，将所有用户保存，方便之后选择

    QString loginUserName;
    QMap<QString,privatechatwidget*> friendList;//私聊窗口存起来

    QWidget* currentWidget = nullptr;//定义一个临时窗口


    QStringList members;//存储群组成员
    QString groupname;//存储群名字
    QMap<QString,groupchatwidget*> groupchatList;//群聊窗口存起来

    createmeetingDialog cmd_p;//添加成员增加会议对话框

    QVBoxLayout * frameLayout;
};

#endif // MENUWIDGET_H
