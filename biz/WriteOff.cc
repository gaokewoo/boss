#include "WriteOff.hh"
#include "libconfparser/confparser.hpp"
#include "BillInterface.hh"
#include "Acct.hh"
#include "Dual.hh"

WriteOff::WriteOff(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "WriteOff::WriteOff start");

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

    LOG_DEBUG(m_logId, "WriteOff::WriteOff end");
}

WriteOff::~WriteOff()
{
    LOG_DEBUG(m_logId, "WriteOff::~WriteOff start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "WriteOff::~WriteOff end");
}

void WriteOff::doBiz()
{
    LOG_DEBUG(m_logId, "WriteOff::doBiz start");

    BillInterface m_bill_interface;
    m_bill_interface.setConnection(m_db->getConnection());
    vector<ST_BILL_INTERFACE> v_bill_interface = m_bill_interface.loadAllData();

    vector<ST_BILL_INTERFACE>::iterator it;
    for(it=v_bill_interface.begin();
                it != v_bill_interface.end(); it++)
    {
        long payment_id = (*it).m_payment_id;
        long acct_id = (*it).m_acct_id;
        LOG_INFO(m_logId, "WriteOff::doBiz get acct info by acct_id:"<<acct_id);
        Acct m_acct;
        m_acct.setConnection(m_db->getConnection());
        ST_ACCT acct_data = m_acct.getAcctByAcctId(acct_id);
        LOG_INFO(m_logId, "WriteOff::doBiz acct_id:"<<acct_id<<" owe_min_ym:"<<acct_data.m_owe_min_ym<<" owe_fee:"<<acct_data.m_owe_fee);

        Dual dual;
        dual.setConnection(m_db->getConnection());
        string ym = dual.getSysDateYYYYMM();

        long owe_min_ym = acct_data.m_owe_min_ym;
        while(owe_min_ym <= atol(ym.c_str()))
        {

            owe_min_ym++;
        }


        LOG_INFO(m_logId, "WriteOff::doBiz mv from bill_interface to bill_interface_his for payment_id:"<<payment_id);
        BillInterface m_bill_interface;
        //m_bill_interface.deleteBillInterfaceByPaymentId(payment_id);
    }
    LOG_DEBUG(m_logId, "WriteOff::doBiz end");

}


