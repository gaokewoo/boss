#include <iostream>
#include <string>
#include <signal.h>
#include "libconfparser/confparser.hpp"
#include "WriteOff.hh"
#include "BossMonitorClient.hh"
#include "log4z/log4z.h"

void mkDaemon(void)
{
    pid_t pid;
    pid_t sid;

    pid = fork();
    if (pid == -1)
      printf("Failed to fork() ");

    if (pid) {
        exit(0);
    }

    sid = setsid();
    if (sid == -1)
      abort();
    return;
} 

int main(int argc, char** argv) {   

    mkDaemon();

    LoggerId logId;
    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    logId = ILog4zManager::GetInstance()->FindLogger("WriteOff");
    ILog4zManager::GetInstance()->Start();

    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    int frequence = CONF_PARSER_GET_NUM_VAL("WriteOff", "frequence");
    LOG_INFO(logId, "The WriteOff will sleep "<<frequence<<" milliseconds to do next scan");

    ::BossMonitorClient client;
    BossData::BossMonitor data;
    data.id=getpid();
    data.name=basename(argv[0]);
    data.status="Active";
    data.ip=CONF_PARSER_GET_VAL("WriteOff", "ip");;
    data.port=0;
    client.subscribe(data);

    auto_ptr<WriteOff> m_write_off(new WriteOff(logId));

    try {  

        while(1)
        {
            m_write_off->doBiz();

            usleep(frequence*1000);
        }


    } catch (...) {   
        cerr<<"ERROR....."<<endl;
        exit(-1);

    }   

}  
