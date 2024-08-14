#include "menuwidget.h"
#include "ui_menuwidget.h"

menuwidget::menuwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menuwidget),afd(this),cgd(this),cmd_p(this)
{
    ui->setupUi(this);
    this->hide();

    frameLayout = new QVBoxLayout(this);
    ui->frame->setLayout(frameLayout);

    //将添加的朋友信息传到这个界面，然后在传到widget界面
    connect(&afd,& addfriendDialog::addfriends,this,&menuwidget::on_addFriends);

    //添加群组
    connect(&cgd,& CreateGroupDialog::creategroup,this,&menuwidget::on_creategroup);

    //增加会议
    connect(&cmd_p,&createmeetingDialog::accepted,this,&menuwidget::on_createMeetingAccepted);
}

menuwidget::~menuwidget()
{
    delete ui;
}

void menuwidget::setFriendList(const QStringList friends)//登录时初始化好友列表
{
    for(auto it:friends)
    {
        friendList.insert(it,nullptr);
        ui->friendList_LW->addItem(it);
    }
}

void menuwidget::setLoginUserName(const QString &value)
{
    loginUserName = value;
}

void menuwidget::setOtherUser(const QStringList &value)//用户列表，在用户登录成功从数据包中获得
{
    //qDebug()<<value;
    otherUser = value;
    startgroupselectlist = value;
}

void menuwidget::setgroups(const QStringList grouplist)//在用户登录成功从数据包中获得,设置初始群组
{
    for(auto it:grouplist)
    {
        groupchatList.insert(it,nullptr);
        ui->groupList_LW->addItem(it);
    }
}

void menuwidget::on_addFriends(QStringList friends)//遍历好友列表，然后从其他人员列表中移除好友成员，从而更新其他人员列表
{
    emit addFriends(friends);
    for(auto it:friends)
    {
        otherUser.removeAll(it);
    }
}

void menuwidget::on_creategroup(QString groupName, QStringList members)
{
    emit creategroup(groupName,members);
}

QString menuwidget::getLoginUserName() const
{
    return loginUserName;
}

void menuwidget::setPrivateMsg(QString friendName, QString msg)//接收消息
{
    //qDebug()<<friendName<<msg;
    if(friendList[friendName]==nullptr)
    {
        //qDebug()<<friendName<<msg;
        privatechatwidget* newWidget = new privatechatwidget(friendName,this);//有私聊，创建窗口
        frameLayout->addWidget(newWidget);
        connect(newWidget,&privatechatwidget::sendMsg,this,&menuwidget::onSendPrivateMsg);//发送到服务器
        connect(newWidget,&privatechatwidget::uploadFile,this,&menuwidget::onUploadPrivateFile);//上传文件

        friendList[friendName] = newWidget;
    }
    friendList[friendName]->addNewMsg(msg);


    if (currentWidget!=nullptr) {
        currentWidget->hide();
    }
    currentWidget = friendList[friendName];
    currentWidget->show();
}

void menuwidget::setgroupMsg(QString sender,QString groupname, QString msg)//接收群聊消息
{
    if(groupchatList[groupname]==nullptr)
    {
        groupchatwidget* newWidget = new groupchatwidget(groupname,members,this);//有私聊，创建窗口
        frameLayout->addWidget(newWidget);
        connect(newWidget,&groupchatwidget::sendMsg,this,&menuwidget::onSendgroupMsg);//发送到服务器
        connect(newWidget,&groupchatwidget::uploadFile,this,&menuwidget::onUploadgroupFile);

        groupchatList[groupname] = newWidget;
        emit needmembers(groupname);//每次点击的时候向服务器请求群成员
    }
    groupchatList[groupname]->addNewMsg(sender,msg);

    if (currentWidget!=nullptr) {//确保每次聊天的窗口都只有一个
        currentWidget->hide();
    }
    currentWidget = groupchatList[groupname];
    currentWidget->show();
    groupchatList[groupname]->show();
}

void menuwidget::setFileInfo(QString sender, QString recver, QString filename)
{
    qDebug()<<filename;
    ui->fileList_TW->insertRow(ui->fileList_TW->rowCount());
    int row = ui->fileList_TW->rowCount() - 1;
    ui->fileList_TW->setItem(row,0,new QTableWidgetItem(sender));
    ui->fileList_TW->setItem(row,1,new QTableWidgetItem(recver));
    ui->fileList_TW->setItem(row,2,new QTableWidgetItem(filename));
}

void menuwidget::setFiles(QStringList files)
{
    for(auto it:files)
    {
        QStringList list = it.split("\n");
        setFileInfo(list[0],list[1],list[2]);
    }
}

void menuwidget::addMeeting(QString meetingName, QString host)//设置会议列表
{
    ui->meetingList_LW->addItem(host+" "+meetingName);
    if(loginUserName == host)
    {
        emit joinMeeting(host);
    }
}

