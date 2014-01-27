#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>
#include "gen-cpp/OpenAccountServlet.h"
#include "libconfparser/confparser.hpp"
#include <iostream>
#include <string>
 
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

int main(int argc, char** argv) {   

    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    int port = CONF_PARSER_GET_NUM_VAL("OpenAccount", "port");
    const char* pval = CONF_PARSER_GET_VAL("OpenAccount", "ip");
    cout<<"Server IP:"<<pval<<" Port:"<<port<<endl;

    int frequence = CONF_PARSER_GET_NUM_VAL("OpenAccount", "frequence");
    cout<<"The client send request each "<<frequence<<" seconds."<<endl;

    shared_ptr<TTransport> socket(new TSocket(pval, port));   

    shared_ptr<TTransport> transport(new TBufferedTransport(socket));   

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));   

    BossInterface::OpenAccountServletClient  client(protocol);   

    try {  
        int i=0;
        transport->open();   

        vector<BossData::OpenAccount> datas;   

        while(1)
        {
            cout<<"----------["<<++i<<"]----------"<<endl;

            client.Sender(datas);//RPC函数，调用serve端的该函数   

            sleep(frequence);
        }

        transport->close();   

    } catch (TException &tx) {   

        printf("ERROR: %s\n", tx.what());   

    }   

}  
