#include "ConfigData.hh"
#include "libconfparser/confparser.hpp"

ConfigData::ConfigData(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "ConfigData::ConfigData start");

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

    m_seq.setConnection(m_db->getConnection());

    LOG_DEBUG(m_logId, "ConfigData::ConfigData end");
}

ConfigData::~ConfigData()
{
    LOG_DEBUG(m_logId, "ConfigData::~ConfigData start");
    m_db->disConnectFromDB();
    LOG_DEBUG(m_logId, "ConfigData::~ConfigData end");
}

void ConfigData::configCertificateType()
{
    LOG_DEBUG(m_logId, "ConfigData::configCertificateType begin");
    m_certificate_type.setConnection(m_db->getConnection());

    m_certificate_type.emptyData();

    m_certificate_type.certificate_type.m_certificate_type="C01";
    m_certificate_type.certificate_type.m_certificate_type_name="身份证";
    m_certificate_type.certificate_type.m_certificate_length=18;
    m_certificate_type.insertData();

    m_certificate_type.certificate_type.m_certificate_type="C02";
    m_certificate_type.certificate_type.m_certificate_type_name="学生证";
    m_certificate_type.certificate_type.m_certificate_length=9;
    m_certificate_type.insertData();

    m_certificate_type.certificate_type.m_certificate_type="C03";
    m_certificate_type.certificate_type.m_certificate_type_name="驾驶证";
    m_certificate_type.certificate_type.m_certificate_length=20;
    m_certificate_type.insertData();

    m_certificate_type.certificate_type.m_certificate_type="C04";
    m_certificate_type.certificate_type.m_certificate_type_name="军官证";
    m_certificate_type.certificate_type.m_certificate_length=10;
    m_certificate_type.insertData();
    LOG_DEBUG(m_logId, "ConfigData::configCertificateType end");
}

void ConfigData::configAcctType()
{
    LOG_DEBUG(m_logId, "ConfigData::configAcctType begin");
    m_acct_type.setConnection(m_db->getConnection());

    m_acct_type.emptyData();

    m_acct_type.acct_type.m_acct_type="A01";
    m_acct_type.acct_type.m_flag=0;
    m_acct_type.acct_type.m_type_name="个人账户";
    m_acct_type.insertData();

    m_acct_type.acct_type.m_acct_type="A02";
    m_acct_type.acct_type.m_flag=0;
    m_acct_type.acct_type.m_type_name="家庭账户";
    m_acct_type.insertData();

    m_acct_type.acct_type.m_acct_type="A03";
    m_acct_type.acct_type.m_flag=1;
    m_acct_type.acct_type.m_type_name="企业账户";
    m_acct_type.insertData();

    LOG_DEBUG(m_logId, "ConfigData::configAcctType end");
}

