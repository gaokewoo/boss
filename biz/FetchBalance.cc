#include "FetchBalance.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"
#include "ServAcct.hh"
#include "Acct.hh"

FetchBalance::FetchBalance(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "FetchBalance::FetchBalance start");

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

    LOG_DEBUG(m_logId, "FetchBalance::FetchBalance end");
}

FetchBalance::~FetchBalance()
{
    LOG_DEBUG(m_logId, "FetchBalance::~FetchBalance start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "FetchBalance::~FetchBalance end");
}

double FetchBalance::doBiz(string nbr)
{
    LOG_DEBUG(m_logId, "FetchBalance::doBiz start");

    try
    {
        if(nbr == "")
        {
            LOG_ERROR(m_logId,"Phone number should not be empty.");

            return 0;
        }

        //get serv_identification info
        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());
        ST_SERV_IDENTIFICATION serv_ident_info;
        LOG_INFO(m_logId, "FetchBalance::doBiz input nbr:"<<nbr);
        serv_ident_info = m_serv_ident.getServIdentInfoByNBR(nbr);
        long serv_id = m_serv_ident.serv_identification.m_serv_id;

        LOG_INFO(m_logId, "FetchBalance::doBiz get serv_acct info");
        ServAcct m_serv_acct;
        m_serv_acct.setConnection(m_db->getConnection());
        ST_SERV_ACCT serv_acct_data = m_serv_acct.getServAcctByServId(serv_id);
        long acct_id = serv_acct_data.m_acct_id;

        LOG_INFO(m_logId, "FetchBalance::doBiz get acct info");
        Acct m_acct;
        m_acct.setConnection(m_db->getConnection());
        ST_ACCT acct_data = m_acct.getAcctByAcctId(acct_id);
        LOG_INFO(m_logId, "FetchBalance::doBiz acct_id:"<<acct_id<<" old owe_min_ym:"<<acct_data.m_owe_min_ym<<" old owe_fee:"<<acct_data.m_owe_fee);

        LOG_DEBUG(m_logId, "FetchBalance::doBiz end");

        return acct_data.m_owe_fee;
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "FetchBalance::doBiz error");
        m_db->rollback();
    }

}


