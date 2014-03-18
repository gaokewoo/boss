#include "FetchNbr.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"

FetchNbr::FetchNbr(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "FetchNbr::FetchNbr start");

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

    LOG_DEBUG(m_logId, "FetchNbr::FetchNbr end");
}

FetchNbr::~FetchNbr()
{
    LOG_DEBUG(m_logId, "FetchNbr::~FetchNbr start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "FetchNbr::~FetchNbr end");
}

string FetchNbr::doBiz()
{
    LOG_DEBUG(m_logId, "FetchNbr::doBiz start");

    //get serv_identification info
    ServIdentification m_serv_ident;
    m_serv_ident.setConnection(m_db->getConnection());
    ST_SERV_IDENTIFICATION serv_ident_info;
    serv_ident_info = m_serv_ident.getRandomServIdentInfo();
    LOG_INFO(m_logId, "FetchNbr::doBiz the random nbr:"<<serv_ident_info.m_acc_nbr);

    LOG_DEBUG(m_logId, "FetchNbr::doBiz end");

    return serv_ident_info.m_acc_nbr;
}

