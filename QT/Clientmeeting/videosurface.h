#ifndef VIDEOSURFACE_H
#define VIDEOSURFACE_H

#include <QObject>
#include <QAbstractVideoSurface>

class VideoSurface:public QAbstractVideoSurface
{
    Q_OBJECT
public:
    VideoSurface(QObject* parent=0);
    virtual QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const override;
    bool present(const QVideoFrame &frame) override;
signals:
    void videoChanged(QVideoFrame);
};

#endif // VIDEOSURFACE_H
