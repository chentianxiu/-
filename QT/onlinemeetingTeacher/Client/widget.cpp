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

    lw_p = new LoginWidget(this);
    mainLayout->addWidget(lw_p);
    connect(lw_p,&LoginWidget::userLogin,this,&Widget::on_login);

    mw_p = new menuWidget(this);
    mainLayout->addWidget(mw_p);
    connect(mw_p,&menuWidget::addFriends,this,&Widget::on_addFriend);
    connect(mw_p,&menuWidget::sendPrivateMsg,this,&Widget::on_sendPrivateMsg);
    connect(mw_p,&menuWidget::uploadPrivateFile,this,&Widget::on_uploadPrivateFile);
    connect(mw_p,&menuWidget::downloadFile,this,&Widget::on_downloadFile);
    connect(mw_p,&menuWidget::createMeeting,this,&Widget::on_createMeeting);
    connect(mw_p,&menuWidget::joinMeeting,this,&Widget::on_joinMeeting);

    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress("127.0.0.1"),8888);
    connect(socket,&QTcpSocket::readyRead,this,&Widget::onReadyRead);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onReadyRead()
{
    while(socket->bytesAvailable()>0)
    {
        messageProtocal pack;
        pack.recvMsg(socket);
        resultHandler(pack);
    }
}

void Widget::on_login(QString name, QString pswd)
{
    //封装数据包
    messageProtocal pack;
    pack.setType("user login");
    pack.addValue("name",name);
    pack.addValue("pswd",pswd);

    //
    pack.sendMsg(socket);
}

void Widget::on_addFriend(QStringList list)
{
    //封装数据包
    messageProtocal pack;
    pack.setType("add friend");
    pack.addValue("name",mw_p->getLoginUserName());
    pack.addValue("friends",list);

    //
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

void Widget::on_createMeeting(QString host, QString meetingName, QStringList members)
{
    //封装数据包
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

void Widget::resultHandler(messageProtocal &pack)
{
    QString type = pack.type();
    if(type == "user login")
    {
        QStringList friends = pack.getListValue("friend");
        QStringList users = pack.getListValue("userList");
        QStringList files = pack.getListValue("filelist");
        if(pack.getIntValue("result")==1)
        {
            qDebug()<<"登录成功";
            lw_p->hide();
            mw_p->setLoginUserName(pack.getStringValue("name"));
            mw_p->addFriendList(friends);
            mw_p->setOtherUser(users);
            mw_p->setFiles(files);

            mw_p->show();
        }
        else
        {
            QMessageBox::warning(this,"登录","登录失败");
        }
    }
    else if(type == "private msg")
    {
        QString sender = pack.getStringValue("sender");
        QString msg = pack.getStringValue("message");
        mw_p->setPrivateMsg(sender,msg);
    }
    else if(type == "private file")
    {
        QString sender = pack.getStringValue("sender");
        QString recver = pack.getStringValue("recver");
        QString filename = pack.getStringValue("filename");
        mw_p->setFileInfo(sender,recver,filename);
    }
    else if(type == "download file")
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

        meetingRoomWidget* w = meetingRoomWidget::getInstance();
        w->setHost(host);
        w->setMeetingName(meetingname);
        w->setNetWork(QHostAddress(ip),textPort,videoPort,audioPort);
        w->setMember(in_m,out_m);
        w->show();
    }
}

