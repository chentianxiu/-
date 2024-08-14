#ifndef SERVERMANANGER_H
#define SERVERMANANGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMap>

#include "clientsockethandler.h"
#include "messageprotocal.h"
#include "meetinginfo.h"

class ServerMananger : public QObject
{
    Q_OBJECT
public:
    explicit ServerMananger(QString ip, int port, QObject *parent = nullptr);

signals:

private slots:
    void onNewConnection();
    void onPrivateMsg(QString recver,messageProtocal pack);
    void onPrivateFile(QString recver,messageProtocal pack);
    void onCreateMeeting(messageProtocal pack);
    void onJoinMeeting(QTcpSocket *user, messageProtocal pack);

private:
    QTcpServer* server;
    QList<clientSocketHandler*> clients;
    QMap<QString,meetingInfo> meetings;

    QHostAddress listenIp = QHostAddress("127.0.0.1");
    int listenPort = 8888;

};

#endif // SERVERMANANGER_H