void ConfigData::configPrivilegeAndStaff()
{
    LOG_DEBUG(m_logId, "ConfigData::configPrivilegeAndStaff begin");
    m_privilege.setConnection(m_db->getConnection());
    m_staff.setConnection(m_db->getConnection());
    m_staff_privilege.setConnection(m_db->getConnection());

    m_privilege.emptyData();
    m_staff.emptyData();
    m_staff_privilege.emptyData();

    long privilege_id;
    long staff_id;

    privilege_id = m_seq.getPrivilegeId();
    m_privilege.privilege.m_privilege_id=privilege_id;
    m_privilege.privilege.m_parent_privilegeid=0;
    m_privilege.privilege.m_privilege_name="DBA";
    m_privilege.privilege.m_privilege_type="P00";
    m_privilege.privilege.m_app_code="000";
    m_privilege.privilege.m_privilege_desc="具有全局权限";
    m_privilege.insertData();

    staff_id = m_seq.getPrivilegeId();
    m_staff.staff.m_staff_id=staff_id;
    m_staff.staff.m_operate_org_id=0;
    m_staff.staff.m_staff_code="S00001";
    m_staff.staff.m_passwd="123456";
    m_staff.staff.m_scope_level="0";
    m_staff.staff.m_staff_desc="管理员";
    m_staff.staff.m_parent_partyroleid=0;
    m_staff.staff.m_staff_type="0";
    m_staff.insertData();

    m_staff_privilege.staff_privilege.m_staff_id = staff_id;
    m_staff_privilege.staff_privilege.m_privilege_id = privilege_id;
    m_staff_privilege.insertData();

    privilege_id = m_seq.getPrivilegeId();
    m_privilege.privilege.m_privilege_id=privilege_id;
    m_privilege.privilege.m_parent_privilegeid=0;
    m_privilege.privilege.m_privilege_name="PAY";
    m_privilege.privilege.m_privilege_type="P01";
    m_privilege.privilege.m_app_code="001";
    m_privilege.privilege.m_privilege_desc="具有缴费权限";
    m_privilege.insertData();

    staff_id = m_seq.getPrivilegeId();
    m_staff.staff.m_staff_id=staff_id;
    m_staff.staff.m_operate_org_id=0;
    m_staff.staff.m_staff_code="S00002";
    m_staff.staff.m_passwd="123456";
    m_staff.staff.m_scope_level="1";
    m_staff.staff.m_staff_desc="普通员工";
    m_staff.staff.m_parent_partyroleid=0;
    m_staff.staff.m_staff_type="1";
    m_staff.insertData();

    m_staff_privilege.staff_privilege.m_staff_id = staff_id;
    m_staff_privilege.staff_privilege.m_privilege_id = privilege_id;
    m_staff_privilege.insertData();

    privilege_id = m_seq.getPrivilegeId();
    m_privilege.privilege.m_privilege_id=privilege_id;
    m_privilege.privilege.m_parent_privilegeid=0;
    m_privilege.privilege.m_privilege_name="QUERY";
    m_privilege.privilege.m_privilege_type="P02";
    m_privilege.privilege.m_app_code="002";
    m_privilege.privilege.m_privilege_desc="具有查询权限";
    m_privilege.insertData();

    staff_id = m_seq.getPrivilegeId();
    m_staff.staff.m_staff_id=staff_id;
    m_staff.staff.m_operate_org_id=0;
    m_staff.staff.m_staff_code="S00003";
    m_staff.staff.m_passwd="123456";
    m_staff.staff.m_scope_level="1";
    m_staff.staff.m_staff_desc="普通员工";
    m_staff.staff.m_parent_partyroleid=0;
    m_staff.staff.m_staff_type="1";
    m_staff.insertData();

    m_staff_privilege.staff_privilege.m_staff_id = staff_id;
    m_staff_privilege.staff_privilege.m_privilege_id = privilege_id;
    m_staff_privilege.insertData();

    LOG_DEBUG(m_logId, "ConfigData::configPrivilegeAndStaff end");
}

void ConfigData::configRegionAndBillingRegion()
{
    LOG_DEBUG(m_logId, "ConfigData::configRegionAndBillingRegion begin");
    m_region.setConnection(m_db->getConnection());
    m_billing_region.setConnection(m_db->getConnection());

    m_region.emptyData();
    m_billing_region.emptyData();

    long region_id;
    for(int i=0;i<17;i++)
    {
        char code[5];
        sprintf(code,"S%02d",i+1);
        string name;
        switch(i+1)
        {
            case 1:name="河南省郑州市";break;
            case 2: name="河南省开封市";break;
            case 3: name="河南省洛阳市";break;
            case 4: name="河南省平顶山市";break;
            case 5: name="河南省安阳市";break;
            case 6: name="河南省鹤壁市";break;
            case 7: name="河南省新乡市";break;
            case 8: name="河南省焦作市";break;
            case 9: name="河南省濮阳市";break;
            case 10: name="河南省许昌市";break;
            case 11: name="河南省漯河市";break;
            case 12: name="河南省三门峡市";break;
            case 13: name="河南省南阳市";break;
            case 14: name="河南省商丘市";break;
            case 15: name="河南省信阳市";break;
            case 16: name="河南省周口市";break;
            case 17: name="河南省驻马店市";break;
        }

        region_id = m_seq.getRegionId();
        m_region.region.m_region_id=region_id;
        m_region.region.m_region_name=name;
        m_region.region.m_region_desc=name;
        m_region.region.m_region_level="0";
        m_region.region.m_region_class="0";
        m_region.region.m_state="0";
        m_region.insertData();
       
        m_billing_region.billing_region.m_region_id=region_id;
        m_billing_region.billing_region.m_parent_region_id=0;
        m_billing_region.billing_region.m_parent_region_level="0";
        m_billing_region.billing_region.m_region_level="0";
        m_billing_region.billing_region.m_region_code=code;
        m_billing_region.billing_region.m_district_num="000";
        m_billing_region.billing_region.m_inter_region_code="0";
        m_billing_region.insertData();
    }

    LOG_DEBUG(m_logId, "ConfigData::configRegionAndBillingRegion end");
}

