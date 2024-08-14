#ifndef DBCONTROL_H
#define DBCONTROL_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QList>

class dbControl
{
public:
    static dbControl *getInstance();//建立连接

    static void removeInstance();//断开连接

    QStringList showTables();//让table_show这个list展示现在的列表有多少个

    QList<QStringList> SelectTableAll(QString databaseName);

    QString executeCmd(QString cmd);

private:
    static dbControl* instance;
    dbControl();
    ~dbControl();
    QSqlDatabase db;

    void db_open();
    void db_close();
};

#endif // DBCONTROL_H
