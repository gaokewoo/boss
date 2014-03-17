#include "ConfigData.hh"

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

int main(int argc, char **argv) {

    mkDaemon();

    LoggerId logId;
    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    logId = ILog4zManager::GetInstance()->FindLogger("ConfigData");
    ILog4zManager::GetInstance()->Start();

    ConfigData m_config_data(logId);

    m_config_data.doBiz();

    return 0;
}

