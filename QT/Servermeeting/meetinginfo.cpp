#include "meetinginfo.h"


int meetinginfo::currentUsePort = 8000;


meetinginfo::meetinginfo()
{
    ip = QHostAddress("224.0.1.0");
    textPort = currentUsePort;
    currentUsePort = (currentUsePort+1)%1001+8000;
    videoPort = currentUsePort;
    currentUsePort = (currentUsePort+1)%1001+8000;
    audioPort = currentUsePort;
    currentUsePort = (currentUsePort+1)%1001+8000;
}
