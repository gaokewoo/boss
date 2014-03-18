#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "gen-cpp/PayFee.h"
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
    int port = CONF_PARSER_GET_NUM_VAL("PayFee", "port");
    const char* pval = CONF_PARSER_GET_VAL("PayFee", "ip");
    cout<<"Server IP:"<<pval<<" Port:"<<port<<endl;

    int frequence = CONF_PARSER_GET_NUM_VAL("PayFee", "frequence");
    cout<<"The client send request each "<<frequence<<" millisecond."<<endl;

    shared_ptr<TTransport> socket(new TSocket(pval, port));   

    shared_ptr<TTransport> transport(new TBufferedTransport(socket));   

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));   

    BossInterface::PayFeeClient  client(protocol);   

    try {  
        int i=0;
        transport->open();   

        BossData::PayFee data;   

        while(1)
        {
            cout<<"----------["<<++i<<"]----------"<<endl;

            client.subscribe(data);

            usleep(frequence*1000);
        }

        transport->close();   

    } catch (TException &tx) {
        transport->close();   
        cerr<<"ERROR: "<<tx.what()<<endl;   
    }

}  
