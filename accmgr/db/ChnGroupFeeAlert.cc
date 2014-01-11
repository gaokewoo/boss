#include "ChnGroupFeeAlert.hh"

string ChnGroupFeeAlert::insSQL="INSERT INTO CHN_GROUP_FEE_ALERT(ORG_ID,ALERT_VALUE,UPDATE_TIME,STAFF_ID,NOTE)VALUES (:ORG_ID,:ALERT_VALUE,SYSDATE,:STAFF_ID,:NOTE)";

void ChnGroupFeeAlert::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ChnGroupFeeAlert::prepareSQL()
{
    stmt->setNumber(1,chn_group_fee_alert.m_org_id);
    stmt->setNumber(2,chn_group_fee_alert.m_alert_value);
    stmt->setNumber(3,chn_group_fee_alert.m_staff_id);
    stmt->setString(4,chn_group_fee_alert.m_note);
}

