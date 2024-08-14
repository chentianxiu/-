#include "dbhelper.h"
#include<QDebug>


dbhelper * dbhelper::instance = nullptr;

dbhelper *dbhelper::getInstance()
{
    if(nullptr == instance)
    {
        instance = new dbhelper;//没有实列，生成实例
    }
    return instance;
}

void dbhelper::removeInstance()//删除实列
{
    if(nullptr != instance)
    {
        delete instance;
        instance = nullptr;
    }

}

bool dbhelper::addNewUser(QString name, QString pswd)//插入新用户
{
    QSqlQuery query(db);
    QString queryStr = QString("insert into userinfo value('%1','%2')").arg(name).arg(pswd);
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

bool dbhelper::findUser(QString name, QString pswd)//查找用户信息
{
    QSqlQuery query(db);
    QString queryStr = QString("select * from userinfo where username='%1'and password = '%2' ").arg(name).arg(pswd);
    query.exec(queryStr);

    bool res = query.next();
    if(res)
    {
        qDebug()<<"找到用户";
    }else
    {
        qDebug()<<"未找到用户";
    }
}

dbhelper::dbhelper()//构造函数
{
    this->db_opt();
    this->db_open();
    this->userInfo_init();
}

dbhelper::~dbhelper()
{
    this->db_close();
}

void dbhelper::db_opt()
{
    db = QSqlDatabase::addDatabase("QMYSQL"); //设置数据库类型MYSQL
    db.setHostName("localhost"); // 设置MySQL服务器地址
    db.setDatabaseName("xw2402"); // 设置数据库名称
    db.setUserName("root"); // 设置用户名
    db.setPassword("ROOT"); // 设置密码

}

void dbhelper::db_open()//打开数据库
{
    if(db.open())
    {
        qDebug()<<"数据库打开成功";
    }else
    {
        qDebug()<<"数据库打开失败"<<db.lastError();
    }
}

void dbhelper::db_close()//关闭数据库
{
    if(db.isOpen())
    {
        db.close();
    }
}

void dbhelper::userInfo_init()//用户信息表初始化
{
    QSqlQuery query;
    QString queryStr = "create table if not exists userinfo(username varchar(20) primary key,password varchar(20) not null)";
    bool res = query.exec(queryStr);
    if(res)
    {
        qDebug()<<"用户数据表准备完成";
    }else
    {
        qDebug()<<"用户数据表异常"<<query.lastError();
    }
}
