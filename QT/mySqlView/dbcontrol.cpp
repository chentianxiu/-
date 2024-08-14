#include "dbcontrol.h"
#include <QDebug>

dbControl* dbControl::instance = nullptr;

dbControl *dbControl::getInstance()
{
    if(nullptr == instance)
    {
        instance = new dbControl;
    }
    return instance;
}

void dbControl::removeInstance()
{
    if(nullptr!=instance)
    {
        delete instance;
    }
}

QStringList dbControl::showTables()//让table_show这个list展示现在的列表有多少个
{
    QSqlQuery query(db);
    QString str = "show tables";
    QStringList list;

    query.exec(str);
    while(query.next())//将show tables的结果一行一行的列出来在左边的列表框里展示
    {
        list.append(query.value(0).toString());
    }
    return list;
}

QList<QStringList> dbControl::SelectTableAll(QString databaseName)//将列表的查询结果展示在右边的框里面
{
    QSqlQuery query(db);
    QString str = QString("select * from %1").arg(databaseName);//将这个表的内容展示出来

    QList<QStringList> retList;//建立一个列表存储查询结果
    query.exec(str);

    QSqlRecord rec = query.record();// 获取查询结果的记录对象，用于访问字段名称和数据（一行数据）

    QStringList list;// 创建一个字符串列表，用于存储表头字段名称
    for(int i=0;i<rec.count();i++)
    {
        list.append(rec.fieldName(i));// 将每个字段的名称添加到列表中，将一行数据分解
    }

    retList.append(list);// 将字段名称列表作为第一行添加到结果列表中

    while(query.next())
    {
        QStringList list;// 创建一个新的字符串列表来存储当前行的数据
        for(int i=0;i<rec.count();i++)
        {
            list.append(query.value(i).toString());
        }
        retList.append(list);//列表存的列表
    }
    return retList;
}

QString dbControl::executeCmd(QString cmd)//执行命令
{
    QString retStr;
    QSqlQuery query(db);
    int ret = query.exec(cmd);
    if(ret)
    {
        retStr = "执行成功";
    }
    else
    {
        retStr = "执行失败" + query.lastError().text();
    }
    return retStr;
}

dbControl::dbControl()//数据库属性
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localHost");
    db.setDatabaseName("xw2402");
    db.setUserName("root");
    db.setPassword("ROOT");

    db.open();

}

dbControl::~dbControl()
{
    db.close();
}

void dbControl::db_open()
{
    if(!db.open())
    {
        qDebug()<<"数据库打开失败"<<db.lastError();
    }
}

void dbControl::db_close()
{
    if(db.isOpen())
    {
        db.close();
    }
}
