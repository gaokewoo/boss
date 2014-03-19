#include "PayFee.hh"
#include "libconfparser/confparser.hpp"
#include "ServIdentification.hh"

PayFee::PayFee(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "PayFee::PayFee start");

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

    loadConfigData();

    LOG_DEBUG(m_logId, "PayFee::PayFee end");
}

PayFee::~PayFee()
{
    LOG_DEBUG(m_logId, "PayFee::~PayFee start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "PayFee::~PayFee end");
}

void PayFee::loadConfigData()
{
    LOG_DEBUG(m_logId, "PayFee::loadConfigData start");
    PaymentMethod m_payment_method;
    BalanceSourceType m_balance_source_type;
    BalanceType m_balance_type;
    BillingCycle m_billing_cycle;
    Staff m_staff;
    Region m_region;

    m_payment_method.setConnection(m_db->getConnection());
    m_balance_source_type.setConnection(m_db->getConnection());
    m_balance_type.setConnection(m_db->getConnection());
    m_billing_cycle.setConnection(m_db->getConnection());
    m_staff.setConnection(m_db->getConnection());
    m_region.setConnection(m_db->getConnection());

    v_payment_method = m_payment_method.loadAllData();
    v_balance_source_type = m_balance_source_type.loadAllData();
    v_balance_type = m_balance_type.loadAllData();
    v_billing_cycle = m_billing_cycle.loadAllData();
    v_staff = m_staff.loadAllData();
    v_region = m_region.loadAllData();
    LOG_DEBUG(m_logId, "PayFee::loadConfigData end");
}

void PayFee::doBiz(PayFeeData & data)
{
    try
    {
        LOG_DEBUG(m_logId, "PayFee::doBiz start");

        ST_PAYMENT_METHOD l_payment_method = v_payment_method[rand()%v_payment_method.size()];
        long payment_method = l_payment_method.m_payment_method;
        long balance_type_id = l_payment_method.m_balance_type_id;
        long balance_source_id = v_balance_source_type[rand()%v_balance_source_type.size()].m_balance_source_id;
        long billing_cycle_type_id = v_billing_cycle[rand()%v_billing_cycle.size()].m_billing_cycle_type_id;
        long staff_id = v_staff[rand()%v_staff.size()].m_staff_id;
        long region_id = v_region[rand()%v_region.size()].m_region_id;

        LOG_INFO(m_logId, "Payment_method:"<<payment_method);
        LOG_INFO(m_logId, "Balance_type_id:"<<balance_type_id);
        LOG_INFO(m_logId, "Balance_source_id:"<<balance_source_id);
        LOG_INFO(m_logId, "Billing_cycle_type_id:"<<billing_cycle_type_id);
        LOG_INFO(m_logId, "Staff_id :"<<staff_id);
        LOG_INFO(m_logId, "Region_id:"<<region_id);

        //get serv_identification info
        ServIdentification m_serv_ident;
        m_serv_ident.setConnection(m_db->getConnection());
        ST_SERV_IDENTIFICATION serv_ident_info;
        if(data.nbr != "")
        {
            LOG_INFO(m_logId, "PayFee::doBiz input nbr:"<<data.nbr);
            serv_ident_info = m_serv_ident.getServIdentInfoByNBR(data.nbr);
        }
        else
        {
            LOG_INFO(m_logId, "PayFee::doBiz no input nbr, system will select a random nbr to do payment.");
            serv_ident_info = m_serv_ident.getRandomServIdentInfo();
            LOG_INFO(m_logId, "PayFee::doBiz the random nbr:"<<serv_ident_info.m_acc_nbr);

        }
        LOG_DEBUG(m_logId, "PayFee::doBiz end");
    }
    catch(...)
    {
        LOG_ERROR(m_logId, "PayFee::doBiz error");
        m_db->rollback();
    }
}


