#include "OpenAccount.hh"
#include "libconfparser/confparser.hpp"

OpenAccount::OpenAccount(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "OpenAccount::OpenAccount start");
    srand( (unsigned)time( NULL ) ); 

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

    m_seq.setConnection(m_db->getConnection());

    m_serv.setConnection(m_db->getConnection());

    m_cust.setConnection(m_db->getConnection());

    m_acct.setConnection(m_db->getConnection());

    m_cust_contact_info.setConnection(m_db->getConnection());

    m_cust_ident.setConnection(m_db->getConnection());

    m_agreement.setConnection(m_db->getConnection());

    m_serv_ident.setConnection(m_db->getConnection());

    m_serv_location.setConnection(m_db->getConnection());

    m_serv_state_attr.setConnection(m_db->getConnection());

    m_serv_billing_mode.setConnection(m_db->getConnection());

    m_staff_opr.setConnection(m_db->getConnection());

    LOG_DEBUG(m_logId, "OpenAccount::OpenAccount end");
}

OpenAccount::~OpenAccount()
{
    LOG_DEBUG(m_logId, "OpenAccount::~OpenAccount start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "OpenAccount::~OpenAccount end");
}

void OpenAccount::loadConfigData()
{
    LOG_DEBUG(m_logId, "OpenAccount::loadConfigData start");
    CertificateType m_certificate_type;
    AcctType m_acct_type;
    Staff m_staff;
    Region m_region;
    BillingRegion m_billing_region;
    Address m_address;
    BillingCycle m_billing_cycle;
    ServStateDesc m_serv_state_desc;

    m_certificate_type.setConnection(m_db->getConnection());
    m_acct_type.setConnection(m_db->getConnection());
    m_staff.setConnection(m_db->getConnection());
    m_region.setConnection(m_db->getConnection());
    m_billing_region.setConnection(m_db->getConnection());
    m_address.setConnection(m_db->getConnection());
    m_billing_cycle.setConnection(m_db->getConnection());
    m_serv_state_desc.setConnection(m_db->getConnection());

    v_certificate_type=m_certificate_type.loadAllData();
    v_acct_type=m_acct_type.loadAllData();
    v_staff=m_staff.loadAllData();
    v_region=m_region.loadAllData();
    v_billing_region=m_billing_region.loadAllData();
    v_address=m_address.loadAllData();
    v_billing_cycle=m_billing_cycle.loadAllData();
    v_serv_state_desc=m_serv_state_desc.loadAllData();
    LOG_DEBUG(m_logId, "OpenAccount::loadConfigData end");
}

void OpenAccount::doBiz()
{

    try
    {
        LOG_DEBUG(m_logId, "OpenAccount::doBiz start");
        long region_id = v_region[rand()%v_region.size()].m_region_id;
        long product_id = 0;
        long billing_cycle_type_id = v_billing_cycle[rand()%v_billing_cycle.size()].m_billing_cycle_type_id;
        long address_id = v_address[rand()%v_address.size()].m_address_id;
        string certificate_type = v_certificate_type[rand()%v_certificate_type.size()].m_certificate_type;
        long staff_id = v_staff[rand()%v_staff.size()].m_staff_id;
        string serv_state;
        vector<ST_SERV_STATE_DESC>::iterator it;
        for(it=v_serv_state_desc.begin();it!=v_serv_state_desc.end();it++)
        {
            if(it->m_region_id == region_id)
              serv_state = it->m_state;
        }

        LOG_INFO(m_logId, "Region_id:"<<region_id);
        LOG_INFO(m_logId, "Product_id:"<<product_id);
        LOG_INFO(m_logId, "Billing_cycle_type_id:"<<billing_cycle_type_id);
        LOG_INFO(m_logId, "Address_id:"<<address_id);
        LOG_INFO(m_logId, "Certificate_type:"<<certificate_type);
        LOG_INFO(m_logId, "Staff_id :"<<staff_id);
        LOG_INFO(m_logId, "Serv_state:"<<serv_state);

        RandomInfo rand_info=generator.getRandomInfo();

        LOG_INFO(m_logId, "Id:"<<rand_info.id);
        LOG_INFO(m_logId, "Name:"<<rand_info.name);
        LOG_INFO(m_logId, "Gender:"<<rand_info.gender);
        LOG_INFO(m_logId, "Addr:"<<rand_info.addr);
        LOG_INFO(m_logId, "Region_nbr:"<<rand_info.region_nbr);
        LOG_INFO(m_logId, "Fax_nbr:"<<rand_info.fax_nbr);
        LOG_INFO(m_logId, "Tel_nbr:"<<rand_info.tel_nbr);
        LOG_INFO(m_logId, "Post_code:"<<rand_info.post_code);
        LOG_INFO(m_logId, "Email_addr:"<<rand_info.email_addr);

        long cust_id = m_seq.getCustId();
        long agreement_id = m_seq.getAgreementId();

        LOG_INFO(m_logId, "Cust_id :"<<cust_id );

        m_cust.cust.m_cust_id=cust_id;
        m_cust.cust.m_party_role_id=0;
        m_cust.cust.m_cust_name=rand_info.name;
        m_cust.cust.m_cust_type="01";
        m_cust.cust.m_cust_location=region_id;
        m_cust.cust.m_is_vip="N";
        m_cust.cust.m_cust_code="A";
        m_cust.cust.m_state="0";
        m_cust.insertData();

        m_cust_contact_info.cust_contact_info.m_cust_id=cust_id;
        m_cust_contact_info.cust_contact_info.m_agreement_id=agreement_id;
        m_cust_contact_info.cust_contact_info.m_contact_name=rand_info.name;
        m_cust_contact_info.cust_contact_info.m_contact_gender=rand_info.gender;
        m_cust_contact_info.cust_contact_info.m_contact_addr=rand_info.addr;
        m_cust_contact_info.cust_contact_info.m_contact_company=rand_info.addr;
        m_cust_contact_info.cust_contact_info.m_duty_desc="无";
        m_cust_contact_info.cust_contact_info.m_telephone=rand_info.tel_nbr;
        m_cust_contact_info.cust_contact_info.m_mobile=generator.getNbr();
        m_cust_contact_info.cust_contact_info.m_post_code=rand_info.post_code;
        m_cust_contact_info.cust_contact_info.m_email_address=rand_info.email_addr;
        m_cust_contact_info.cust_contact_info.m_fax=rand_info.fax_nbr;
        m_cust_contact_info.cust_contact_info.m_comments="无";
        m_cust_contact_info.insertData();

        m_cust_ident.cust_identification.m_cust_id=cust_id;
        m_cust_ident.cust_identification.m_agreement_id=agreement_id;
        m_cust_ident.cust_identification.m_certificate_type=certificate_type ;
        m_cust_ident.cust_identification.m_certificate_no=rand_info.id;
        m_cust_ident.cust_identification.m_attest_type="A0";
        m_cust_ident.cust_identification.m_attest_passwd="123456";
        m_cust_ident.cust_identification.m_secrecy_level="0";
        m_cust_ident.insertData();

        m_agreement.agreement.m_agreement_id=agreement_id;
        m_agreement.agreement.m_cust_id=cust_id;
        m_agreement.agreement.m_agreement_type="0A";
        m_agreement.agreement.m_accept_staff_id=staff_id;
        m_agreement.agreement.m_state="0A";
        m_agreement.agreement.m_comments="无";
        m_agreement.insertData();

        long acct_id = m_seq.getAcctId();
        LOG_INFO(m_logId, "Acct_id :"<<acct_id );
        m_acct.acct.m_acct_id=acct_id;
        m_acct.acct.m_cust_id=cust_id;
        m_acct.acct.m_acct_name=rand_info.name;
        m_acct.acct.m_address_id=address_id;
        m_acct.acct.m_state="0";
        m_acct.acct.m_acct_pwd="&8re@31";
        m_acct.acct.m_region_id=region_id;
        m_acct.acct.m_acct_type="10";
        m_acct.acct.m_owe_min_ym=201401;
        m_acct.acct.m_owe_fee=0;
        m_acct.insertData();

        long serv_id = m_seq.getServId();
        LOG_INFO(m_logId, "Serv_id :"<<serv_id );
        m_serv.serv.m_serv_id=serv_id;
        m_serv.serv.m_agreement_id=agreement_id;
        m_serv.serv.m_cust_id=cust_id;
        m_serv.serv.m_product_id=product_id;
        m_serv.serv.m_billing_cycle_type_id=billing_cycle_type_id;
        m_serv.serv.m_product_family_id=0;
        m_serv.serv.m_state=serv_state;
        m_serv.serv.m_region_id=region_id;
        m_serv.serv.m_band_id=0;
        m_serv.insertData();

        string acc_nbr = generator.getNbr();
        LOG_INFO(m_logId, "Acc_nbr:"<<acc_nbr);
        m_serv_ident.serv_identification.m_serv_id = serv_id;
        m_serv_ident.serv_identification.m_agreement_id = agreement_id;
        m_serv_ident.serv_identification.m_acc_nbr = acc_nbr; 
        m_serv_ident.insertData();

        m_serv_location.serv_location.m_serv_id=serv_id;
        m_serv_location.serv_location.m_agreement_id=agreement_id;
        m_serv_location.serv_location.m_address_id=address_id;
        m_serv_location.serv_location.m_bureau_id=region_id;
        m_serv_location.serv_location.m_exchange_id=region_id;
        m_serv_location.serv_location.m_stat_region_id=region_id;
        m_serv_location.insertData();

        m_serv_state_attr.serv_state_attr.m_serv_id=serv_id;
        m_serv_state_attr.serv_state_attr.m_billing_cycle_type_id=billing_cycle_type_id;
        m_serv_state_attr.serv_state_attr.m_agreement_id=agreement_id;
        m_serv_state_attr.serv_state_attr.m_owe_business_type_id=0;
        m_serv_state_attr.serv_state_attr.m_state=serv_state;
        m_serv_state_attr.insertData();

        m_serv_billing_mode.serv_billing_mode.m_serv_id = serv_id;
        m_serv_billing_mode.serv_billing_mode.m_agreement_id = agreement_id;
        m_serv_billing_mode.serv_billing_mode.m_billing_mode = "A";
        m_serv_billing_mode.insertData();

        m_staff_opr.staff_opr.m_login_accept = m_seq.getScardvcsn();
        m_staff_opr.staff_opr.m_op_code = "KH";
        m_staff_opr.staff_opr.m_payment_method = 100;
        m_staff_opr.staff_opr.m_pay_money = 0;
        m_staff_opr.staff_opr.m_band_id = 111;
        m_staff_opr.staff_opr.m_serv_id = serv_id;
        m_staff_opr.staff_opr.m_acc_nbr = acc_nbr;
        m_staff_opr.staff_opr.m_op_note = "开户";
        m_staff_opr.staff_opr.m_ip_addr = "127.0.0.1";
        m_staff_opr.staff_opr.m_staff_org_id = region_id;
        m_staff_opr.staff_opr.m_nbr_org_id = region_id;
        m_staff_opr.staff_opr.m_staff_id = staff_id;
        m_staff_opr.insertData();

        m_db->commit();
        LOG_DEBUG(m_logId, "OpenAccount::doBiz end");
    }
    catch(...)
    {
        m_db->rollback();
    }
}

