#ifndef DBHELPER_H
#define DBHELPER_H

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>

class dbhelper
{
public:
    static dbhelper *getInstance();
    static void removeInstance();
    bool addSong(QString song, QString Name, QString lrc);
    QStringList getSonglist();
    QString getSonglryics(QString path);
private:
    static dbhelper* instance;
    dbhelper();
    ~dbhelper();
    QSqlDatabase db;

    void tableInit();
};

#endif // DBHELPER_H
