#include "dbhelper.h"
#include <QDebug>

dbhelper* dbhelper::instance = nullptr;

dbhelper *dbhelper::getInstance()
{
    if(instance == nullptr)
    {
        instance = new dbhelper;
    }
    return instance;
}

void dbhelper::removeInstance()
{
    if(instance!=nullptr)
    {
        delete instance;
    }
}

bool dbhelper::addSong(QString song,QString Name,QString lrc)//添加歌曲地址到数据库中
{
    QSqlQuery query(db);
    QString str = QString("insert into songlist values('%1','%2','%3');").arg(song).arg(Name).arg(lrc);
    int ret = query.exec(str);
    qDebug()<<ret<<query.lastError();
    return ret;
}

QStringList dbhelper::getSonglist()//获取歌曲的地址
{
    QSqlQuery query(db);
    QString str = QString("select path from songlist;");
    query.exec(str);
    QStringList list;
    while(query.next())
    {
        list.append(query.value(0).toString());//歌曲地址放入list当中
    }
    qDebug()<<list;
    return list;
}

QString dbhelper::getSonglryics(QString path)//获取歌词地址
{
    QSqlQuery query(db);
    QString str = QString("select lrc from songlist where path='%1';").arg(path);
    query.exec(str);
    QString ret;
    if(query.next())
    {
        ret = query.value(0).toString();//lrc的地址
    }
    //qDebug()<<ret;
    return ret;
}

dbhelper::dbhelper()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./data.db");
    if(!db.open())
    {
        qDebug()<<"数据库打开失败"<<db.lastError();
        return;
    }
    tableInit();
}

dbhelper::~dbhelper()
{
    if(db.isOpen())
    {
        db.close();
    }
}

void dbhelper::tableInit()
{
    QSqlQuery query(db);
    QString str = "create table if not exists songlist("
                  "path varchar(256) primary key,"
                  "name varchar(64) not null,"
                  "lrc varchar(256));";
    qDebug()<<query.exec(str)<<query.lastError();
}
