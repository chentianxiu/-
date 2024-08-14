#include "menuwidget.h"
#include "ui_menuwidget.h"
#include "addfriedndialog.h"
#include "meetingroomwidget.h"
#include <QTableWidgetItem>
#include <QDebug>

menuWidget::menuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menuWidget),afd(this)
{
    ui->setupUi(this);
    this->hide();

    frameLayout = new QVBoxLayout(this);
    ui->frame->setLayout(frameLayout);

    ui->meetingList_LW->hide();

    cmd_p = new createMeetingDialog(this);
    connect(cmd_p,&createMeetingDialog::accepted,this,&menuWidget::on_createMeetingAccepted);

    connect(&afd,&addFriednDialog::addfriends,this,&menuWidget::on_addFriends);


}

menuWidget::~menuWidget()
{
    delete ui;
}

void menuWidget::on_addFriend_PB_clicked()
{
    afd.setSelectList(otherUser);
    afd.show();
}

void menuWidget::on_addFriends(QStringList friends)
{
    emit addFriends(friends);
    for(auto it:friends)
    {
        otherUser.removeAll(it);
    }
}

void menuWidget::setOtherUser(const QStringList &value)
{
    otherUser = value;
}

void menuWidget::setPrivateMsg(QString friendName, QString msg)
{
    if(friendList[friendName]==nullptr)
    {
        privateChatWidget* newWidget = new privateChatWidget(friendName,this);
        frameLayout->addWidget(newWidget);
        connect(newWidget,&privateChatWidget::sendMsg,this,&menuWidget::onSendPrivateMsg);
        connect(newWidget,&privateChatWidget::uploadFile,this,&menuWidget::onUploadPrivateFile);

        friendList[friendName] = newWidget;
    }
    friendList[friendName]->addNewMsg(msg);
}

void menuWidget::setFileInfo(QString sender, QString recver, QString filename)
{
    ui->fileList_TW->insertRow(ui->fileList_TW->rowCount());
    int row = ui->fileList_TW->rowCount() - 1;
    ui->fileList_TW->setItem(row,0,new QTableWidgetItem(sender));
    ui->fileList_TW->setItem(row,1,new QTableWidgetItem(recver));
    ui->fileList_TW->setItem(row,2,new QTableWidgetItem(filename));
}

void menuWidget::setFiles(QStringList files)
{
    for(auto it:files)
    {
        QStringList list = it.split("\n");
        setFileInfo(list[0],list[1],list[2]);
    }
}

void menuWidget::addMeeting(QString meetingName, QString host)
{
    ui->meetingList_LW->addItem(host+" "+meetingName);
    if(loginUserName == host)
    {
        emit joinMeeting(host);
    }
}

void menuWidget::setLoginUserName(const QString &value)
{
    loginUserName = value;
}

void menuWidget::addFriendList(const QStringList friends)
{
    for(auto it:friends)
    {
        friendList.insert(it,nullptr);
        ui->friendList_LW->addItem(it);
    }
}

QString menuWidget::getLoginUserName() const
{
    return loginUserName;
}

void menuWidget::on_friendList_LW_itemClicked(QListWidgetItem *item)
{
    QString friendName = item->text();
    if(friendList[friendName] == nullptr)
    {
        privateChatWidget* newWidget = new privateChatWidget(friendName,this);
        frameLayout->addWidget(newWidget);

        connect(newWidget,&privateChatWidget::sendMsg,this,&menuWidget::onSendPrivateMsg);
        connect(newWidget,&privateChatWidget::uploadFile,this,&menuWidget::onUploadPrivateFile);

        friendList[friendName] = newWidget;
    }
    friendList[friendName]->show();
}

void menuWidget::onSendPrivateMsg(QString recver, QString msg)
{
    emit sendPrivateMsg(loginUserName,recver,msg);
}

void menuWidget::onUploadPrivateFile(QString recver, QString filePath, QString filename)
{
    emit uploadPrivateFile(loginUserName,recver,filePath,filename);
}

void menuWidget::on_fileList_TW_cellDoubleClicked(int row, int)
{
    qDebug()<<111;
    QString sender = ui->fileList_TW->item(row,0)->text();
    QString recver = ui->fileList_TW->item(row,1)->text();
    QString filename = ui->fileList_TW->item(row,2)->text();

    emit downloadFile(sender,recver,filename);

}

void menuWidget::on_meetinglist_PB_clicked()
{
    if(ui->meetingList_LW->isHidden())
    {
        ui->meetingList_LW->show();
    }
    else
    {
        ui->meetingList_LW->hide();
    }
}

void menuWidget::on_createMeeting_PB_clicked()
{
    cmd_p->prepareMeetingName(loginUserName+"的会议");
    cmd_p->setSelectList(friendList.keys());
    cmd_p->show();
}

void menuWidget::on_createMeetingAccepted()
{
    emit createMeeting(loginUserName,cmd_p->getMeetingName(),cmd_p->getmemberList());
}

void menuWidget::on_meetingList_LW_itemDoubleClicked(QListWidgetItem *item)
{
    QString text = item->text();
    QStringList list = text.split(" ");
    emit joinMeeting(list.first());
}
