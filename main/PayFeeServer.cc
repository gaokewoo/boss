// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "gen-cpp/PayFee.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include "libconfparser/confparser.hpp"
#include "BossMonitorClient.hh"
#include "PayFee.hh"
#include "log4z/log4z.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

using namespace  ::BossInterface;

using namespace zsummer::log4z;

class PayFeeHandler : virtual public PayFeeIf {
    public:
        PayFeeHandler(LoggerId logId) {
            // Your initialization goes here
            m_logId = logId;
            m_payment=new PayFee(m_logId);
        }

        ~PayFeeHandler() {
            // Your initialization goes here
            delete m_payment;
            m_payment=NULL;
        }

        bool subscribe(const  ::BossData::PayFee& data) {
            // Your implementation goes here
            LOG_INFO(m_logId, "Receive a message...");
            LOG_INFO(m_logId, "Pay "<<data.fee<<" to "<<data.nbr);
            PayFeeData my_data;
            my_data.nbr = data.nbr;
            my_data.fee= data.fee;
            m_payment->doBiz(my_data);

            LOG_INFO(m_logId, "Server handle successfully.");

            return true;
        }

    private:
        PayFee *m_payment;
        LoggerId m_logId;
};

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

int main(int argc, char **argv) {

    mkDaemon();

    LoggerId logId;
    ILog4zManager::GetInstance()->Config("../conf/log.cfg");
    logId = ILog4zManager::GetInstance()->FindLogger("PayFee");
    ILog4zManager::GetInstance()->Start();

    LOG_INFO(logId, "Parse boss.cfg");
    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    int port = CONF_PARSER_GET_NUM_VAL("PayFee", "port");

    LOG_INFO(logId, "Server listening port:"<<port);

    shared_ptr<PayFeeHandler> handler(new PayFeeHandler(logId));
    shared_ptr<TProcessor> processor(new PayFeeProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    ::BossMonitorClient client;
    BossData::BossMonitor data;
    data.id=getpid();
    data.name=basename(argv[0]);
    data.status="Active";
    data.ip=CONF_PARSER_GET_VAL("PayFee", "ip");;
    data.port=port;
    client.subscribe(data);

    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(10);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());

    threadManager->threadFactory(threadFactory);
    threadManager->start();

    TThreadPoolServer server(processor, serverTransport, transportFactory, protocolFactory, threadManager);
    server.serve();
    return 0;
}

