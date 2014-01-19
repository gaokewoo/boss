// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "BossMonitor.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::BossInterface;

class BossMonitorHandler : virtual public BossMonitorIf {
 public:
  BossMonitorHandler() {
    // Your initialization goes here
  }

  bool subscirbe(const  ::BossData::BossMonitor& datas) {
    // Your implementation goes here
    printf("subscirbe\n");
  }

  void getAll(std::vector< ::BossData::BossMonitor> & _return) {
    // Your implementation goes here
    printf("getAll\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<BossMonitorHandler> handler(new BossMonitorHandler());
  shared_ptr<TProcessor> processor(new BossMonitorProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

