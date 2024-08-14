#include "mythread.h"

myThread::myThread(QObject *parent):QThread(parent)
{

}

void myThread::run()
{
    while(1)
    {
        emit addMsg();
        sleep(1);
    }
}
