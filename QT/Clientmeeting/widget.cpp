#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include "meetingroomwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mainLayout = new QVBoxLayout(this);
    this->setLayout(mainLayout);

    lw_p = new loginwidget(this);
    mainLayout->addWidget(lw_p);
    connect(lw_p,&loginwidget::userLogin,this,&Widget::on_login);//连接登录

    rw_p = new regist(this);
    mainLayout->addWidget(rw_p);
    connect(rw_p,&regist::userRegist,this,&Widget::on_regist);//连接注册

    connect(lw_p,&loginwidget::userRegist,this,&Widget::showrw_p);//显示注册界面

    mw_p = new menuwidget(this);
    mainLayout->addWidget(mw_p);
    connect(mw_p,&menuwidget::addFriends,this,&Widget::on_addFriend);//增加好友

    connect(mw_p,&menuwidget::sendPrivateMsg,this,&Widget::on_sendPrivateMsg);//私聊

    connect(mw_p,&menuwidget::uploadPrivateFile,this,&Widget::on_uploadPrivateFile);//上传文件

    connect(mw_p,&menuwidget::downloadFile,this,&Widget::on_downloadFile);//下载文件

    connect(mw_p,&menuwidget::creategroup,this,&Widget::on_creategroup);//创建群组

    connect(mw_p,&menuwidget::createMeeting,this,&Widget::on_createMeeting);//创建会议

    connect(mw_p,&menuwidget::joinMeeting,this,&Widget::on_joinMeeting);//加入会议

    connect(mw_p,&menuwidget::needmembers,this,&Widget::on_needmembers);//获取小组成员


    //connect(mw_p,&menuwidget::joinMeeting,this,&Widget::on_joinMeeting);//mw_p的信号处理-加入会议

    //群聊
    connect(mw_p,&menuwidget::sendgroupMsg,this,&Widget::on_sendgroupMsg);
    //群上传文件
    connect(mw_p,&menuwidget::uploadgroupFile,this,&Widget::on_uploadgroupFile);

    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress("127.0.0.1"),8888);
    connect(socket,&QTcpSocket::readyRead,this,&Widget::onReadyRead);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::onReadyRead()//读取数据包
{
    while(socket->bytesAvailable()>0)
    {
        messageProtocal pack;
        pack.recvMsg(socket);
        resultHandler(pack);
    }
}

void Widget::on_login(QString name, QString pswd)//发送登录数据
{
    //封装数据包
    messageProtocal pack;
    pack.setType("user login");
    pack.addValue("name",name);
    pack.addValue("pswd",pswd);

    //
    pack.sendMsg(socket);
    //qDebug()<<pack.getStringValue("name")<<" "<<pack.getStringValue("pswd");
}

void Widget::on_regist(QString name, QString pswd)//发送注册数据
{
    //封装数据包
    messageProtocal pack;
    pack.setType("user regist");
    pack.addValue("name",name);
    pack.addValue("pswd",pswd);

    //
    pack.sendMsg(socket);
}

void Widget::showrw_p()
{
    rw_p->show();
}

void Widget::on_addFriend(QStringList list)
{
    //封装数据包
    messageProtocal pack;
    pack.setType("add friend");
    pack.addValue("name",mw_p->getLoginUserName());
    pack.addValue("friends",list);

    pack.sendMsg(socket);
}

void Widget::on_sendPrivateMsg(QString sender, QString recver, QString msg)
{
    //封装数据包
    messageProtocal pack;
    pack.setType("private msg");
    pack.addValue("sender",sender);
    pack.addValue("recver",recver);
    pack.addValue("message",msg);
    //
    pack.sendMsg(socket);
}

//上传文件
void Widget::on_uploadPrivateFile(QString sender, QString recver, QString filepath, QString filename)
{
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

    //封装数据包
    messageProtocal pack;
    pack.setType("private file");
    pack.addValue("sender",sender);
    pack.addValue("recver",recver);
    pack.addValue("filename",filename);
    pack.addValue("data",data);
    //
    //qDebug()<<filename;
    pack.sendMsg(socket);
}

void Widget::on_sendgroupMsg(QString sender, QString groupname, QString msg)
{
    //封装数据包
    messageProtocal pack;
    pack.setType("group msg");
    pack.addValue("sender",sender);
    pack.addValue("groupname",groupname);
    pack.addValue("message",msg);
    //
    pack.sendMsg(socket);
}

void Widget::on_uploadgroupFile(QString sender, QString groupname, QString filepath, QString filename)
{
    //qDebug()<<filename;
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

    //封装数据包
    messageProtocal pack;
    pack.setType("group file");
    pack.addValue("sender",sender);
    pack.addValue("groupname",groupname);
    pack.addValue("filename",filename);
    pack.addValue("data",data);
    //

    pack.sendMsg(socket);
}

void Widget::on_downloadFile(QString sender, QString recver, QString filename)
{
    //封装数据包
    messageProtocal pack;
    pack.setType("download file");
    pack.addValue("sender",sender);
    pack.addValue("recver",recver);
    pack.addValue("filename",filename);
    //
    pack.sendMsg(socket);
}

void Widget::on_creategroup(QString groupName, QStringList members)//创建群组私聊包
{
    //封装数据包
    messageProtocal pack;
    pack.setType("create group");
    pack.addValue("name",mw_p->getLoginUserName());
    pack.addValue("groupname",groupName);
    members.append(mw_p->getLoginUserName());//--------------群成员增加自己
    pack.addValue("members",members);
    //
    pack.sendMsg(socket);
}

