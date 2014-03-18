#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "gen-cpp/FetchNbr.h"
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
    int port = CONF_PARSER_GET_NUM_VAL("FetchNbr", "port");
    const char* pval = CONF_PARSER_GET_VAL("FetchNbr", "ip");
    cout<<"Server IP:"<<pval<<" Port:"<<port<<endl;

    shared_ptr<TTransport> socket(new TSocket(pval, port));   

    shared_ptr<TTransport> transport(new TBufferedTransport(socket));   

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));   

    BossInterface::FetchNbrClient  client(protocol);   

    try {  
        transport->open();   

        string nbr;
        client.fetchNbr(nbr);

        cout<<"Get a phone nbr:"<<nbr<<endl;

        transport->close();   

    } catch (TException &tx) {
        transport->close();   
        cerr<<"ERROR: "<<tx.what()<<endl;   
    }

}  
