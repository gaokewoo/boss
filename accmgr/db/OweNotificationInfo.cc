#include "OweNotificationInfo.hh"

string OweNotificationInfo::insSQL="INSERT INTO OWE_NOTIFICATION_INFO(SERV_ID,NOTIFICATION_TYPE,FIRST_DATE,LAST_DATE,TIMES,MONTH_TIMES,DURATIONS)VALUES (:SERV_ID,:NOTIFICATION_TYPE,SYSDATE,SYSDATE,:TIMES,:MONTH_TIMES,:DURATIONS)";

void OweNotificationInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweNotificationInfo::prepareSQL()
{
    stmt->setNumber(1,owe_notification_info.m_serv_id);
    stmt->setString(2,owe_notification_info.m_notification_type);
    stmt->setNumber(3,owe_notification_info.m_times);
    stmt->setNumber(4,owe_notification_info.m_month_times);
    stmt->setNumber(5,owe_notification_info.m_durations);
}

