#include "videosurface.h"

VideoSurface::VideoSurface(QObject *parent)
    :QAbstractVideoSurface(parent)
{

}

QList<QVideoFrame::PixelFormat> VideoSurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType) const
{
    //返回图像的处理格式
    return QList<QVideoFrame::PixelFormat>()<<QVideoFrame::Format_RGB32;
}

bool VideoSurface::present(const QVideoFrame &frame)
{
    //当前帧捕获
    emit this->videoChanged(frame);
    return true;
}
