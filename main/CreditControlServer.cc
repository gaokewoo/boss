#include <cppzmq/zmq.hpp>
#include <iostream>
#include <unistd.h>
#include "log4z/log4z.h"
#include "libconfparser/confparser.hpp"
#include "CreditControl.hh"
#include <memory>

using namespace std;
using namespace zmq;
using namespace zsummer::log4z;

LoggerId logId;

void* payFeeThread(void *)
{
    LOG_INFO(logId, "Parse boss.cfg");
    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");

    const char* pval = CONF_PARSER_GET_VAL("AdjustAcctItem", "ip");
    int port = CONF_PARSER_GET_NUM_VAL("PayFee", "zmq_pub_port");

    context_t context (1);
    // Socket to talk to clients
    socket_t socket (context, ZMQ_SUB);

    char tmp[30];
    sprintf(tmp,"tcp://%s:%d",pval,port);
    LOG_INFO(logId, "Subscriber listening :"<<tmp);

    auto_ptr<CreditControl> m_credit_control(new CreditControl(logId));
    while (true) 
    {
        // Wait for next request from client
        socket.connect (tmp);

        char* filter = (char*)"JF ";
        socket.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

        message_t pub_info;

        socket.recv(&pub_info);
        string acc_nbr((char*)pub_info.data());
        acc_nbr=acc_nbr.substr(3);
        
        LOG_INFO(logId, "Pay fee for:"<<acc_nbr);

        m_credit_control->doBiz(acc_nbr);
    }

}

void* adjustAcctItemThread(void *)
{
    LOG_INFO(logId, "Parse boss.cfg");
    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");

    const char* pval = CONF_PARSER_GET_VAL("AdjustAcctItem", "ip");
    int port = CONF_PARSER_GET_NUM_VAL("AdjustAcctItem", "zmq_pub_port");

    context_t context (1);
    // Socket to talk to clients
    socket_t socket (context, ZMQ_SUB);

    char tmp[30];
    sprintf(tmp,"tcp://%s:%d",pval,port);
    LOG_INFO(logId, "Subscriber listening :"<<tmp);
    auto_ptr<CreditControl> m_credit_control(new CreditControl(logId));
    while (true) 
    {
        // Wait for next request from client
        socket.connect (tmp);

        char* filter = (char*)"TZ ";
        socket.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

        message_t pub_info;

        socket.recv(&pub_info);
        string acc_nbr((char*)pub_info.data());
        acc_nbr=acc_nbr.substr(3);

        LOG_INFO(logId,"Adjust acct item for:"<<acc_nbr);

        m_credit_control->doBiz(acc_nbr);
    }

}

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

int main (void)
{
    mkDaemon();

    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    logId = ILog4zManager::GetInstance()->FindLogger("CreditControl");
    ILog4zManager::GetInstance()->Start();

    pthread_t id[2];
    int ret;
    ret=pthread_create(&id[0],NULL,payFeeThread,NULL);
    if(ret!=0)
    {
        cerr<<"Create payFeeThread error!"<<endl;
        exit (1);
    }

    ret=pthread_create(&id[1],NULL,adjustAcctItemThread,NULL);
    if(ret!=0)
    {
        cerr<<"Create adjustAcctItemThread error!"<<endl;
        exit (1);
    }

    pthread_join(id[0], NULL);
    pthread_join(id[1], NULL);

    return 0;
}
