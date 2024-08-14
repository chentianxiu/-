#ifndef LOADFILETHREAD_H
#define LOADFILETHREAD_H

#include <QObject>
#include <QThread>
#include <QFile>

class loadFileThread : public QThread
{
    Q_OBJECT
public:
    loadFileThread(QString filePath, QObject *parent = nullptr);
    QFile file;
protected:
    virtual void run() override;
signals:
    void SndMsg(QString line);
};

#endif // LOADFILETHREAD_H
