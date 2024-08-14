#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTcpSocket>
#include "loginwidget.h"
#include "messageprotocal.h"
#include "menuwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onReadyRead();
    void on_login(QString name,QString pswd);
    void on_addFriend(QStringList list);
    void on_sendPrivateMsg(QString sender,QString recver,QString msg);
    void on_uploadPrivateFile(QString sender,QString recver,QString filepath,QString filename);
    void on_downloadFile(QString sender,QString recver,QString filename);
    void on_createMeeting(QString host,QString meetingName,QStringList members);
    void on_joinMeeting(QString host);

private:
    Ui::Widget *ui;
    QVBoxLayout * mainLayout;
    LoginWidget* lw_p;
    menuWidget* mw_p;
    QTcpSocket* socket;

    void resultHandler(messageProtocal& pack);
};
#endif // WIDGET_H
