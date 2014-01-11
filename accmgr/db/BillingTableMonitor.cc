#include "BillingTableMonitor.hh"

string BillingTableMonitor::insSQL="INSERT INTO BILLING_TABLE_MONITOR(TABLE_NAME,FIELD_NAME,DOMAIN,SERIAL,DOMAIN_EXP,ALARM_THRESHOLD,ALARM_EXP)VALUES (:TABLE_NAME,:FIELD_NAME,:DOMAIN,:SERIAL,:DOMAIN_EXP,:ALARM_THRESHOLD,:ALARM_EXP)";

void BillingTableMonitor::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillingTableMonitor::prepareSQL()
{
    stmt->setString(1,billing_table_monitor.m_table_name);
    stmt->setString(2,billing_table_monitor.m_field_name);
    stmt->setString(3,billing_table_monitor.m_domain);
    stmt->setNumber(4,billing_table_monitor.m_serial);
    stmt->setString(5,billing_table_monitor.m_domain_exp);
    stmt->setNumber(6,billing_table_monitor.m_alarm_threshold);
    stmt->setString(7,billing_table_monitor.m_alarm_exp);
}

