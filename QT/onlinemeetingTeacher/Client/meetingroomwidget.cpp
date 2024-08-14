#include "meetingroomwidget.h"
#include "ui_meetingroomwidget.h"
#include "videosurface.h"
#include "pack.h"
#include <QTableWidgetItem>

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

QString meetingRoomWidget::getHost() const
{
    return host;
}

void meetingRoomWidget::setHost(const QString &value)
{
    host = value;
    ui->host_LB->setText(host);
}

void meetingRoomWidget::setNetWork(QHostAddress ip, int Text, int video, int audio)
{
    this->ip = ip;
    msgSocket = new QUdpSocket(this);
    videoSocket = new QUdpSocket(this);
    videoSocket_R = new QUdpSocket(this);
    audioSocket = new QUdpSocket(this);

    videoPort = video;
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

    vr_thread = new videoRecver(this);
    vr_thread->setSocket(videoSocket_R);
    vr_thread->setLabel(ui->label);
    vr_thread->start();
}

void meetingRoomWidget::on_sendMsg_PB_clicked()
{
    QString msg = ui->msgInput_LE->text();
    if(msg.isEmpty())
    {
        return;
    }
    msgSocket->writeDatagram(msg.toUtf8(),ip,msgSocket->peerPort());
}

void meetingRoomWidget::on_TextmsgReadyRead()
{
    int len = msgSocket->pendingDatagramSize();
    char data[len];
    memset(data,0,len);
    msgSocket->readDatagram(data,len);
    ui->msgOutput_TB->append(data);
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

meetingRoomWidget *meetingRoomWidget::getInstance()
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

void meetingRoomWidget::on_setPixmap(QImage image)
{
    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap = pixmap.scaled(ui->label->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);

}
