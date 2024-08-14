#ifndef DBHELPER_H
#define DBHELPER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class dbhelper
{
public:
    static dbhelper *getInstance(); //获取实例的接口
    static void removeInstance(); //删除实例
    bool addNewUser(QString name,QString pswd);
    bool fineUser(QString name,QString pswd);

private:
    static dbhelper *instance; //唯一实例
    dbhelper();  //构造私有化
    ~dbhelper(); //析构私有化
    QSqlDatabase db;

    void db_opt();
    void db_open();
    void db_close();

    void userInfo_init();
};

#endif // DBHELPER_H
