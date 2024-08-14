#ifndef DBHELPER_H
#define DBHELPER_H


#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>


class dbhelper
{
public:
    static dbhelper * getInstance();//获取实列接口
    static void  removeInstance();//取消实列接口,删除实例
    bool addNewUser(QString name,QString pswd);//增加新用户
    bool findUser(QString name,QString pswd);//查找用户

private:
        static dbhelper * instance;//唯一实例
        dbhelper();//构造私有化
        ~dbhelper();//析构私有化
        QSqlDatabase db;

        void db_opt();
        void db_open();
        void db_close();

        void userInfo_init();//用户信息列表初始化
};

#endif // DBHELPER_H

