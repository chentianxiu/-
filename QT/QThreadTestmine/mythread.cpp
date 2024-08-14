#include "mythread.h"

mythread::mythread(QObject *parent):QThread(parent)
{

}

void mythread::run()
{
    int num = 3;
    while(num>0)
    {
        emit addMsg();
        sleep(1);
        num--;
    }
}
