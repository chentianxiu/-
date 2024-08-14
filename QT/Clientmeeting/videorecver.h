#ifndef VIDEORECVER_H
#define VIDEORECVER_H

#include <QObject>
#include <QThread>
#include <QObject>
#include <QUdpSocket>
#include <QImage>
#include <QLabel>

class videoRecver : public QThread
{
    Q_OBJECT
public:
    videoRecver(QObject* parent = nullptr);
    void setSocket(QUdpSocket *value);
    void setLabel(QLabel *value);

signals:
    void videoChanged(QImage image);
protected:
    virtual void run() override;
private:
    QUdpSocket * socket;
    QLabel* label;

};

#endif // VIDEORECVER_H
