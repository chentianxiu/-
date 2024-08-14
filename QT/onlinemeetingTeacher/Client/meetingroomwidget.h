#ifndef MEETINGROOMWIDGET_H
#define MEETINGROOMWIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QCamera>
#include <QCameraInfo>
#include "videorecver.h"
namespace Ui {
class meetingRoomWidget;
}

class meetingRoomWidget : public QWidget
{
    Q_OBJECT

public:


    void setNetWork(QHostAddress ip,int Text,int video,int audio);

    static meetingRoomWidget *getInstance();
    static void removeInstance();

    QString getHost() const;
    void setHost(const QString &value);

    QString getMeetingName() const;
    void setMeetingName(const QString &value);

    void updateMemberStat(QString member,QString stat);

    void setMember(QStringList in,QStringList out);

private slots:
    void on_sendMsg_PB_clicked();
    void on_TextmsgReadyRead();
    void on_videoChanged(QVideoFrame curframe);

    void on_camera_cb_stateChanged(int arg1);
    void on_setPixmap(QImage image);

private:
    static meetingRoomWidget* instance;
    explicit meetingRoomWidget(QWidget *parent = nullptr);
    ~meetingRoomWidget();
    void sendFrame(QImage image);

    Ui::meetingRoomWidget *ui;
    QString host;
    QString meetingName;

    QHostAddress ip;
    QUdpSocket *msgSocket;
    QUdpSocket *videoSocket;
    QUdpSocket *videoSocket_R;
    QUdpSocket *audioSocket;
    int  videoPort;

    videoRecver* vr_thread;
    QCamera *camera;
};

#endif // MEETINGROOMWIDGET_H
