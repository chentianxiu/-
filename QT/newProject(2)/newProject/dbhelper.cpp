#include "dbhelper.h"
#include <QDebug>

dbhelper* dbhelper::instance = nullptr;

dbhelper *dbhelper::getInstance()
{
    if(nullptr == instance) //如果没有实例
    {
        instance = new dbhelper; //生成实例
    }
    return instance;
}

void dbhelper::removeInstance()//删除实例
{
    if(nullptr != instance)
    {
        delete instance;
        instance = nullptr;
    }
}

bool dbhelper::addNewUser(QString name, QString pswd) //插入新用户信息
{
    QSqlQuery query(db);
    QString queryStr = QString("insert into userinfo values('%1','%2')").arg(name).arg(pswd);
    bool res = query.exec(queryStr);
    if(res)
    {
        qDebug()<<"添加成功";
    }
    else
    {
        qDebug()<<"添加失败"<<query.lastError();
    }
    return res;
}

bool dbhelper::fineUser(QString name, QString pswd) //查找用户信息
{
    QSqlQuery query(db);
    QString queryStr = QString("select * from userinfo where username='%1' and password='%2'").arg(name).arg(pswd);
    query.exec(queryStr);

    bool res = query.next();
    if(res)
    {
        qDebug()<<"找到用户";
    }
    else
    {
        qDebug()<<"未找到用户";
    }
    return res;
}

dbhelper::dbhelper()
{
    this->db_opt();
    this->db_open();
    this->userInfo_init();
}

dbhelper::~dbhelper()
{
    this->db_close();
}

void dbhelper::db_opt() //数据库信息设置
{
    db = QSqlDatabase::addDatabase("QMYSQL"); //设置数据库为mysql数据库
    db.setHostName("localhost"); //设置服务器地址为本机地址
    db.setDatabaseName("xw2402"); //设置使用的数据库 （use xw2402）
    db.setUserName("root");
    db.setPassword("ROOT");
}

void dbhelper::db_open() //打开数据库
{
    if(db.open())
    {
        qDebug()<<"数据库打开成功";
    }
    else
    {
        qDebug()<<"数据库打开失败"<<db.lastError();
    }
}

void dbhelper::db_close() //关闭数据库
{
    if(db.isOpen())
    {
        db.close();
    }
}

void dbhelper::userInfo_init() //用户信息表-初始化
{
    QSqlQuery query(db);
    QString queryStr = "create table if not exists userinfo(username varchar(20) primary key,password varchar(20) not null);";
    bool res = query.exec(queryStr);
    if(res)
    {
        qDebug()<<"用户数据表准备完成";
    }
    else
    {
        qDebug()<<"用户数据表异常"<<query.lastError();
    }
}
