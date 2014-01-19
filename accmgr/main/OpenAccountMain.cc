#include "OpenAccount.hh"

int main()
{
    LoggerId open_account;
    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    open_account= ILog4zManager::GetInstance()->FindLogger("OpenAccount");
    ILog4zManager::GetInstance()->Start();
    //ILog4zManager::GetInstance()->SetLoggerDisplay(open_account, true);
    //ILog4zManager::GetInstance()->SetLoggerLevel(open_account, LOG_LEVEL_DEBUG);
    //ILog4zManager::GetInstance()->SetLoggerMonthdir(open_account, true);

    OpenAccount main(open_account);
    main.doBiz();


    return 0;
}
