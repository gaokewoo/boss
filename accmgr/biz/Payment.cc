#include "Payment.hh"
#include "libconfparser/confparser.hpp"

Payment::Payment(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "Payment::Payment start");

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

    LOG_DEBUG(m_logId, "Payment::Payment end");
}

Payment::~Payment()
{
    LOG_DEBUG(m_logId, "Payment::~Payment start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "Payment::~Payment end");
}

void Payment::doBiz(PaymentData & data)
{
    LOG_DEBUG(m_logId, "Payment::~Payment start");
    LOG_DEBUG(m_logId, "Payment::~Payment end");
}


