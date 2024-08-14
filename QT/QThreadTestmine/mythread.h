#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include<QThread>

class mythread : public QThread
{
    Q_OBJECT;
public:
    mythread(QObject* parent=nullptr);
protected:
    virtual void run() override;
signals:
    void addMsg();
};

#endif // MYTHREAD_H
