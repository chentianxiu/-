#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    myThread(QObject* parent=nullptr);
protected:
    virtual void run() override;
signals:
    void addMsg();
};

#endif // MYTHREAD_H
