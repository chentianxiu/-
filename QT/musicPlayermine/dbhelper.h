#ifndef DBHELPER_H
#define DBHELPER_H


#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>

class dbhelper
{
public:

    static dbhelper *getInstance();//创建对象
    static void removeInstance();//删除对象
    //添加歌曲到数据库中
    bool addSong(QString song, QString Name, QString lrc);

    //从数据库中获取保存的歌曲路径
    QStringList getSonglist();

    //从数据库中获得歌词路径
    QString getSonglryics(QString path);

    //删除歌曲
    bool removeSong(const QString &songName);

private:
    static dbhelper* instance;//创建对象
    dbhelper();
    ~dbhelper();
    QSqlDatabase db;

    void tableInit();//创建表
};

#endif // DBHELPER_H
