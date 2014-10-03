#include "CreditControl.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"
#include "Serv.hh"
#include "ServStateAttr.hh"
#include "BillingCycle.hh"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "gen-cpp/FetchBalance.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

CreditControl::CreditControl(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "CreditControl::CreditControl start");

    LOG_DEBUG(logId, "Parse boss.cfg");
    CONF_PARSER_SIMPLE_INIT("../conf/boss.cfg");
    string db_user = CONF_PARSER_GET_VAL("DB", "user");
    string db_passwd = CONF_PARSER_GET_VAL("DB", "passwd");
    string db_instance = CONF_PARSER_GET_VAL("DB", "instance");
    LOG_DEBUG(logId, "DB User:"<<db_user);
    LOG_DEBUG(logId, "DB Passwd:"<<db_passwd);
    LOG_DEBUG(logId, "DB Instance:"<<db_instance);

    m_db = new OracleDB(db_user,db_passwd,db_instance);
    m_db->connectToDB();

    LOG_DEBUG(m_logId, "CreditControl::CreditControl end");
}

CreditControl::~CreditControl()
{
    LOG_DEBUG(m_logId, "CreditControl::~CreditControl start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "CreditControl::~CreditControl end");
}

void CreditControl::doBiz(string acc_nbr)
{
    LOG_DEBUG(m_logId, "CreditControl::doBiz start");

    int fetch_balance_port = CONF_PARSER_GET_NUM_VAL("FetchBalance", "port");
    const char* fetch_balance_ip = CONF_PARSER_GET_VAL("FetchBalance", "ip");

    shared_ptr<TTransport> t_socket(new TSocket(fetch_balance_ip, fetch_balance_port));

    shared_ptr<TTransport> transport(new TBufferedTransport(t_socket));

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    BossInterface::FetchBalanceClient  client(protocol);

    try {  
        transport->open();
        double balance = client.fetchBalance(acc_nbr);
        LOG_INFO(m_logId, "The balance of "<<acc_nbr<<" is "<<balance);
        transport->close();

        //get serv_identification info
        LOG_INFO(m_logId, "Get serv identification for"<<acc_nbr);
        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());
        ST_SERV_IDENTIFICATION serv_ident_info;
        serv_ident_info = m_serv_ident.getServIdentInfoByNBR(acc_nbr);

        long serv_id = serv_ident_info.m_serv_id;

        Serv m_serv;
        m_serv.setConnection(m_db->getConnection());
        ST_SERV serv;
        serv = m_serv.getServByServId(serv_id);
        
        BillingCycle m_billing_cycle;
        m_billing_cycle.setConnection(m_db->getConnection());
        vector<ST_BILLING_CYCLE> v_billing_cycle = m_billing_cycle.getEffectiveBillingCycle();
        long billing_cycle_type_id = 0;
        if (!v_billing_cycle.empty())
        {
            billing_cycle_type_id = v_billing_cycle[0].m_billing_cycle_type_id;
        }

        if((int)(balance*100)>=0 && serv.m_state != "A")
        {
            LOG_INFO(m_logId, acc_nbr<<" old state:"<<serv.m_state<<" balance:"<<balance<<" state change to A");
            m_serv.updateStateInServByServId(serv_id,"A");

            ServStateAttr m_serv_state_attr;
            m_serv_state_attr.setConnection(m_db->getConnection());
            m_serv_state_attr.serv_state_attr.m_serv_id=serv_id;
            m_serv_state_attr.serv_state_attr.m_billing_cycle_type_id=billing_cycle_type_id;
            m_serv_state_attr.serv_state_attr.m_agreement_id=serv.m_agreement_id;
            m_serv_state_attr.serv_state_attr.m_owe_business_type_id=0;
            m_serv_state_attr.serv_state_attr.m_state="A";
            m_serv_state_attr.insertData();
        }
        else if((int)(balance*100)<0 && serv.m_state == "A")
        {
            LOG_INFO(m_logId, acc_nbr<<" old state:"<<serv.m_state<<" balance:"<<balance<<" state change to C");
            m_serv.updateStateInServByServId(serv_id,"C");

            ServStateAttr m_serv_state_attr;
            m_serv_state_attr.serv_state_attr.m_serv_id=serv_id;
            m_serv_state_attr.serv_state_attr.m_billing_cycle_type_id=billing_cycle_type_id;
            m_serv_state_attr.serv_state_attr.m_agreement_id=serv.m_agreement_id;
            m_serv_state_attr.serv_state_attr.m_owe_business_type_id=0;
            m_serv_state_attr.serv_state_attr.m_state="C";
            m_serv_state_attr.insertData();
        }
        else
        {
            LOG_INFO(m_logId, acc_nbr<<" old state:"<<serv.m_state<<" balance:"<<balance<<" no need to change state");
        }

        m_db->commit();

    } catch (TException &tx) {
        transport->close();   
        LOG_ERROR(m_logId, acc_nbr<<" ERROR, reason:"<<tx.what());
        m_db->rollback();
    }catch(...)
    {
        LOG_ERROR(m_logId, acc_nbr<<" ERROR");
        m_db->rollback();
        exit(-1);
    }

    LOG_DEBUG(m_logId, "CreditControl::doBiz end");
}


