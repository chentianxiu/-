#include "dbhelper.h"
#include <QDebug>


dbhelper* dbhelper::instance = nullptr;//指向空


dbhelper *dbhelper::getInstance()//创建对象
{
    if(instance == nullptr)
    {
        instance = new dbhelper;
    }
    return instance;
}

void dbhelper::removeInstance()//删除对象
{
    if(instance!=nullptr)
    {
        delete instance;
    }
}

//添加歌曲地址到数据库中
bool dbhelper::addSong(QString song, QString Name, QString lrc)
{
    QSqlQuery query(db);//数据库指令函数
    QString str = QString("insert into songlist values('%1','%2','%3');").arg(song).arg(Name).arg(lrc);
    int ret = query.exec(str);
    qDebug()<<ret<<query.lastError();
    return ret;
}

QStringList dbhelper::getSonglist()//从数据库中获取保存的歌曲路径
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

QString dbhelper::getSonglryics(QString path)//从数据库中获得歌词路径
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

bool dbhelper::removeSong(const QString &songName)
{
    QSqlQuery query;
    query.prepare("DELETE FROM songlist WHERE name = :name");
    query.bindValue(":name", songName);
    qDebug()<<query.exec();
    return query.exec();
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

void dbhelper::tableInit()//创建表
{
    QSqlQuery query(db);
    QString str = "create table if not exists songlist("
                  "path varchar(256) primary key,"
                  "name varchar(64) not null,"
                  "lrc varchar(256));";
    qDebug()<<query.exec(str)<<query.lastError();
}
