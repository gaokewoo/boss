#include <iostream>
#include <string>
#include <signal.h>
#include "libconfparser/confparser.hpp"
#include "OpenAccount.hh"

void handler(int signo)
{
    cerr<<"Program terminated"<<endl;  
    exit(0);  
}

int main(int argc, char** argv) {   

    LoggerId logId;
    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    logId = ILog4zManager::GetInstance()->FindLogger("OpenAccount");
    ILog4zManager::GetInstance()->Start();

    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    int port = CONF_PARSER_GET_NUM_VAL("OpenAccount", "port");
    const char* pval = CONF_PARSER_GET_VAL("OpenAccount", "ip");
    cout<<"Server IP:"<<pval<<" Port:"<<port<<endl;

    int frequence = CONF_PARSER_GET_NUM_VAL("OpenAccount", "frequence");
    cout<<"The client send request each "<<frequence<<" milliseconds."<<endl;

    OpenAccount *m_open_account = new OpenAccount(logId);

    signal(SIGINT,handler);

    try {  
        int i=0;


        while(1)
        {
            cout<<"----------["<<++i<<"]----------"<<endl;
            m_open_account->doBiz();

            usleep(frequence*1000);
        }


    } catch (...) {   
        cerr<<"ERROR....."<<endl;
        exit(-1);

    }   

}  
