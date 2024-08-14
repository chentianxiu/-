#include "servermananger.h"
#include "dbhelper.h"

ServerMananger::ServerMananger(QString ip,int port,QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    server->listen(listenIp,listenPort);
    connect(server,&QTcpServer::newConnection,this,&ServerMananger::onNewConnection);
    dbhelper::getInstance(); //加载数据库
}

void ServerMananger::onNewConnection()
{
    QTcpSocket * socket = server->nextPendingConnection(); //同意连接得到套接字的指针
    clientSocketHandler* handler = new clientSocketHandler(socket,this);  //生成客户端套接字处理-管理套接字
    connect(handler,&clientSocketHandler::privateMsg,this,&ServerMananger::onPrivateMsg);
    connect(handler,&clientSocketHandler::privateFile,this,&ServerMananger::onPrivateFile);
    connect(handler,&clientSocketHandler::createMeeting,this,&ServerMananger::onCreateMeeting);
    connect(handler,&clientSocketHandler::joinMeeting,this,&ServerMananger::onJoinMeeting);

    clients.append(handler); //将处理类放到容器中统一管理
}

void ServerMananger::onPrivateMsg(QString recver, messageProtocal pack)
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

void ServerMananger::onPrivateFile(QString recver, messageProtocal pack)
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

void ServerMananger::onCreateMeeting(messageProtocal pack)
{
    QString host = pack.getStringValue("host");
    if(meetings.contains(host)){return;}
    meetingInfo meeting;
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

void ServerMananger::onJoinMeeting(QTcpSocket* user,messageProtocal pack)
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
