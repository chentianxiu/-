#include "meetingroomwidget.h"
#include "ui_meetingroomwidget.h"
#include <QTableWidgetItem>
#include <QDateTime>
#include "videosurface.h"
#include "pack.h"
#include "AudioPack.h"

meetingRoomWidget* meetingRoomWidget::instance = nullptr;

meetingRoomWidget::meetingRoomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::meetingRoomWidget)
{
    ui->setupUi(this);

    QCameraInfo info = QCameraInfo::defaultCamera();//返回默认相机
    camera = new QCamera(info,this);

    VideoSurface* vf = new VideoSurface(this);//生成摄像头捕获格式对象

    camera->setViewfinder(vf); //设置捕获格式
    connect(vf,&VideoSurface::videoChanged,this,&meetingRoomWidget::on_videoChanged);

    QAudioFormat format;
    format.setSampleRate(800);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    audioInput = new QAudioInput(format,this);
    audioOutput = new QAudioOutput(format,this);
    audioSocket = new QUdpSocket(this);
    audioOutputIODevice = audioOutput->start();
    connect(audioSocket,&QUdpSocket::readyRead,this,&meetingRoomWidget::onReadyRead);


}

meetingRoomWidget::~meetingRoomWidget()
{
    delete ui;
}


void meetingRoomWidget::sendFrame(QImage image)
{
    int unitBytes = 2048;
    int byteCount = image.sizeInBytes(); //图片大小
    int width = image.width();
    int height = image.height();
    int bytePerLine = image.bytesPerLine();
    //qDebug()<<"bytesCount:"<<byteCount<<" width&height"<<width<<","<<height<<"bytePerLine:"<<bytePerLine;
    int writeBytes = 0; //已写入大小

    while(true)
    {
        ImagePackage pack;
        memset(&pack,0,sizeof(ImagePackage));
        pack.width = width;
        pack.height = height;
        pack.bytesPerline = bytePerLine;
        if(writeBytes<byteCount)
        {
            memcpy(pack.data,((char*)image.bits())+writeBytes,unitBytes);

            writeBytes += unitBytes;
            if(writeBytes>=byteCount)
            {
                pack.isLastPack = true;
                pack.packTaken = unitBytes-(writeBytes-byteCount); //获取当前包实际的数据大小
            }
            else
            {
                pack.isLastPack = false;
                pack.packTaken = unitBytes; //设置当前包中数据的大小
            }
            qDebug()<<"writeBytes:"<<writeBytes<<"taken"<<pack.packTaken<<"count"<<byteCount;
            videoSocket->writeDatagram((char*)&pack,sizeof(ImagePackage),ip,videoPort);
        }
        else
        {
            break;
        }
    }
}


void meetingRoomWidget::setNetWork(QHostAddress ip, int Text, int video, int audio)//设置udp网络
{
    this->ip = ip;
    msgSocket = new QUdpSocket(this);
    videoSocket = new QUdpSocket(this);
    videoSocket_R = new QUdpSocket(this);


    videoPort = video;
    audioPort = audio;
    videoSocket->setSocketOption(QAbstractSocket::SendBufferSizeSocketOption,300*1024);
    videoSocket_R->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,300*1024);

    msgSocket->bind(QHostAddress::AnyIPv4,Text,QAbstractSocket::ReuseAddressHint);
    videoSocket->bind(QHostAddress::AnyIPv4,video,QAbstractSocket::ReuseAddressHint);
    videoSocket_R->bind(QHostAddress::AnyIPv4,video,QAbstractSocket::ReuseAddressHint);
    audioSocket->bind(QHostAddress::AnyIPv4,audio,QAbstractSocket::ReuseAddressHint);


    connect(msgSocket,&QUdpSocket::readyRead,this,&meetingRoomWidget::on_TextmsgReadyRead);

    msgSocket->joinMulticastGroup(ip);
    videoSocket_R->joinMulticastGroup(ip);
    audioSocket->joinMulticastGroup(ip);

    vr_thread = new videoRecver(this);//设置图像接收对象
    vr_thread->setSocket(videoSocket_R);//设置接收套接字
    vr_thread->setLabel(ui->label);
    vr_thread->start();
}

meetingRoomWidget *meetingRoomWidget::getInstance()//创建实列
{
    if(instance == nullptr)
    {
        instance = new meetingRoomWidget;
    }
    return instance;
}

void meetingRoomWidget::removeInstance()
{
    if(instance!=nullptr)
    {
        delete  instance;
    }
}

QString meetingRoomWidget::getHost() const
{
    return host;
}

void meetingRoomWidget::setHost(const QString &value)
{
    host = value;
    ui->host_LB->setText(host);
}

QString meetingRoomWidget::getMeetingName() const
{
    return meetingName;
}

void meetingRoomWidget::setMeetingName(const QString &value)
{
    meetingName = value;
    ui->meetingName_LB->setText(meetingName);
}

