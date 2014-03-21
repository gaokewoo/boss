#include "ChargeAdjustLog.hh"

string ChargeAdjustLog::insSQL="INSERT INTO CHARGE_ADJUST_LOG(CHARGE_ADJUST_LOG_ID,ADJUST_RECORD_ID,CAUSE,\"DATE\",STAFF_ID)VALUES (:CHARGE_ADJUST_LOG_ID,:ADJUST_RECORD_ID,:CAUSE,SYSDATE,:STAFF_ID)";

void ChargeAdjustLog::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ChargeAdjustLog::prepareSQL()
{
    stmt->setNumber(1,charge_adjust_log.m_charge_adjust_log_id);
    stmt->setNumber(2,charge_adjust_log.m_adjust_record_id);
    stmt->setString(3,charge_adjust_log.m_cause);
    stmt->setNumber(4,charge_adjust_log.m_staff_id);
}

