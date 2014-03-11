#include "ZtStaffLog.hh"

string ZtStaffLog::insSQL="INSERT INTO ZT_STAFF_LOG(STAFF_ID,STAFF_ORG_ID,LOGIN_ACCEPT,OPERATE_TYPE,OPERATE_CODE,OPERATE_TIME,ZTPERSON_NAME,NOTE)VALUES (:STAFF_ID,:STAFF_ORG_ID,:LOGIN_ACCEPT,:OPERATE_TYPE,:OPERATE_CODE,SYSDATE,:ZTPERSON_NAME,:NOTE)";

void ZtStaffLog::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ZtStaffLog::prepareSQL()
{
    stmt->setNumber(1,zt_staff_log.m_staff_id);
    stmt->setNumber(2,zt_staff_log.m_staff_org_id);
    stmt->setNumber(3,zt_staff_log.m_login_accept);
    stmt->setString(4,zt_staff_log.m_operate_type);
    stmt->setString(5,zt_staff_log.m_operate_code);
    stmt->setString(6,zt_staff_log.m_ztperson_name);
    stmt->setString(7,zt_staff_log.m_note);
}

