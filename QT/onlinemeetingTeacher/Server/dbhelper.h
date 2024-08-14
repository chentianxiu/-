#ifndef DBHELPER_H
#define DBHELPER_H


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class dbhelper
{
public:
    static dbhelper *getInstance();
    bool userLogin(QString name, QString pswd);
    bool addFriend(QString name1,QString name2);
    QStringList getFriends(QString name);
    QStringList getUsers();
    bool addFile(QString filePath,QString sender,QString recver,QString filename,QString type);
    QStringList getFiles(QString loginUser);
    QString getFilePath(QString sender,QString recver,QString filename);

private:
    static dbhelper* instance;
    dbhelper();
    ~dbhelper();

    QSqlDatabase db;
    void userTableInit();
    void friendTableInit();
    void fileTableInit();
    void groupinfoTableInit();
    void groupmemberTableInit();

    QString userTableName = "userlist";
    QString friendTableName = "friendlist";
    QString fileTableName = "fileinfo";
    QString groupTableName ="groupinfo";
    QString groupmemberTableName = "groupmember";

};

#endif // DBHELPER_H
