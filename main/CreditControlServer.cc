#include <cppzmq/zmq.hpp>
#include <iostream>
#include <unistd.h>
#include "log4z/log4z.h"
#include "libconfparser/confparser.hpp"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "gen-cpp/FetchBalance.h"
#include "OracleDB.hh"
#include "DBStruct.hh"
#include "ServIdentification.hh"

using namespace std;
using namespace zmq;
using namespace zsummer::log4z;

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

LoggerId logId;

void doCredit(string acc_nbr)
{
    int fetch_balance_port = CONF_PARSER_GET_NUM_VAL("FetchBalance", "port");
    const char* fetch_balance_ip = CONF_PARSER_GET_VAL("FetchBalance", "ip");

    shared_ptr<TTransport> t_socket(new TSocket(fetch_balance_ip, fetch_balance_port));

    shared_ptr<TTransport> transport(new TBufferedTransport(t_socket));

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    BossInterface::FetchBalanceClient  client(protocol);

    string db_user = CONF_PARSER_GET_VAL("DB", "user");
    string db_passwd = CONF_PARSER_GET_VAL("DB", "passwd");
    string db_instance = CONF_PARSER_GET_VAL("DB", "instance");
    LOG_INFO(logId, "DB User:"<<db_user);
    LOG_INFO(logId, "DB Passwd:"<<db_passwd);
    LOG_INFO(logId, "DB Instance:"<<db_instance);
    auto_ptr<OracleDB> m_db(new OracleDB(db_user,db_passwd,db_instance));
    m_db->connectToDB();

    try {  
        transport->open();
        double balance = client.fetchBalance(acc_nbr);
        LOG_INFO(logId, "The balance of "<<acc_nbr<<" is "<<balance);
        transport->close();

        //get serv_identification info
        LOG_INFO(logId, "Get serv identification for"<<acc_nbr);
        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());
        ST_SERV_IDENTIFICATION serv_ident_info;
        serv_ident_info = m_serv_ident.getServIdentInfoByNBR(acc_nbr);

    } catch (TException &tx) {
        transport->close();   
        LOG_ERROR(logId, "Pay fee for:"<<acc_nbr<<" ERROR, reason:"<<tx.what());
    }
}

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

        doCredit(acc_nbr);
    }

}

void* ajustAcctItemThread(void *)
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

        doCredit(acc_nbr);
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

    ret=pthread_create(&id[1],NULL,ajustAcctItemThread,NULL);
    if(ret!=0)
    {
        cerr<<"Create ajustAcctItemThread error!"<<endl;
        exit (1);
    }

    pthread_join(id[0], NULL);
    pthread_join(id[1], NULL);

    return 0;
}
