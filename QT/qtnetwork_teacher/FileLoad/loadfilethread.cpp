#include "loadfilethread.h"
#include <QTextStream>

loadFileThread::loadFileThread(QString filePath,QObject *parent):QThread(parent),file(filePath)
{

}

void loadFileThread::run()
{
    file.open(QIODevice::ReadOnly); //打开文件
    QTextStream streamer(&file); //文件读取流对象

    //循环读取
    while(!streamer.atEnd())
    {
        QString text = streamer.read(1024);
        emit SndMsg(text);
//        usleep(50000);
    }

}
