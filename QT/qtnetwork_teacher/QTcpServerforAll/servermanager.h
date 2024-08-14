#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QList>

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(QObject *parent = nullptr);

signals:
    void newConnection(QString ip,QString port);
    void disConnection(QString ip,QString port);

private slots:
    void on_NewConnection();
    void on_readyRead();
    void on_disconnect();

private:
    QTcpServer * server;
    QList<QTcpSocket*> clients;
};

#endif // SERVERMANAGER_H
