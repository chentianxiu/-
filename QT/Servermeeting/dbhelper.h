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
    bool userLogin(QString name, QString pswd);//登录
    bool userregist(QString name, QString pswd);//注册

    bool isonline(QString name);//判断是否在线
    bool setonline(QString name);//设置为在线状态
    bool setunonline(QString name);//设置不在线状态


    bool addFriend(QString name1,QString name2);//增加好友
    QStringList getFriends(QString name);//用户登录时获取好友信息
    QStringList getUsers();//用户登录时获取用户信息

    bool addGroupinfo(QString name,QString groupname);//增加群组------------------------------
    bool addGroupmember(QString groupName,QStringList members);//增加群(的成员)

    QStringList getGroupinfo(QString name);//登陆时获取群的信息-----------------------------
    QStringList getGroupmembers(QString groupname);//获取群成员信息


    bool addFile(QString filePath,QString sender,QString recver,QString filename,QString type);//上传文件信息
    QStringList getFiles(QString loginUser);//用户登录时获取文件信息
    QString getFilePath(QString sender,QString recver,QString filename);//下载时获取文件位置

private:
    static dbhelper* instance;//创建实例，单例模式
    dbhelper();
    ~dbhelper();

    QSqlDatabase db;//数据库
    void userTableInit();//用户列表初始化
    void friendTableInit();//好友列表初始化
    void fileTableInit();//文件信息列表初始化
    //void groupinfoTableInit();//群聊信息初始化
    void groupmemberTableInit();//群聊成员初始化

    QString userTableName = "userlist";//宏定义
    QString friendTableName = "friendlist";
    QString fileTableName = "fileinfo";
    //QString groupTableName ="groupinfo";//群信息
    QString groupmemberTableName = "groupmember";//群成员
};

#endif // DBHELPER_H
