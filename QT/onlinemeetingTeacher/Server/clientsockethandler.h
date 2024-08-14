#ifndef CLIENTSOCKETHANDLER_H
#define CLIENTSOCKETHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include "messageprotocal.h"

class clientSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit clientSocketHandler(QTcpSocket* socket,QObject *parent = nullptr);

    void sendMsg(messageProtocal &pack);

    QString getLoginUserName() const;

signals:
    void privateMsg(QString recver,messageProtocal pack);
    void privateFile(QString recver,messageProtocal pack);
    void createMeeting(messageProtocal pack);
    void joinMeeting(QTcpSocket*user, messageProtocal pack);
private slots:
    void onReadyRead();
private:
    QString LoginUserName;

    QTcpSocket * socket;

    void handler(messageProtocal& pack);

    void loginHandler(messageProtocal& pack);

    void addfriendHandler(messageProtocal& pack);

    void privateMsgHandler(messageProtocal& pack);

    void privateFileHandler(messageProtocal& pack);

    void downloadFile(messageProtocal& pack);

    void createMeetingHandler(messageProtocal& pack);

    void joinMeetingHandler(messageProtocal& pack);

};

#endif // CLIENTSOCKETHANDLER_H
