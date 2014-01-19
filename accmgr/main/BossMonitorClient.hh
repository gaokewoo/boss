#ifndef __BOSS_MONITOR_CLIENT_HH__
#define __BOSS_MONITOR_CLIENT_HH__
#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>
#include "gen-cpp/BossMonitor.h"
#include "libconfparser/confparser.hpp"

#include <string>
 
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

class BossMonitorClient{   

public:
    BossMonitorClient()
    {
        CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
        int port = CONF_PARSER_GET_NUM_VAL("BossMonitor", "port");
        const char* pval = CONF_PARSER_GET_VAL("BossMonitor", "ip");

        socket.reset(new TSocket(pval, port));

        transport.reset(new TBufferedTransport(socket));

        protocol.reset(new TBinaryProtocol(transport));

        client.reset(new BossInterface::BossMonitorClient(protocol));
    }

    void subscirbe(BossData::BossMonitor data)
    {
        try {   

            transport->open();   

            client->subscirbe(data);

            transport->close();   

        } catch (TException &tx) {   
            printf("ERROR: %s\n", tx.what());   
        }   
    }

    void getAll()
    {
        try {   

            transport->open();   

            vector<BossData::BossMonitor> datas;
            client->getAll(datas);

            vector<BossData::BossMonitor>::iterator it;
            cout<<"******************************************************************************"<<endl;
            cout<<"PROCESS_ID\tPROCESS_NAME\t\tPROCESS_STATUS\tLISTENING_IP\t\tLISTENING_PORT"<<endl;
            for (it=datas.begin(); it!=datas.end(); it++)
            {
                cout<<(*it).id<<"\t\t"<<(*it).name<<"\t"<<(*it).status<<"\t\t"<<(*it).ip<<"\t\t"<<(*it).port<<"\t\t"<<endl;
            }
            cout<<"******************************************************************************"<<endl;

            transport->close();   

        } catch (TException &tx) {   
            printf("ERROR: %s\n", tx.what());   
        }   

    }

private:
    shared_ptr<TTransport> socket;
    shared_ptr<TTransport> transport;
    shared_ptr<TProtocol> protocol;
    shared_ptr<BossInterface::BossMonitorClient>  client;
};  

#endif

