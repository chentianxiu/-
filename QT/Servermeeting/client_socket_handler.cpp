#include "client_socket_handler.h"
#include<QDebug>
#include <QFile>

client_socket_handler::client_socket_handler(QTcpSocket *socket, QObject *parent) :
    QObject(parent),socket(socket)
{
    connect(socket,&QTcpSocket::readyRead,this,&client_socket_handler::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &client_socket_handler::onDisconnected);
}

void client_socket_handler::sendMsg(messageProtocal &pack)//给客户端发送信息
{
    pack.sendMsg(socket);
}

void client_socket_handler::onReadyRead()//数据处理
{

    while(socket->bytesAvailable()>0)
    {
        messageProtocal pack(nullptr,0); //生成数据包对象
        pack.recvMsg(socket); //读取数据

        //数据处理
        handler(pack);
    }
}

void client_socket_handler::onDisconnected()
{
     emit clientDisconnected(LoginUserName);
}

QString client_socket_handler::getLoginUserName() const
{
    return LoginUserName;
}

void client_socket_handler::handler(messageProtocal &pack)//数据处理下一级函数
{
    QString type = pack.type(); //获取请求类型
    if(type == "user login")
    {
        loginHandler(pack);//登录包
    }
    else if(type == "add friend")
    {
        addfriendHandler(pack);//添加朋友包
    }
    else if (type == "user regist")
    {
        registHandler(pack);//注册包
    }else if (type == "private msg")
    {

        privateMsgHandler(pack);//私聊包
    }else if(type == "private file")
    {
         privateFileHandler(pack);//上传文件包
    }else if(type == "download file")
    {
        downloadFile(pack);//下载文件包
    }
    else if(type == "create group")
    {
        creatgroupHandler(pack);//创建群组包
    }
    else if(type == "create meeting")
    {
        createMeetingHandler(pack);
    }
    else if(type == "join meeting")
    {
        joinMeetingHandler(pack);
    }
    else if(type =="group msg")//群聊包
    {
        groupmsgHandler(pack);
    }
    else if(type =="group file")
    {
        groupfileHandler(pack);
    }
    else if(type =="get groupmembers")
    {
        getgroupmembers(pack);
    }
}

void client_socket_handler::loginHandler(messageProtocal &pack)//登录数据包处理
{
    //获取用户信息
    QString name = pack.getStringValue("name");
    QString pswd = pack.getStringValue("pswd");

    pack.addValue("result",false);
    //检测登录结果
    int ret = dbhelper::getInstance()->userLogin(name,pswd);
    //记录结果
    int ret2 = dbhelper::getInstance()->isonline(name);
    if(ret==true&&ret2==false)//根据查找结果来判断是否登录
    {
        LoginUserName = name;

        QStringList users = dbhelper::getInstance()->getUsers();
        QStringList friends = dbhelper::getInstance()->getFriends(name);
        QStringList files = dbhelper::getInstance()->getFiles(name);
        QStringList groupNames = dbhelper::getInstance()->getGroupinfo(name);
        users.removeAll(name);
//        for(auto it:friends)
//        {
//            users.removeAll(it);
//        }
        pack.addValue("userList",users);
        pack.addValue("friend",friends);
        pack.addValue("filelist",files);
        pack.addValue("grouplist",groupNames);

        pack.addValue("result",1);
        dbhelper::getInstance()->setonline(name);
    }else if(ret2 == true){
        pack.addValue("result",2);//用户已经在线
    }else
    {
        pack.addValue("result",0);//用户没找到
    }
    //反馈给客户端
    pack.sendMsg(socket);
}

void client_socket_handler::registHandler(messageProtocal &pack)//注册数据包处理
{
    //获取用户信息
    QString name = pack.getStringValue("name");
    QString pswd = pack.getStringValue("pswd");
    //检测登录结果
    int ret = dbhelper::getInstance()->userLogin(name,pswd);
    //记录结果
    if(ret)//根据查找结果来判断是否登录
    {
        pack.addValue("result",0);//查到了，已经存在用户
    }
    else {
        int ret1 = dbhelper::getInstance()->userregist(name,pswd);
        if(ret1)
        {
            pack.addValue("result",1);//注册成功
        }
        else{
            pack.addValue("result",2);//注册失败
        }
    }

    pack.sendMsg(socket);
}

void client_socket_handler::addfriendHandler(messageProtocal &pack)//增加朋友数据包处理
{
    QString name = pack.getStringValue("name");//找到键值name对应的值，就是对应的实际的名字
    QStringList friends = pack.getListValue("friends");
    for(auto it:friends)
    {
        dbhelper::getInstance()->addFriend(name,it);
    }

    emit this->addFriends(pack);
}

void client_socket_handler::creatgroupHandler(messageProtocal &pack)//创建群聊
{
    QString name = pack.getStringValue("name");//找到名字
    QString groupName = pack.getStringValue("groupname");//得到小组名字
    QStringList members = pack.getListValue("members");//得到加入的成员列表

    dbhelper::getInstance()->addGroupmember(groupName,members);

    emit this->creategroup(pack);
}

void client_socket_handler::privateMsgHandler(messageProtocal &pack)//私聊数据包处理
{
    QString recver = pack.getStringValue("recver");
    emit this->privateMsg(recver,pack);
}

void client_socket_handler::getgroupmembers(messageProtocal &pack)
{
    QString groupName = pack.getStringValue("groupname");
    QStringList members = dbhelper::getInstance()->getGroupmembers(groupName);

    pack.addValue("groupmembers",members);

    pack.sendMsg(socket);

}

void client_socket_handler::groupmsgHandler(messageProtocal& pack)
{
    QString groupname = pack.getStringValue("groupname");
    emit this->groupMsg(groupname,pack);
}

void client_socket_handler::privateFileHandler(messageProtocal &pack)//单人文件上传
{
    QString sender = pack.getStringValue("sender");
    QString recver = pack.getStringValue("recver");
    QString fileName = pack.getStringValue("filename");
    QString data = pack.getStringValue("data");

    qDebug()<<recver;
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

void client_socket_handler::groupfileHandler(messageProtocal &pack)
{

    QString sender = pack.getStringValue("sender");
    QString groupname = pack.getStringValue("groupname");
    QString fileName = pack.getStringValue("filename");
    QString data = pack.getStringValue("data");

    qDebug()<<fileName;
    QString filePath = "./document/"+sender+groupname+fileName;
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    file.write(data.toLocal8Bit().data());
    file.close();

    qDebug()<<fileName;
    if(!dbhelper::getInstance()->addFile(filePath,sender,groupname,fileName,"group"))
    {
        return;
    }
    messageProtocal retPack;
    retPack.setType("group file");
    retPack.addValue("sender",sender);
    retPack.addValue("groupname",groupname);
    retPack.addValue("filename",fileName);

    emit groupFile(groupname,retPack);

    retPack.sendMsg(socket);
}

void client_socket_handler::downloadFile(messageProtocal &pack)//文件下载
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

void client_socket_handler::createMeetingHandler(messageProtocal &pack)
{
    emit createMeeting(pack);
}

void client_socket_handler::joinMeetingHandler(messageProtocal &pack)
{
    emit joinMeeting(socket,pack);
}
