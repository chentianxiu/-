#ifndef MESSAGEPROTOCAL_H
#define MESSAGEPROTOCAL_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTcpSocket>


class messageProtocal
{
public:
    messageProtocal(){}
    messageProtocal(char *data,int size);
    messageProtocal(QByteArray& data);
    QJsonObject message;

    //请求类型
    QString type();//读取类型,一般接收消息
    void setType(QString type);//设置类型，一般发送消息

    //字符数据
    QString getStringValue(QString key);//读取字符数据
    void addValue(QString key,QString value);//添加字符数据

    //整形数据
    int getIntValue(QString key);//读取整形数据
    void addValue(QString Key,int value);//添加整形数据

    //列表数据
    QStringList getListValue(QString Key);//读取列表数据
    void addValue(QString key,QStringList values);//添加列表数据

    //发送包
    void sendMsg(QTcpSocket* socket);
    //接受包
    void recvMsg(QTcpSocket* socket);
};

#endif // MESSAGEPROTOCAL_H
