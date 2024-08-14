#ifndef CLIENT_SOCKET_HANDLER_H
#define CLIENT_SOCKET_HANDLER_H

#include <QObject>
#include <QTcpSocket>
#include "messageprotocal.h"
#include "dbhelper.h"

class client_socket_handler : public QObject
{
    Q_OBJECT
public:
    explicit client_socket_handler(QTcpSocket* socket,QObject *parent = nullptr);

    void sendMsg(messageProtocal &pack);//给用户发消息

    QString getLoginUserName() const;

signals:
    void privateMsg(QString recver,messageProtocal pack);//向server发送信号

    void groupMsg(QString groupname,messageProtocal pack);//向server发送信号

    void addFriends(messageProtocal pack);//向server发送信号

    void clientDisconnected(const QString &name); // 向server发送信号

    void privateFile(QString recver,messageProtocal pack);//向server发送信号

    void groupFile(QString groupname,messageProtocal pack);//向server发送信号

    void creategroup(messageProtocal pack);//向server发送信号

    void createMeeting(messageProtocal pack);//向server发送信号

     void joinMeeting(QTcpSocket*user, messageProtocal pack);//向server发送信号

public slots:
    void onReadyRead();//数据处理

    void onDisconnected();//客户端断开连接

private:
    QString LoginUserName;

    QTcpSocket * socket;

    void handler(messageProtocal& pack);//数据处理下一级的函数

    void loginHandler(messageProtocal& pack);//登录数据包处理

    void registHandler(messageProtocal& pack);//注册数据包处理

    void addfriendHandler(messageProtocal& pack);//增加朋友数据包处理

    void creatgroupHandler(messageProtocal& pack);//创建小组数据包处理

    void privateMsgHandler(messageProtocal& pack);//私聊数据包处理

    void groupmsgHandler(messageProtocal& pack);// 群聊数据包处理
    void getgroupmembers(messageProtocal& pack);//获取群成员数据包处理

    void privateFileHandler(messageProtocal& pack);//单人文件上传

    void groupfileHandler(messageProtocal& pack);//群文件上传

    void downloadFile(messageProtocal& pack);//文件下载

    void createMeetingHandler(messageProtocal& pack);//创建会议数据包

    void joinMeetingHandler(messageProtocal& pack);//加入会议处理包



};

#endif // CLIENT_SOCKET_HANDLER_H
