#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QMap>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include "addfriedndialog.h"
#include "privatechatwidget.h"
#include "createmeetingdialog.h"

namespace Ui {
class menuWidget;
}

class menuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit menuWidget(QWidget *parent = nullptr);
    ~menuWidget();

    QString getLoginUserName() const;

    void setLoginUserName(const QString &value);

    void addFriendList(const QStringList friends);

    void setOtherUser(const QStringList &value);

    void setPrivateMsg(QString friendName,QString msg);

    void setFileInfo(QString sender,QString recver,QString filename);
    void setFiles(QStringList files);
    void addMeeting(QString meetingName, QString host);

signals:
    void addFriends(QStringList friends);
    void sendPrivateMsg(QString sender,QString recver,QString msg);
    void uploadPrivateFile(QString sender,QString recver,QString filePath,QString filename);
    void downloadFile(QString Sender,QString recver,QString filename);
    void createMeeting(QString host,QString meetingName,QStringList members);
    void joinMeeting(QString Host);

private slots:

    void on_addFriend_PB_clicked();
    void on_addFriends(QStringList friends);

    void on_friendList_LW_itemClicked(QListWidgetItem *item);
    void onSendPrivateMsg(QString recver,QString msg);
    void onUploadPrivateFile(QString recver,QString filePath,QString filename);

    void on_fileList_TW_cellDoubleClicked(int row, int column);

    void on_meetinglist_PB_clicked();

    void on_createMeeting_PB_clicked();
    void on_createMeetingAccepted();

    void on_meetingList_LW_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::menuWidget *ui;
    addFriednDialog afd; //添加用户对话框
    QString loginUserName;
    QMap<QString,privateChatWidget*> friendList;
    QStringList otherUser;
    createMeetingDialog* cmd_p;

    QVBoxLayout * frameLayout;
};

#endif // MENUWIDGET_H
