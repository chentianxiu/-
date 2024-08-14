#include "dbhelper.h"
#include <QDebug>

dbhelper* dbhelper::instance = nullptr;//指向空

dbhelper *dbhelper::getInstance()//懒汉式单例在第一次调用 getInstance 方法时创建实例，延迟加载，但需要考虑线程安全问题。
{
    if(instance == nullptr)
    {
        instance = new dbhelper;
    }
    return instance;
}

bool dbhelper::userLogin(QString name, QString pswd)//登录
{
    QSqlQuery query(db);
    QString str = QString("select * from %1 where name='%2' and pswd='%3';").arg(userTableName).arg(name).arg(pswd);
    query.exec(str);
    bool ret = query.next();
    qDebug()<<"用户存在检测"<<ret;
    return ret;
}

bool dbhelper::userregist(QString name, QString pswd)//注册
{
    QSqlQuery query(db);
    QString str = QString("insert %1 values('%2','%3',0);").arg(userTableName).arg(name).arg(pswd);
    bool ret = query.exec(str);
    qDebug()<<"用户注册检测"<<ret;
    return ret;
}

bool dbhelper::isonline(QString name)//判断是否在线
{
    QSqlQuery query(db);
    QString str = QString("select * from %1 where name='%2';").arg(userTableName).arg(name);
    query.exec(str);
    if (query.next()) {
        // 如果查询结果集有记录，访问结果集中的值
        bool isOnline = query.value(2).toBool();
        return isOnline;
    } else {
        // 没有找到对应的记录
        qDebug() << "No record found for user:" << name;
        return false; // 或者其他适当的处理
    }
}

bool dbhelper::setonline(QString name)//设置在线状态
{
    QSqlQuery query(db);
    QString str = QString("UPDATE %1 SET online = true WHERE name = '%2';").arg(userTableName).arg(name);
    bool ret = query.exec(str);
    qDebug()<<"用户在线检测"<<ret;
    return ret;
}

bool dbhelper::setunonline(QString name)//设置离线状态
{
    QSqlQuery query(db);
    QString str = QString("UPDATE %1 SET online = false WHERE name = '%2';").arg(userTableName).arg(name);
    bool ret = query.exec(str);
    qDebug()<<"用户离线检测"<<ret;
    return ret;
}

//服务器开始时设置所有的用户为离线状态，否则需要先退出客户端

bool dbhelper::addFriend(QString name1, QString name2)//增加好友
{
    QSqlQuery query(db);
    QString str = QString("select * from %1 where name1='%2' and name2='%3';").arg(friendTableName).arg(name1).arg(name2);

    query.exec(str);
    if(query.next())
    {
        qDebug()<<"好友关系已存在";
        return false;
    }

    //1，2和2，1都添加一遍，方便后面的查询
    str = QString("insert into %1 values('%2','%3');").arg(friendTableName).arg(name1).arg(name2);
    bool ret = query.exec(str);
    str = QString("insert into %1 values('%2','%3');").arg(friendTableName).arg(name2).arg(name1);
    ret = query.exec(str);

    qDebug()<<"添加好友"<<ret;
    return ret;
}

QStringList dbhelper::getFriends(QString name)//获取好友信息
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

QStringList dbhelper::getUsers()//获取用户信息
{
    QSqlQuery query(db);
    QString str = QString("select name from %1;").arg(userTableName);
    qDebug()<<"获取所有用户"<<query.exec(str);
    QStringList list;
    while(query.next())
    {
        list.append(query.value(0).toString());
    }
    //qDebug()<<list;
    return list;
}

bool dbhelper::addGroupmember(QString groupName, QStringList members)//增加群(的成员)
{
    QSqlQuery query(db);
    QString membersStr = members.join(",");  // 使用逗号分隔成员
    QString str = QString("insert into %1 values('%2','%3');").arg(groupmemberTableName).arg(groupName).arg(membersStr);
    bool ret = query.exec(str);
    qDebug()<<"添加新群"<<ret;
    return  ret;
}

QStringList dbhelper::getGroupinfo(QString name)//根据用户名获得群列表
{
    QSqlQuery query(db);
    QString str = QString("SELECT groupname FROM %1;").arg(groupmemberTableName);
    QStringList groupList;

    if (query.exec(str)) {
        while (query.next()) {
            QString groupName = query.value(0).toString();
            QStringList members = getGroupmembers(groupName);

            // 检查用户是否在群成员中
            if (members.contains(name)) {
                groupList.append(groupName);
            }
        }
    } else {
        qDebug() << "获取群列表失败" << query.lastError();
    }
    return groupList;
}

QStringList dbhelper::getGroupmembers(QString groupname)//获取群成员信息
{
    QSqlQuery query(db);
    QString str = QString("SELECT member FROM %1 WHERE groupname = '%2';")
            .arg(groupmemberTableName)
            .arg(groupname);
    QStringList members;

    if (query.exec(str)) {
        if (query.next()) {
            QString memberStr = query.value(0).toString();
            members = memberStr.split(",");  // 根据存储的分隔符拆分字符串s
        }
    } else {
        qDebug() << "获取群成员失败" << query.lastError();
    }

    return members ;
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

QStringList dbhelper::getFiles(QString loginUser)//用户登录时获取文件信息
{
    QStringList groupname = getGroupinfo(loginUser);
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

    for(auto it:groupname)
    {
        QSqlQuery query(db);
        QString str = QString("select sender,recver,filename from %1 where recver='%2';").arg(fileTableName).arg(it);
        query.exec(str);
        while(query.next()&&query.value(0).toString()!=loginUser)
        {
            QString str = query.value(0).toString();
            str += "\n";
            str += query.value(1).toString();
            str += "\n";
            str += query.value(2).toString();
            ret.append(str);
        }
    }

    return ret;
}

QString dbhelper::getFilePath(QString sender, QString recver, QString filename)//下载时获取文件位置
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

dbhelper::dbhelper()//初始化
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
    groupmemberTableInit();
}

dbhelper::~dbhelper()
{
    if(db.isOpen())
    {
        db.close();
    }
}

void dbhelper::userTableInit()//用户列表初始化
{
    QSqlQuery query(db);
    QString str = "create table if not exists %1(name varchar(64) primary key,pswd varchar(64) not null,online bool);";
    str = QString(str).arg(userTableName);
    qDebug()<<"初始化用户数据表"<<query.exec(str);
}

void dbhelper::friendTableInit()//好友列表初始化
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
    qDebug()<<"初始文件上传数据表"<<query.exec(str);
}

//void dbhelper::groupinfoTableInit()//群聊信息初始化
//{
//    QSqlQuery query(db);
//    QString str = "create table if not exists %1(name varchar(64) primary key,groupname varchar(64) not null);";
//    str = QString(str).arg(groupTableName);
//    qDebug()<<"初始用户群聊数据表"<<query.exec(str);
//}

void dbhelper::groupmemberTableInit()//群聊成员初始化
{
    QSqlQuery query(db);
    QString str = "create table if not exists %1(groupname varchar(64) not null,member varchar(128) not null);";
    str = QString(str).arg(groupmemberTableName);
    qDebug()<<"初始化群聊成员数据表"<<query.exec(str);
}
