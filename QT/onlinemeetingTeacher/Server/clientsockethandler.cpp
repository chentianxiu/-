#include "clientsockethandler.h"
#include "dbhelper.h"
#include <QFile>

clientSocketHandler::clientSocketHandler(QTcpSocket *socket, QObject *parent) :
    QObject(parent),socket(socket)
{
    connect(socket,&QTcpSocket::readyRead,this,&clientSocketHandler::onReadyRead);
}

void clientSocketHandler::sendMsg(messageProtocal &pack)
{
    pack.sendMsg(socket);
}

void clientSocketHandler::onReadyRead()
{
    while(socket->bytesAvailable()>0)
    {
        messageProtocal pack(nullptr,0); //生成数据包对象
        pack.recvMsg(socket); //读取数据

        //数据处理
        handler(pack);
    }
}

QString clientSocketHandler::getLoginUserName() const
{
    return LoginUserName;
}

void clientSocketHandler::handler(messageProtocal &pack)
{
    QString type = pack.type(); //获取请求类型
    if(type == "user login")
    {
        loginHandler(pack);
    }
    else if(type == "add friend")
    {
        addfriendHandler(pack);
    }
    else if(type == "private msg")
    {
        privateMsgHandler(pack);
    }
    else if(type == "private file")
    {
        privateFileHandler(pack);
    }
    else if(type == "download file")
    {
        downloadFile(pack);
    }
    else if(type == "create meeting")
    {
        createMeetingHandler(pack);
    }
    else if(type == "join meeting")
    {
        joinMeetingHandler(pack);
    }
}

void clientSocketHandler::loginHandler(messageProtocal &pack)
{
    //获取用户信息
    QString name = pack.getStringValue("name");
    QString pswd = pack.getStringValue("pswd");
    //检测登录结果
    int ret = dbhelper::getInstance()->userLogin(name,pswd);
    //记录结果
    pack.addValue("result",ret);
    if(ret)
    {
        LoginUserName = name;

        QStringList users = dbhelper::getInstance()->getUsers();
        QStringList friends = dbhelper::getInstance()->getFriends(name);
        QStringList files = dbhelper::getInstance()->getFiles(name);
        users.removeAll(name);
//        QSet<QString> set1 = QSet<QString>(users.begin(),users.end());
//        QSet<QString> result = set1.subtract(QSet<QString>(friends.begin(),friends.end()));
//        users = QList<QString>(result.begin(),result.end());
//                for(auto it:friends)
//                {
//                   users.removeAll(it);
//                }


        pack.addValue("userList",users);
        pack.addValue("friend",friends);
        pack.addValue("filelist",files);
    }

    //反馈给客户端
    pack.sendMsg(socket);
}

void clientSocketHandler::addfriendHandler(messageProtocal &pack)
{
    QString name = pack.getStringValue("name");
    QStringList friends = pack.getListValue("friends");
    for(auto it:friends)
    {
        dbhelper::getInstance()->addFriend(name,it);
    }
}

void clientSocketHandler::privateMsgHandler(messageProtocal &pack)
{
    QString recver = pack.getStringValue("recver");
    emit this->privateMsg(recver,pack);
}

void clientSocketHandler::privateFileHandler(messageProtocal &pack)
{
    QString sender = pack.getStringValue("sender");
    QString recver = pack.getStringValue("recver");
    QString fileName = pack.getStringValue("filename");
    QString data = pack.getStringValue("data");

    QString filePath = "./document/"+sender+recver+fileName;
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    file.write(data.toLocal8Bit().data());
    file.close();

    if(!dbhelper::getInstance()->addFile(filePath,sender,recver,fileName,"private"))
    {
        return;
    }
    messageProtocal retPack;
    retPack.setType("private file");
    retPack.addValue("sender",sender);
    retPack.addValue("recver",recver);
    retPack.addValue("filename",fileName);

    emit privateFile(recver,retPack);

    retPack.sendMsg(socket);
}

void clientSocketHandler::downloadFile(messageProtocal &pack)
{
    QString sender = pack.getStringValue("sender");
    QString recver = pack.getStringValue("recver");
    QString filename = pack.getStringValue("filename");
    QString filepath = dbhelper::getInstance()->getFilePath(sender,recver,filename);
    qDebug()<<filepath;

    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QTextStream steamer(&file);
    QString data;
    while(!steamer.atEnd())
    {
        QString str = steamer.read(1024);
        data += str;
    }
    file.close();
    pack.addValue("data",data);
    pack.sendMsg(socket);
}

void clientSocketHandler::createMeetingHandler(messageProtocal &pack)
{
    emit createMeeting(pack);
}

void clientSocketHandler::joinMeetingHandler(messageProtocal &pack)
{
    emit joinMeeting(socket,pack);
}