void menuwidget::addgroupname(QString groupname, QStringList members)
{
    groupchatList.insert(groupname,nullptr);
    ui->groupList_LW->addItem(groupname);
}

void menuwidget::addnewfriends(QString name)
{
    friendList.insert(name,nullptr);
    ui->friendList_LW->addItem(name);
    otherUser.append(name);
}

void menuwidget::addnewfriends(QStringList friends)
{
    for(auto it:friends)
    {
        friendList.insert(it,nullptr);
        ui->friendList_LW->addItem(it);
        otherUser.append(it);
    }

}

void menuwidget::setgroupmembers(QString groupname, QStringList members)//设置群的成员列表
{
    if(groupchatList.contains(groupname))
    {
        groupchatList[groupname]->setgroupmemberslist(members);
    }
}

void menuwidget::on_addFriend_PB_clicked()//点击添加好友按钮，将其他人员列表传入afd中
{
    QStringList templist;
    for (int i = 0;i<ui->friendList_LW->count();++i) {
        QListWidgetItem *item = ui->friendList_LW->item(i);
        templist.append(item->text());
    }
    for(auto it:templist)
    {
        otherUser.removeAll(it);
    }

    //上面把已经有的好友去掉了
    afd.setSelectList(otherUser);
    afd.show();
}

void menuwidget::on_friendList_LW_itemClicked(QListWidgetItem *item)//创建窗口
{
    QString friendName = item->text();
    if(friendList[friendName] == nullptr)
    {
        privatechatwidget* newWidget = new privatechatwidget(friendName,this);
        frameLayout->addWidget(newWidget);
        connect(newWidget,&privatechatwidget::sendMsg,this,&menuwidget::onSendPrivateMsg);//私聊
        connect(newWidget,&privatechatwidget::uploadFile,this,&menuwidget::onUploadPrivateFile);//上传文件

        friendList[friendName] = newWidget;
    }

    if (currentWidget!=nullptr) {
        currentWidget->hide();
    }
    currentWidget = friendList[friendName];
    currentWidget->show();
}

void menuwidget::onSendPrivateMsg(QString recver, QString msg)
{
    emit sendPrivateMsg(loginUserName,recver,msg);
}

void menuwidget::onSendgroupMsg(QString groupname, QString msg)
{
    emit sendgroupMsg(loginUserName,groupname,msg);
}

void menuwidget::onUploadPrivateFile(QString recver, QString filePath, QString filename)
{
    emit uploadPrivateFile(loginUserName,recver,filePath,filename);
}

void menuwidget::on_fileList_TW_cellDoubleClicked(int row, int )//双击下载
{
    QString sender = ui->fileList_TW->item(row,0)->text();
    QString recver = ui->fileList_TW->item(row,1)->text();
    QString filename = ui->fileList_TW->item(row,2)->text();

    emit downloadFile(sender,recver,filename);
}

void menuwidget::on_creategroup_PB_clicked()//点击创建群组
{
    //qDebug()<<startgroupselectlist;
    cgd.setSelectList(startgroupselectlist);
    cgd.show();
}


void menuwidget::on_createMeeting_PB_clicked()//创建会议
{
    cmd_p.prepareMeetingName(loginUserName+"的会议");
    cmd_p.setSelectList(friendList.keys());
    cmd_p.show();
}

void menuwidget::on_createMeetingAccepted()
{
    emit createMeeting(loginUserName,cmd_p.getMeetingName(),cmd_p.getmemberList());
}

void menuwidget::on_groupList_LW_itemClicked(QListWidgetItem *item)//群聊
{
    QString groupname = item->text();
    emit needmembers(groupname);//每次点击的时候向服务器请求群成员
    if(groupchatList[groupname] == nullptr)
    {
        groupchatwidget* newWidget = new groupchatwidget(groupname,members,this);
        frameLayout->addWidget(newWidget);

        connect(newWidget,&groupchatwidget::sendMsg,this,&menuwidget::onSendgroupMsg);
        connect(newWidget,&groupchatwidget::uploadFile,this,&menuwidget::onUploadgroupFile);

        groupchatList[groupname] = newWidget;
    }
    if (currentWidget!=nullptr) {
        currentWidget->hide();
    }
    currentWidget = groupchatList[groupname];
    currentWidget->show();
    groupchatList[groupname]->show();
}

//void menuwidget::onSendgroupmsg(QString groupname, QString msg)
//{
//    emit sendgroupMsg(loginUserName,groupname,msg);
//}

void menuwidget::onUploadgroupFile(QString groupname, QString filePath, QString filename)
{

    emit uploadgroupFile(loginUserName,groupname,filePath,filename);
}

void menuwidget::on_meetingList_LW_itemDoubleClicked(QListWidgetItem *item)
{
    QString text = item->text();
    QStringList list = text.split(" ");
    emit joinMeeting(list.first());
}
