#include "FetchBalance.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"
#include "ServAcct.hh"
#include "Acct.hh"
#include "AcctBalance.hh"
#include "AcctItem.hh"
#include "Dual.hh"

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

        LOG_INFO(m_logId, "FetchBalance::doBiz get acct balance info by acct_id:"<<acct_id);
        AcctBalance m_acct_balance;
        m_acct_balance.setConnection(m_db->getConnection());
        vector<ST_ACCT_BALANCE> v_acct_balance(m_acct_balance.getAcctBalanceByAcctId(acct_id));

        long total_balance=0;
        for(vector<ST_ACCT_BALANCE>::iterator it=v_acct_balance.begin();
                    it != v_acct_balance.end(); it++)
        {
            total_balance = (*it).m_balance;
        }

        long owe_min_ym = acct_data.m_owe_min_ym;

        Dual dual;
        dual.setConnection(m_db->getConnection());
        string ym = dual.getSysDateYYYYMM();
        LOG_INFO(m_logId, "FetchBalance::doBiz current ym:"<<ym);

        long total_amount=0;
        AcctItem m_acct_item;
        m_acct_item.setConnection(m_db->getConnection());
        while(owe_min_ym <= atol(ym.c_str()))
        {
            LOG_INFO(m_logId, "FetchBalance::doBiz get acct_item info by acct_id:"<<acct_id<<" and owe_min_ym:"<<owe_min_ym);

            char tmp[30];
            sprintf(tmp,"%ld",owe_min_ym);
            m_acct_item.setYM(tmp);
            vector<ST_ACCT_ITEM> v_acct_item(m_acct_item.getAcctItemByAcctId(acct_id));

            for(vector<ST_ACCT_ITEM>::iterator it=v_acct_item.begin();
                        it != v_acct_item.end(); it++)
            {
                total_amount += (*it).m_amount;
            }

            owe_min_ym=getNextYm(owe_min_ym);
        }

        if (total_amount != acct_data.m_owe_fee)
        {
            LOG_WARN(m_logId, "FetchBalance::doBiz update acct by acct_id:"<<acct_id<<" actual owe fee;"<<total_amount<<" but store value is:"<<acct_data.m_owe_fee);
            m_acct.setAcctOweMinYMAndOweFee(acct_id,acct_data.m_owe_min_ym,total_amount);
        }
        LOG_DEBUG(m_logId, "FetchBalance::doBiz end");

        m_db->commit();

        return (total_balance-total_amount)/100;
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "FetchBalance::doBiz error");
        m_db->rollback();
    }

}

long FetchBalance::getNextYm(long owe_min_ym)
{
    long year = owe_min_ym/100;
    long month = owe_min_ym%100;

    if(++month >= 13)
    {
        year++;
        month-=12;
    }

    return year*100+month;
}



