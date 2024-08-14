#ifndef MESSAGEPROTOCAL_H
#define MESSAGEPROTOCAL_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTcpSocket>

class messageProtocal
{
public:
    messageProtocal(){};
    messageProtocal(char *data,int size);
    messageProtocal(QByteArray& data);
    QJsonObject message;

    //请求类型
    QString type();
    void setType(QString type);

    //字符数据
    QString getStringValue(QString key);
    void addValue(QString key,QString value);

    //整形数据
    int getIntValue(QString key);
    void addValue(QString Key,int value);

    //列表数据
    QStringList getListValue(QString Key);
    void addValue(QString key,QStringList values);

    //发送包
    void sendMsg(QTcpSocket* socket);
    //接受包
    void recvMsg(QTcpSocket* socket);
};

#endif // MESSAGEPROTOCAL_H
