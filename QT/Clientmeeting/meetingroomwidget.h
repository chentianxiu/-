#ifndef MEETINGROOMWIDGET_H
#define MEETINGROOMWIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QCamera>
#include <QCameraInfo>
#include <QAudioInput>
#include <QAudioOutput>
#include <QIODevice>
#include "videorecver.h"

namespace Ui {
class meetingRoomWidget;
}

class meetingRoomWidget : public QWidget
{
    Q_OBJECT

public:
    void setNetWork(QHostAddress ip,int Text,int video,int audio);//初始化试着udp网络

    static meetingRoomWidget *getInstance();//创建实列
    static void removeInstance();//移除实列

    QString getHost() const;//得到网络
    void setHost(const QString &value);//设置网络

    QString getMeetingName() const;
    void setMeetingName(const QString &value);

    void updateMemberStat(QString member,QString stat);//更新用户状态

    void setMember(QStringList in,QStringList out);//进入会议时设置成员列表

private slots:
    void on_sendMsg_PB_clicked();

    void on_camera_cb_stateChanged(int arg1);

    void on_TextmsgReadyRead();
    void on_videoChanged(QVideoFrame curframe);
    void on_setPixmap(QImage image);

    void on_mic_cb_stateChanged(int arg1);

    void captureDataFromDevice(); //获取输入设备的音频数据

    void onReadyRead();//读取音频数据

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
    //QUdpSocket *audioSocket_R;//读取的套接字

    QAudioInput* audioInput;    //音频的输入设备对象
    QAudioOutput* audioOutput;    //音频的输入设备对象
    QIODevice *audioOutputIODevice;
    QIODevice *audioInputIODevice;


    int  videoPort;
    int audioPort;

    videoRecver* vr_thread;
    QCamera *camera;
};

#endif // MEETINGROOMWIDGET_H
