#include "OpenAccount.hh"

OpenAccount::OpenAccount(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "OpenAccount::OpenAccount start");

    m_db = new OracleDB();
    m_db->connectToDB();

    m_seq.setConnection(m_db->getConnection());

    m_serv.setConnection(m_db->getConnection());

    m_cust.setConnection(m_db->getConnection());

    m_acct.setConnection(m_db->getConnection());
    LOG_DEBUG(m_logId, "OpenAccount::OpenAccount end");
}

OpenAccount::~OpenAccount()
{
    LOG_DEBUG(m_logId, "OpenAccount::~OpenAccount start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "OpenAccount::~OpenAccount end");
}

void OpenAccount::doBiz()
{

    LOG_DEBUG(m_logId, "OpenAccount::doBiz start");
    long region_id = m_seq.getRegionId();
    long agreement_id = m_seq.getAgreementId();
    long product_id = m_seq.getScardvcsn();
    long billing_cycle_type_id = m_seq.getScardvcsn();
    long band_id = m_seq.getScardvcsn();
    long party_id = m_seq.getPartyId();

    LOG_INFO(m_logId, "region_id :"<<region_id);
    LOG_INFO(m_logId, "agreement_id :"<<agreement_id );
    LOG_INFO(m_logId, "product_id :"<<product_id );
    LOG_INFO(m_logId, "billing_cycle_type_id :"<<billing_cycle_type_id );
    LOG_INFO(m_logId, "band_id :"<<band_id );
    LOG_INFO(m_logId, "party_id :"<<party_id );
    Name name;
    for(int i=0;i<50;i++)
    {
        long serv_id = m_seq.getServId();
        long acct_id = m_seq.getAcctId();
        long cust_id = m_seq.getCustId();
        long family_id = m_seq.getScardvcsn();
        long cust_location= m_seq.getScardvcsn();

        string my_name=name.getName();

        LOG_INFO(m_logId, "["<<i<<"]"<<"Name:"<<my_name);
        LOG_INFO(m_logId, "["<<i<<"]"<<"serv_id :"<<serv_id );
        LOG_INFO(m_logId, "["<<i<<"]"<<"acct_id :"<<acct_id );
        LOG_INFO(m_logId, "["<<i<<"]"<<"cust_id :"<<cust_id );
        LOG_INFO(m_logId, "["<<i<<"]"<<"family_id :"<<family_id );
        LOG_INFO(m_logId, "["<<i<<"]"<<"cust_location:"<<cust_location);

        m_serv.serv.m_serv_id=serv_id;
        m_serv.serv.m_agreement_id=agreement_id;
        m_serv.serv.m_cust_id=acct_id;
        m_serv.serv.m_product_id=product_id;
        m_serv.serv.m_billing_cycle_type_id=billing_cycle_type_id;
        m_serv.serv.m_product_family_id=family_id;
        m_serv.serv.m_state="0";
        m_serv.serv.m_region_id=region_id;
        m_serv.serv.m_band_id=band_id;
        m_serv.insertData();

        m_cust.cust.m_cust_id=cust_id;
        m_cust.cust.m_party_role_id=party_id;
        m_cust.cust.m_cust_name=my_name;
        m_cust.cust.m_cust_type="01";
        m_cust.cust.m_cust_location=cust_location;
        m_cust.cust.m_is_vip="N";
        m_cust.cust.m_cust_code="A";
        m_cust.cust.m_state="0";
        m_cust.insertData();


        m_acct.acct.m_acct_id=acct_id;
        m_acct.acct.m_cust_id=cust_id;
        m_acct.acct.m_acct_name=my_name;
        m_acct.acct.m_address_id=m_seq.getAddressId();
        m_acct.acct.m_state="0";
        m_acct.acct.m_acct_pwd="&8re@31";
        m_acct.acct.m_region_id=region_id;
        m_acct.acct.m_acct_type="10";
        m_acct.acct.m_owe_min_ym=201401;
        m_acct.acct.m_owe_fee=0;
        m_acct.insertData();

        if(i%200==0) m_db->commit();
    }
    m_db->commit();
    LOG_DEBUG(m_logId, "OpenAccount::doBiz end");
}

