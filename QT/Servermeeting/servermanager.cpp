#include "servermanager.h"
#include "dbhelper.h"

servermanager::servermanager(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    server->listen(listenIp,listenPort);
    connect(server,&QTcpServer::newConnection,this,&servermanager::onNewConnection);

    dbhelper::getInstance(); //加载数据库
}

void servermanager::onNewConnection()
{
    QTcpSocket * socket = server->nextPendingConnection(); //同意连接得到套接字的指针
    client_socket_handler* handler = new client_socket_handler(socket,this);  //生成客户端套接字处理-管理套接字
    connect(handler,&client_socket_handler::privateMsg,this,&servermanager::onPrivateMsg);//私聊

    connect(handler,&client_socket_handler::groupMsg,this,&servermanager::ongroupMsg);//群聊

    connect(handler, &client_socket_handler::clientDisconnected, this, &servermanager::onClientDisconnected);

    connect(handler, &client_socket_handler::addFriends, this, &servermanager::onaddFriends);

    connect(handler,&client_socket_handler::privateFile,this,&servermanager::onPrivateFile);//私人上传文件

    connect(handler,&client_socket_handler::groupFile,this,&servermanager::ongroupFile);//群上传文件


    connect(handler,&client_socket_handler::creategroup,this,&servermanager::oncreategroup);//创建群聊

    connect(handler,&client_socket_handler::createMeeting,this,&servermanager::onCreateMeeting);//创建会议

    connect(handler,&client_socket_handler::joinMeeting,this,&servermanager::onJoinMeeting);//加入会议

    clients.append(handler); //将处理类放到容器中统一管理
    //qDebug()<<handler->getLoginUserName();
}

void servermanager::onPrivateMsg(QString recver, messageProtocal pack)//给单个用户发送私聊包
{
    for(auto it:clients)
    {
        if(recver == it->getLoginUserName())
        {
            //qDebug()<<recver;
            it->sendMsg(pack);
            break;
        }
    }
}

void servermanager::ongroupMsg(QString groupname, messageProtocal pack)
{

    QStringList members = dbhelper::getInstance()->getGroupmembers(groupname);
    QString name = pack.getStringValue("sender");
    for(auto it:clients)
    {
        if((members.contains(it->getLoginUserName()))&&(it->getLoginUserName()!= name))
        {
            //qDebug()<<recver;
            it->sendMsg(pack);
        }
    }
}

void servermanager::onClientDisconnected(const QString &name)//断开连接
{
    qDebug() << "Client disconnected:" << name;
    dbhelper::getInstance()->setunonline(name);

    // 从 clients 容器中移除对应的 client_socket_handler 对象
    for (int i = 0; i < clients.size(); ++i) {
        if (clients[i]->getLoginUserName() == name) {
            client_socket_handler* handler = clients.takeAt(i);
            handler->deleteLater(); // 删除对象
            break;
        }
    }
}

void servermanager::onaddFriends(messageProtocal pack)//从服务器发来的增加好友的消息
{
    QString name = pack.getStringValue("name");
    QStringList friends = pack.getListValue("friends");
    for(auto it:clients)
    {
        if(friends.contains(it->getLoginUserName()))
        {
            //qDebug()<<it->getLoginUserName();
            it->sendMsg(pack);
        }
        if(name==it->getLoginUserName())
        {
            it->sendMsg(pack);
        }

    }
}

void servermanager::onPrivateFile(QString recver, messageProtocal pack)//向好友发送文件
{
    for(auto it:clients)
    {
        if(recver == it->getLoginUserName())
        {
            it->sendMsg(pack);
            break;
        }
    }
}

void servermanager::ongroupFile(QString groupname, messageProtocal pack)//向群发送群文件
{
    QStringList members = dbhelper::getInstance()->getGroupmembers(groupname);
    QString name = pack.getStringValue("sender");
    for(auto it:clients)
    {
        if(members.contains(it->getLoginUserName())&&it->getLoginUserName()!= name)
        {
            //qDebug()<<recver;
            it->sendMsg(pack);
            break;
        }
    }
}

void servermanager::oncreategroup(messageProtocal pack)//创建群聊包
{
    QStringList members = pack.getListValue("members");
    for(auto it:clients)
    {
        if(members.contains((it->getLoginUserName())))
        {
            it->sendMsg(pack);
        }
    }
}

void servermanager::onCreateMeeting(messageProtocal pack)
{
    QString host = pack.getStringValue("host");
    if(meetings.contains(host)){return;}
    meetinginfo meeting;
    meeting.host = host;
    meeting.out_members = pack.getListValue("members");
    meeting.meetingName = pack.getStringValue("meetingname");
    meetings.insert(host,meeting);
    for(auto it:clients)
    {
        if(meeting.out_members.contains(it->getLoginUserName()))
        {
            it->sendMsg(pack);
        }
        else if(host == it->getLoginUserName())
        {
            it->sendMsg(pack);
        }
    }
}

void servermanager::onJoinMeeting(QTcpSocket *user, messageProtocal pack)
{
    QString host = pack.getStringValue("host");
    QString userName = pack.getStringValue("username");


    if(!meetings.contains(host)){return;}
    if(userName != host)
    {
        messageProtocal pack2;
        pack2.setType("member in");
        pack2.addValue("member",userName);
        //通知进入会议的用户,有新成员进入
        for(auto it:clients)
        {
            if(meetings[host].in_members.contains(it->getLoginUserName()))
            {
                it->sendMsg(pack2);
            }
            else if(host == it->getLoginUserName())
            {
                it->sendMsg(pack2);
            }
        }
        //设置用户的参会状态
        meetings[host].in_members.append(userName);
        meetings[host].out_members.removeAll(userName);
    }

    pack.addValue("meetingname",meetings[host].meetingName);
    pack.addValue("in_members",meetings[host].in_members);
    pack.addValue("out_members",meetings[host].out_members);
    pack.addValue("ip",meetings[host].ip.toString());
    pack.addValue("textport",meetings[host].textPort);
    pack.addValue("videoport",meetings[host].videoPort);
    pack.addValue("audioport",meetings[host].audioPort);
    pack.sendMsg(user);
}
