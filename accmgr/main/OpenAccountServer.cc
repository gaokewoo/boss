// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "gen-cpp/OpenAccountServlet.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "OpenAccount.hh"
#include "libconfparser/confparser.hpp"
#include "BossMonitorClient.hh"
#include <libgen.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::BossInterface;

class OpenAccountServletHandler : virtual public OpenAccountServletIf {
    public:
        OpenAccountServletHandler(LoggerId logId) {
            // Your initialization goes here
            m_logId = logId;
            m_open_account=new OpenAccount(m_logId);
        }

        ~OpenAccountServletHandler() {
            // Your initialization goes here
            delete m_open_account;
            m_open_account=NULL;
        }

        bool send(const  ::BossData::OpenAccount& data) {
            // Your implementation goes here
            LOG_INFO(m_logId, "Receive a message...");
            AccountData account_data;
            account_data.nbr = data.nbr;
            account_data.name = data.name;
            account_data.gender = data.gender;
            account_data.idNo = data.idNo;
            account_data.address = data.address;
            m_open_account->doBiz(account_data);
            LOG_INFO(m_logId, "Server handle successfully.");

            return true;
        }

    private:
        OpenAccount *m_open_account;
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
    logId = ILog4zManager::GetInstance()->FindLogger("OpenAccount");
    ILog4zManager::GetInstance()->Start();

    LOG_INFO(logId, "Parse boss.cfg");
    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    int port = CONF_PARSER_GET_NUM_VAL("OpenAccount", "port");
    LOG_INFO(logId, "Server listening port:"<<port);

    shared_ptr<OpenAccountServletHandler> handler(new OpenAccountServletHandler(logId));
    shared_ptr<TProcessor> processor(new OpenAccountServletProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    ::BossMonitorClient client;
    BossData::BossMonitor data;
    data.id=getpid();
    data.name=basename(argv[0]);
    data.status="Active";
    data.ip=CONF_PARSER_GET_VAL("OpenAccount", "ip");;
    data.port=port;
    client.subscribe(data);

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
    return 0;
}

