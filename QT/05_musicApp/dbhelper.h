#ifndef DBHELPER_H
#define DBHELPER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class dbhelper
{
public:
    static dbhelper *getINstance();
    static void removeInstance();
    bool addMusic(QString path,QString name,QString lrcPath);
    bool findMusic(QString name);
    QString getLrcPath(QString name);

private:
    static dbhelper *instance;
    dbhelper();
    ~dbhelper();
    QSqlDatabase db;

    void db_info();

};

#endif // DBHELPER_H
