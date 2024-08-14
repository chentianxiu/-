#include "dbhelper.h"

dbhelper *dbhelper::instance = nullptr;

dbhelper *dbhelper::getINstance()
{
    if(instance == nullptr){
        instance = new dbhelper;
    }
    return instance;
}
void dbhelper::removeInstance()
{
    if(instance != nullptr){
        delete instance;
        instance = nullptr;
    }
}


bool dbhelper::addMusic(QString path,QString name,QString lrcPath)
{
    QSqlQuery query(db);
    QString text = QString("insert into musicList values('%1','%2','%3');").arg(path).arg(name).arg(lrcPath);
    bool res = query.exec(text);
    if(res){
        qDebug()<<"数据添加成功!";
    }else{
        qDebug()<<"数据添加失败!";
    }
    return res;
}
bool dbhelper::findMusic(QString name)
{
    QSqlQuery query(db);
    QString text = QString("select * from musicList where name='%1';").arg(name);
    query.exec(text);
    int res = query.next();
    if(res){
        qDebug()<<"数据已存在!";
    }else{
        qDebug()<<"数据不存在!";
    }
    return res;
}
QString dbhelper::getLrcPath(QString name)
{
    QSqlQuery query(db);
    QString text = QString("select lrcPath from musicList where name='%1';").arg(name);
    query.exec(text);
    if(!query.next()){
        qDebug()<<"未找到该歌曲!";
        return "ERROR";
    }
    return query.value(0).toString();
}


dbhelper::dbhelper()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./mSqlite.db");
    if(db.open()){
        qDebug()<<"数据库打开成功!";
    }else{
        qDebug()<<"数据库打开失败!"<<db.lastError();
    }
    db_info();
}
dbhelper::~dbhelper()
{
    QSqlQuery query(db);
    QString text = "delete from musicList;";
    bool res = query.exec(text);
    if(res){
        qDebug()<<"数据表格已清空!";
    }
    if(db.isOpen()){
        db.close();
    }
}


void dbhelper::db_info()
{
    QSqlQuery query(db);
    QString text = "create table if not exists musicList(path varchar(128),name varchar(32) primary key,lrcPath varchar(128));";
    bool res = query.exec(text);
    if(res){
        qDebug()<<"数据库准备完成!";
    }else{
        qDebug()<<"数据库异常!";
    }
}
