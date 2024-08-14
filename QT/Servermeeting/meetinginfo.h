#ifndef MEETINGINFO_H
#define MEETINGINFO_H



#include <QString>
#include <QStringList>
#include <QHostAddress>


class meetinginfo
{
public:
    meetinginfo();
    QString host;
    QString meetingName;
    QStringList in_members;
    QStringList out_members;
    QHostAddress ip; //会议的组播地址
    int textPort;
    int videoPort;
    int audioPort;
    static int currentUsePort;
};

#endif // MEETINGINFO_H