void ConfigData::configAddress()
{
    LOG_DEBUG(m_logId, "ConfigData::configAddress begin");
    m_address.setConnection(m_db->getConnection());

    m_address.emptyData();

    RandomGen random_gen;
    map<int,string> address = random_gen.getAllAddress();
    map<int,string>::iterator it;
    for(it=address.begin();it!=address.end();it++)
    {
        long id = m_seq.getAddressId();
        string name(it->second,9);
        char post_code[5];
        sprintf(post_code,"%04d",it->first%10000);
        m_address.address.m_address_id=id;
        m_address.address.m_province_name="河南省";
        m_address.address.m_city_name=name;
        m_address.address.m_street_name=name;
        m_address.address.m_street_nbr="00000";
        m_address.address.m_detail=it->second;
        m_address.address.m_postcode=post_code;
        m_address.insertData();
    }

    LOG_DEBUG(m_logId, "ConfigData::configAddress end");
}

void ConfigData::configBillingCycle()
{
    LOG_DEBUG(m_logId, "ConfigData::configBillingCycle begin");
    m_billing_cycle.setConnection(m_db->getConnection());
    m_billing_cycle_type.setConnection(m_db->getConnection());

    m_billing_cycle.emptyData();
    m_billing_cycle_type.emptyData();

    long id = m_seq.getScardvcsn();
    long type_id = m_seq.getScardvcsn();
    m_billing_cycle.billing_cycle.m_billing_cycle_id=id;
    m_billing_cycle.billing_cycle.m_billing_cycle_type_id=type_id;
    m_billing_cycle.billing_cycle.m_last_billing_cycle_id=0;
    m_billing_cycle.billing_cycle.m_state="00A";
    m_billing_cycle.billing_cycle.m_bill_month_flag="0";
    m_billing_cycle.insertData();

    m_billing_cycle_type.billing_cycle_type.m_billing_cycle_type_id=type_id;
    m_billing_cycle_type.billing_cycle_type.m_billing_cycle_type_name="按月计费";
    m_billing_cycle_type.billing_cycle_type.m_app_type="0";
    m_billing_cycle_type.billing_cycle_type.m_cycle_unit="51A";
    m_billing_cycle_type.billing_cycle_type.m_unit_count=1;
    m_billing_cycle_type.billing_cycle_type.m_cycle_duration=0;
    m_billing_cycle_type.billing_cycle_type.m_cycle_duration_days=0;
    m_billing_cycle_type.insertData();

    LOG_DEBUG(m_logId, "ConfigData::configBillingCycle end");
}

