#include "videorecver.h"
#include <QDataStream>
#include <QDebug>
#include <QImage>
#include "pack.h"

videoRecver::videoRecver(QObject *parent):QThread(parent)
{

}

void videoRecver::run()
{
    QByteArray *imageBytes = new QByteArray(4000000,0);
    QDataStream *dataStream = new QDataStream(imageBytes,QIODevice::ReadWrite);
    while(true)
    {
        if(socket->hasPendingDatagrams())
        {
            int i=0;
            i++;
            ImagePackage pack = {};
            memset(&pack,0,sizeof(ImagePackage));
            socket->readDatagram((char*)&pack,sizeof(ImagePackage));

            qDebug()<<i<<pack.packTaken<<pack.isLastPack;

//            if(pack.packTaken<0)
//            {
//                if(pack.isLastPack)
//                {
//                    dataStream->device()->seek(0);
//                }
//                continue;
//            }
            if(true == pack.isLastPack)
            {
                qDebug()<<1;
                dataStream->writeRawData(pack.data,pack.packTaken);
                QImage image = QImage((uchar*)imageBytes->data(),
                                      pack.width,
                                      pack.height,
                                      pack.bytesPerline,
                                      QImage::Format_RGB32);
                 qDebug()<<2;
//                emit videoChanged(image);
                 QPixmap pixmap = QPixmap::fromImage(image);
                 pixmap = pixmap.scaled(label->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
                 label->setPixmap(pixmap);
                 qDebug()<<4;
                imageBytes->clear();
                dataStream->device()->seek(0);
            }
            else
            {
                dataStream->writeRawData(pack.data,pack.packTaken);
            }
        }
    }
}

void videoRecver::setLabel(QLabel *value)
{
    label = value;
}

void videoRecver::setSocket(QUdpSocket *value)
{
    socket = value;
    socket->setParent(nullptr);
    socket->moveToThread(this);
}
