#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>
#include "gen-cpp/OpenAccountServlet.h"

#include <string>
 
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

int main(int argc, char** argv) {   

    shared_ptr<TTransport> socket(new TSocket("localhost", 9090));   

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
