#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>
#include "gen-cpp/OpenAccountServlet.h"
#include "libconfparser/confparser.hpp"

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

    shared_ptr<TTransport> socket(new TSocket(pval, port));   

    shared_ptr<TTransport> transport(new TBufferedTransport(socket));   

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));   

    BossInterface::OpenAccountServletClient  client(protocol);   

    try {   

        transport->open();   

        vector<BossData::OpenAccount> datas;   

        client.Sender(datas);//RPC函数，调用serve端的该函数   

        transport->close();   

    } catch (TException &tx) {   

        printf("ERROR: %s\n", tx.what());   

    }   

}  
