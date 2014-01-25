#include "ConfigData.hh"

ConfigData::ConfigData(LoggerId logId)
{
    m_logId = logId;
    LOG_DEBUG(m_logId, "ConfigData::ConfigData start");

    m_db = new OracleDB();
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

void ConfigData::doBiz()
{

    LOG_DEBUG(m_logId, "ConfigData::doBiz start");
    configCertificateType();
    configAcctType();

    m_db->commit();
    LOG_DEBUG(m_logId, "ConfigData::doBiz end");
}

