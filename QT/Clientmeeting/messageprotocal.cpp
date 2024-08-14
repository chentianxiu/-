#include "messageprotocal.h"

messageProtocal::messageProtocal()
{

}

messageProtocal::messageProtocal(char *data, int size)
{
    if(data!=nullptr && size>0)
    {
        message = QJsonDocument::fromRawData(data,size).object(); // 将字符串变成json对象进行操作
    }
}

messageProtocal::messageProtocal(QByteArray &data)
{
    message = QJsonDocument::fromJson(data).object();  //将字节数组变成json对象进行操作
}

QString messageProtocal::type()//读取类型
{
    return message["type"].toString();
}

void messageProtocal::setType(QString type)//设置类型
{
    message.insert("type",type);
}

QString messageProtocal::getStringValue(QString key)//读取字符数据
{
    return message[key].toString();
}

void messageProtocal::addValue(QString key, QString value)//添加字符数据
{
    message.insert(key,value);
}

int messageProtocal::getIntValue(QString key)//读取整形数据
{
    return message[key].toInt();
}

void messageProtocal::addValue(QString Key, int value)//添加整形数据
{
    message.insert(Key,value);
}

QStringList messageProtocal::getListValue(QString Key)//读取列表数据
{
    QJsonArray arr = message[Key].toArray();
    QStringList list;
    for(auto it:arr)
    {
        list.append(it.toString());
    }
    return list;
}

void messageProtocal::addValue(QString key, QStringList values)//添加列表数据
{
    QJsonArray array;
    for(QString it:values)
    {
        array.append(it);
    }

    message.insert(key,array);
}

void messageProtocal::sendMsg(QTcpSocket *socket)//发送包
{
    //json转成QByteArray用于发送
    QJsonDocument doc(message);
    QByteArray array = doc.toJson();

    //先发送长度，防止读取粘包的问题
    qint64 size = array.size();
    socket->write(reinterpret_cast<char*>(&size),4);//指针类型转换，将一个指针转换为另一个指针

    //再发数据
    socket->write(array);
}

void messageProtocal::recvMsg(QTcpSocket *socket)//接收包
{
    //先读取长度，保证不会多读
    int len = 0;
    socket->read(reinterpret_cast<char*>(&len),4);

    //在读取数据
    QByteArray arr =  socket->read(len);

    //将数据转成json对象保存在类中
    message = QJsonDocument::fromJson(arr).object();
}
