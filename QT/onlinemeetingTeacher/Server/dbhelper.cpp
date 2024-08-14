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

bool dbhelper::userLogin(QString name,QString pswd)
{
    QSqlQuery query(db);
    QString str = QString("select * from %1 where name='%2' and pswd='%3';").arg(userTableName).arg(name).arg(pswd);
    qDebug()<<"用户登录检测"<<query.exec(str);
    return query.next();
}

bool dbhelper::addFriend(QString name1, QString name2)
{
    QSqlQuery query(db);
    QString str = QString("select * from %1 where name1='%2' and name2='%3';").arg(friendTableName).arg(name1).arg(name2);

    query.exec(str);
    if(query.next())
    {
        qDebug()<<"好友关系已存在";
        return false;
    }

    str = QString("insert into %1 values('%2','%3');").arg(friendTableName).arg(name1).arg(name2);
    bool ret = query.exec(str);
    str = QString("insert into %1 values('%2','%3');").arg(friendTableName).arg(name2).arg(name1);
    ret = query.exec(str);

    qDebug()<<"添加好友"<<ret;
    return ret;
}

QStringList dbhelper::getFriends(QString name)
{
    QSqlQuery query(db);
    QString str = QString("select name2 from %1 where name1='%2';").arg(friendTableName).arg(name);

    qDebug()<<"获取好友列表"<<query.exec(str);
    QStringList list;
    while(query.next())
    {
        list.append(query.value(0).toString());
    }
    return list;
}

QStringList dbhelper::getUsers()
{
    QSqlQuery query(db);
    QString str = QString("select name from %1;").arg(userTableName);
    qDebug()<<"获取所有用户"<<query.exec(str);
    QStringList list;
    while(query.next())
    {
        list.append(query.value(0).toString());
    }
    return list;
}

bool dbhelper::addFile(QString filePath, QString sender, QString recver, QString filename, QString type)
{
    QSqlQuery query(db);
    QString str = QString("insert into %1 values('%2','%3','%4','%5','%6');");
    str = str.arg(fileTableName).arg(filePath).arg(sender).arg(recver).arg(filename).arg(type);
    bool ret = query.exec(str);
    qDebug()<<"添加新文件"<<ret;
    return ret;
}

QStringList dbhelper::getFiles(QString loginUser)
{
    QSqlQuery query(db);
    QString str = QString("select sender,recver,filename from %1 where sender='%2' or recver='%2';").arg(fileTableName).arg(loginUser);
    qDebug()<<"查找用户文件"<<query.exec(str);
    QStringList ret;
    while(query.next())
    {
        QString str = query.value(0).toString();
        str += "\n";
        str += query.value(1).toString();
        str += "\n";
        str += query.value(2).toString();
        ret.append(str);
    }
    return ret;
}

QString dbhelper::getFilePath(QString sender, QString recver, QString filename)
{
    QSqlQuery query(db);
    QString str = QString("select filepath from %1 where sender='%2' and recver='%3' and filename='%4';");
    str = str.arg(fileTableName).arg(sender).arg(recver).arg(filename);
    qDebug()<<"查找用户文件"<<query.exec(str);
    QString path;
    query.next();
    path = query.value(0).toString();
    return path;
}

dbhelper::dbhelper()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("ROOT");
    db.setDatabaseName("xw2402");

    if(!db.open())
    {
        qDebug()<<"数据库打开失败"<<db.lastError();
        return ;
    }

    //表格初始化
    userTableInit();
    friendTableInit();
    fileTableInit();
}

dbhelper::~dbhelper()
{
    if(db.isOpen())
    {
        db.close();
    }
}

void dbhelper::userTableInit()
{
    QSqlQuery query(db);
    QString str = "create table if not exists %1(name varchar(64) primary key,pswd varchar(64) not null,online bool);";
    str = QString(str).arg(userTableName);
    qDebug()<<"初始化用户数据表"<<query.exec(str);
}

void dbhelper::friendTableInit()
{
    QSqlQuery query(db);
    QString str = "create table if not exists %1(name1 varchar(64) not null,name2 varchar(64) not null);";
    str = QString(str).arg(friendTableName);
    qDebug()<<"初始化好友关系数据表"<<query.exec(str);
}

void dbhelper::fileTableInit()
{
    QSqlQuery query(db);
    QString str = "create table if not exists %1(filepath varchar(128) primary key,"
                  "sender varchar(64) not null,recver varchar(64) not null,"
                  "filename varchar(64) not null,type varchar(64) not null);";
    str = QString(str).arg(fileTableName);
    qDebug()<<"初始化好友关系数据表"<<query.exec(str);
}

void dbhelper::groupinfoTableInit()
{
    QSqlQuery query(db);
    QString str = "create table if not exists %1(name varchar(64) primary key,n_member int default 0);";
    str = QString(str).arg(groupTableName);
    qDebug()<<"初始化用户数据表"<<query.exec(str);
}

void dbhelper::groupmemberTableInit()
{
    QSqlQuery query(db);
    QString str = "create table if not exists %1(group varchar(64) not null,member varchar(64) not null);";
    str = QString(str).arg(groupmemberTableName);
    qDebug()<<"初始化好友关系数据表"<<query.exec(str);
}
