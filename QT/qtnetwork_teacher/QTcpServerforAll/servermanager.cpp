#include "servermanager.h"

ServerManager::ServerManager(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::AnyIPv4,8888);
    connect(server,&QTcpServer::newConnection,this,&ServerManager::on_NewConnection);
}

void ServerManager::on_NewConnection()
{
    QTcpSocket* socket = server->nextPendingConnection(); //同意连接
    connect(socket,&QTcpSocket::readyRead,this,&ServerManager::on_readyRead); //绑定接受处理函数
    connect(socket,&QTcpSocket::disconnected,this,&ServerManager::on_disconnect);//绑定断开连接的处理函数

    clients.append(socket); //保存到容器中

    emit this->newConnection(socket->peerAddress().toString(),QString::number(socket->peerPort())); //发出有新连接的信号

}

void ServerManager::on_readyRead()
{
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(this->sender()); //获取信号来源对象
    QByteArray bytes = socket->read(1024); //接受消息

    //转发给所有在线客户端
    for(auto it : clients)
    {
        it->write(bytes);
    }
}

void ServerManager::on_disconnect()
{
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(this->sender()); //获取信号来源对象
    //获取对应客户端的地址信息
    QString ip = socket->peerAddress().toString();
    QString port = QString::number(socket->peerPort());

    clients.removeOne(socket); //移除容器中对应元素
    socket->close();  //关闭套接字
    socket->deleteLater(); //释放套接字对象空间

    emit disConnection(ip,port);
}
