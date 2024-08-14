#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMap>
#include "client_socket_handler.h"
#include "meetinginfo.h"
#include "messageprotocal.h"

class servermanager : public QObject
{
    Q_OBJECT
public:
    explicit servermanager(QObject *parent = nullptr);

signals:

public slots:
    void onNewConnection();

    //给单个用户发送私聊包
    void onPrivateMsg(QString recver,messageProtocal pack);

    void ongroupMsg(QString groupname,messageProtocal pack);//群鸟发消息

    void onClientDisconnected(const QString &name); // 断开连接槽函数

    void onaddFriends(messageProtocal pack);

    void onPrivateFile(QString recver,messageProtocal pack);//连接发送来的信号

    void ongroupFile(QString groupname,messageProtocal pack);//群聊的上传文件

    void oncreategroup(messageProtocal pack);//连接创建群组会议包的处理函数

    void onCreateMeeting(messageProtocal pack);//连接创建会议包的处理函数

    void onJoinMeeting(QTcpSocket *user, messageProtocal pack);//连接加入会议处理函数

private:
    QTcpServer* server;
    QList<client_socket_handler*> clients;

    QMap<QString,meetinginfo> meetings;

    QHostAddress listenIp = QHostAddress("127.0.0.1");
    int listenPort = 8888;
};

#endif // SERVERMANAGER_H