void meetingRoomWidget::updateMemberStat(QString member, QString stat)
{
    QTableWidgetItem* item = ui->memberList_TW->findItems(member,Qt::MatchExactly).first();
    int row = ui->memberList_TW->row(item);
    ui->memberList_TW->setItem(row,1,new QTableWidgetItem(stat));

}

void meetingRoomWidget::setMember(QStringList in, QStringList out)
{
    for(auto it : in)
    {
        ui->memberList_TW->insertRow(0);
        ui->memberList_TW->setItem(0,0,new QTableWidgetItem(it));
        ui->memberList_TW->setItem(0,1,new QTableWidgetItem("已入会"));
    }

    for(auto it : out)
    {
        ui->memberList_TW->insertRow(0);
        ui->memberList_TW->setItem(0,0,new QTableWidgetItem(it));
        ui->memberList_TW->setItem(0,1,new QTableWidgetItem("未入会"));
    }
}


void meetingRoomWidget::on_sendMsg_PB_clicked()
{
    QString msg = ui->msgInput_LE->text();
    if(msg.isEmpty())
    {
        return;
    }
    msgSocket->writeDatagram(msg.toUtf8(),ip,msgSocket->localPort());//使用本地端口或者存起来的端口
    //ui->msgOutput_TB->append(QString("[%1] %2").arg(QDateTime::currentDateTime().toString(), msg));

}


void meetingRoomWidget::on_camera_cb_stateChanged(int arg1)
{
    if(arg1)
    {
        camera->start();
        vr_thread->terminate();
        vr_thread->deleteLater();
        videoSocket_R->deleteLater();
    }
    else
    {
        camera->stop();
        vr_thread = new videoRecver(this);
        vr_thread->setSocket(videoSocket_R);
        vr_thread->setLabel(ui->label);
        vr_thread->start();
    }
}

void meetingRoomWidget::on_TextmsgReadyRead()
{
    int len = msgSocket->pendingDatagramSize();
    //    char data[len];
    //    memset(data,0,len);
    //    msgSocket->readDatagram(data,len);
    //    ui->msgOutput_TB->append(data);
    QByteArray data(len, 0); // 创建一个长度为len的QByteArray
    msgSocket->readDatagram(data.data(), len); // 读取数据到QByteArray中
    // 设置文本左对齐
    ui->msgOutput_TB->setAlignment(Qt::AlignLeft);
    ui->msgOutput_TB->append(QString::fromUtf8(data)); // 转换为QString并显示
}


void meetingRoomWidget::on_videoChanged(QVideoFrame curframe)
{
    static int i=0;
    QVideoFrame frame(curframe);
    frame.map(QAbstractVideoBuffer::ReadOnly);

    //通过当前帧的对象构建QImage图片对象
    QImage image(frame.bits(),
                 frame.width(),frame.height(),
                 QVideoFrame::imageFormatFromPixelFormat(frame.pixelFormat()));
    //旋转图像180
    QMatrix matrix;
    matrix.rotate(180);
    image = image.transformed(matrix);
    image = image.scaled(300,300,Qt::KeepAspectRatio,Qt::SmoothTransformation); //300*300像素

    QPixmap pixmap = QPixmap::fromImage(image); //从QImage图片对象转成QPixmap格式图片对象
    pixmap = pixmap.scaled(ui->label->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
    qDebug()<<image.sizeInBytes()<<pixmap.size();
    if(i%4!=0)
    {
        i++;
        return;
    }
    sendFrame(image);
    i++;
}

void meetingRoomWidget::on_setPixmap(QImage image)
{
    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap = pixmap.scaled(ui->label->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
}

void meetingRoomWidget::on_mic_cb_stateChanged(int arg1)
{
    if(arg1)
    {
        qDebug()<< "麦克风开启";
        audioInputIODevice = audioInput->start();
        //audioOutputIODevice = audioOutput->start(); // 启动音频输出设备
        connect(audioInputIODevice,&QIODevice::readyRead,this,&meetingRoomWidget::captureDataFromDevice);

    }
    else
    {
        audioInput->stop();
        //audioOutput->stop(); // 停止音频输出设备
    }
}

void meetingRoomWidget::captureDataFromDevice()
{
    AudioPackage pack = {};
    memset(&pack,0,sizeof(AudioPackage));
    pack.dataLen = audioInputIODevice->read(pack.data,1024); //读取音频数据

    // 调试信息
        qDebug() << "Captured audio data, length:" << pack.dataLen;

//    audioOutputIODevice->write(pack.data,pack.dataLen); //输出数据
    audioSocket->writeDatagram((char*)&pack,sizeof(AudioPackage),ip,audioPort);
}

void meetingRoomWidget::onReadyRead()
{
    AudioPackage pack = {};
    memset(&pack,0,sizeof(AudioPackage));

    audioSocket->readDatagram((char*)&pack,sizeof(AudioPackage));

    // 调试信息
        qDebug() << "Received audio data, length:" << pack.dataLen;

    audioOutputIODevice->write(pack.data,pack.dataLen);
}