void Widget::on_createMeeting(QString host, QString meetingName, QStringList members)
{
    //封装数据包
    // qDebug()<<meetingName;
    messageProtocal pack;
    pack.setType("create meeting");
    pack.addValue("host",host);
    pack.addValue("meetingname",meetingName);
    pack.addValue("members",members);
    //
    pack.sendMsg(socket);
}

void Widget::on_joinMeeting(QString host)
{
    //封装数据包
    messageProtocal pack;
    pack.setType("join meeting");
    pack.addValue("host",host);
    pack.addValue("username",mw_p->getLoginUserName());
    qDebug()<<host;
    //
    pack.sendMsg(socket);
}

void Widget::on_needmembers(QString groupName)//获取小组成员
{
    //封装数据包
    messageProtocal pack;
    pack.setType("get groupmembers");
    pack.addValue("name",mw_p->getLoginUserName());
    pack.addValue("groupname",groupName);
    //
    pack.sendMsg(socket);
}

void Widget::resultHandler(messageProtocal &pack)
{
    QString type = pack.type();
    if(type == "user login")
    {
        QStringList friends = pack.getListValue("friend");
        QStringList users = pack.getListValue("userList");
        QStringList files = pack.getListValue("filelist");
        QStringList grouplist = pack.getListValue("grouplist");
        if(pack.getIntValue("result")==1)
        {
            qDebug()<<"登录成功";
            lw_p->hide();
            mw_p->setLoginUserName(pack.getStringValue("name"));//设置登录名称
            mw_p->setFriendList(friends);
            //qDebug()<<users;
            mw_p->setOtherUser(users);
            mw_p->setFiles(files);
            mw_p->setgroups(grouplist);

            mw_p->show();
        }else if(pack.getIntValue("result")==2)
        {
            QMessageBox::warning(this,"登录","用户已在线");
        }
        else
        {
            QMessageBox::warning(this,"登录","登录失败");
        }
    }
    else if(type =="user regist")
    {
        if(pack.getIntValue("result")==1)
        {
            QMessageBox::warning(this,"注册","注册成功");
            rw_p->hide();
            lw_p->show();
        }
        else if(pack.getIntValue("result")==0)
        {
            QMessageBox::warning(this,"注册","该账号已存在");
        }
        else {
            QMessageBox::warning(this,"注册","注册失败");
        }
    }
    else if (type == "private msg")//收到私聊
    {
        //qDebug()<<111;
        QString sender = pack.getStringValue("sender");
        QString msg = pack.getStringValue("message");
        mw_p->setPrivateMsg(sender,msg);
    }
    else if(type == "group msg")
    {
        QString sender = pack.getStringValue("sender");
        QString msg = pack.getStringValue("message");
        QString groupname = pack.getStringValue("groupname");
        mw_p->setgroupMsg(sender,groupname,msg);
    }
    else if (type == "private file")//收到私人文件发送成功的消息，显示在侧边栏
    {
        QString sender = pack.getStringValue("sender");
        QString recver = pack.getStringValue("recver");
        QString filename = pack.getStringValue("filename");
        mw_p->setFileInfo(sender,recver,filename);
    }
    else if(type == "group file")
    {
        QString sender = pack.getStringValue("sender");
        QString groupname = pack.getStringValue("groupname");
        QString filename = pack.getStringValue("filename");
        mw_p->setFileInfo(sender,groupname,filename);
    }
    else if(type == "download file")//下在文件
    {
        QString filepath = "./"+pack.getStringValue("filename");
        QString data = pack.getStringValue("data");
        filepath = QFileDialog::getSaveFileName(this,"选择下载文件位置",filepath);
        QFile file(filepath);
        if(!file.open(QIODevice::WriteOnly))
        {
            return;
        }
        file.write(data.toStdString().data());
        file.close();
    }
    else if(type =="create group")
    {
        QString groupName = pack.getStringValue("groupname");
        QStringList members = pack.getListValue("members");
        mw_p->addgroupname(groupName,members);
    }
    else if(type == "create meeting")
    {
        QString meetingName = pack.getStringValue("meetingname");
        QString host = pack.getStringValue("host");
        mw_p->addMeeting(meetingName,host);
    }
    else if(type == "member in")
    {
        QString member = pack.getStringValue("member");
        meetingRoomWidget::getInstance()->updateMemberStat(member,"已入会");
    }
    else if(type == "join meeting")
    {
        qDebug()<<"加入会议"<<endl;
        QString host = pack.getStringValue("host");
        QString meetingname = pack.getStringValue("meetingname");
        QStringList in_m = pack.getListValue("in_members");
        QStringList out_m = pack.getListValue("out_members");

        QString ip = pack.getStringValue("ip");
        int textPort = pack.getIntValue("textport");
        int videoPort = pack.getIntValue("videoport");
        int audioPort = pack.getIntValue("audioport");

        //qDebug()<<2222;
        meetingRoomWidget* w = meetingRoomWidget::getInstance();
        w->setHost(host);
        w->setMeetingName(meetingname);
        w->setNetWork(QHostAddress(ip),textPort,videoPort,audioPort);
        w->setMember(in_m,out_m);
        w->show();
    }
    else if(type == "add friend")
    {

        QString name = pack.getStringValue("name");
        if(name == mw_p->getLoginUserName())
        {

            QStringList friends = pack.getListValue("friends");
            qDebug()<<friends;
            mw_p->addnewfriends(friends);
        }
        else
        {
            mw_p->addnewfriends(name);
        }

    }
    else if(type == "get groupmembers")
    {
        QStringList members = pack.getListValue("groupmembers");
        QString groupname = pack.getStringValue("groupname");
        mw_p->setgroupmembers(groupname,members);
    }
}