void ConfigData::configServStateDesc()
{
    LOG_DEBUG(m_logId, "ConfigData::configServStateDesc begin");
    m_serv_state_desc.setConnection(m_db->getConnection());

    m_serv_state_desc.emptyData();

    Region region;
    region.setConnection(m_db->getConnection());
    vector<ST_REGION> v_data = region.loadAllData();

    vector<ST_REGION>::iterator it;
    for(it=v_data.begin();it!=v_data.end();it++)
    {
        long region_id = it->m_region_id;

        m_serv_state_desc.serv_state_desc.m_region_id=region_id;
        m_serv_state_desc.serv_state_desc.m_state="A";
        m_serv_state_desc.serv_state_desc.m_state_name="正常";
        m_serv_state_desc.insertData();

        m_serv_state_desc.serv_state_desc.m_state="B";
        m_serv_state_desc.serv_state_desc.m_state_name="单停";
        m_serv_state_desc.insertData();

        m_serv_state_desc.serv_state_desc.m_state="C";
        m_serv_state_desc.serv_state_desc.m_state_name="双停";
        m_serv_state_desc.insertData();

        m_serv_state_desc.serv_state_desc.m_state="D";
        m_serv_state_desc.serv_state_desc.m_state_name="销号";
        m_serv_state_desc.insertData();
    }

    LOG_DEBUG(m_logId, "ConfigData::configServStateDesc end");
}

void ConfigData::configPaymentMethodAndBalanceType()
{
    LOG_DEBUG(m_logId, "ConfigData::configPaymentMethodAndBalanceType begin");
    m_payment_method.setConnection(m_db->getConnection());
    m_balance_type.setConnection(m_db->getConnection());

    m_payment_method.emptyData();
    m_balance_type.emptyData();

    long payment_method_id = m_seq.getPaymentMethodId();
    long balance_type_id = m_seq.getBalanceTypeId();

    m_payment_method.payment_method.m_payment_method=payment_method_id;
    m_payment_method.payment_method.m_payment_method_name="前台缴费";
    m_payment_method.payment_method.m_balance_type_id=balance_type_id;
    m_payment_method.insertData();

    payment_method_id = m_seq.getPaymentMethodId();
    m_payment_method.payment_method.m_payment_method=payment_method_id;
    m_payment_method.payment_method.m_payment_method_name="银行缴费";
    m_payment_method.payment_method.m_balance_type_id=balance_type_id;
    m_payment_method.insertData();

    payment_method_id = m_seq.getPaymentMethodId();
    m_payment_method.payment_method.m_payment_method=payment_method_id;
    m_payment_method.payment_method.m_payment_method_name="代理商缴费";
    m_payment_method.payment_method.m_balance_type_id=balance_type_id;
    m_payment_method.insertData();

	m_balance_type.balance_type.m_balance_type_id=balance_type_id;
	m_balance_type.balance_type.m_priority=0;
	m_balance_type.balance_type.m_spe_payment_id=0;
	m_balance_type.balance_type.m_measure_method_id=0;
	m_balance_type.balance_type.m_balance_type_name="现金";
	m_balance_type.balance_type.m_action_mark="00";
	m_balance_type.balance_type.m_pay_type="00";
    m_balance_type.insertData();

    LOG_DEBUG(m_logId, "ConfigData::configPaymentMethodAndBalanceType end");

}

void ConfigData::configBalanceSourceType()
{

}

void ConfigData::configBalanceState()
{

}

void ConfigData::configAcctItemGroup()
{

}

void ConfigData::configAcctItemGroupMember()
{

}

void ConfigData::configAcctItemType()
{

}

void ConfigData::configAcctItemSource()
{

}

void ConfigData::doBiz()
{

    LOG_DEBUG(m_logId, "ConfigData::doBiz start");
    configCertificateType();
    configAcctType();
    configPrivilegeAndStaff();
    configRegionAndBillingRegion();
    configAddress();
    configBillingCycle();
    configServStateDesc();
    configPaymentMethodAndBalanceType();
    configBalanceSourceType();
    configBalanceState();
    configAcctItemGroup();
    configAcctItemGroupMember();
    configAcctItemType();
    configAcctItemSource();

    m_db->commit();
    LOG_DEBUG(m_logId, "ConfigData::doBiz end");
}

