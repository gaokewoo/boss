#include "OweTask.hh"

string OweTask::insSQL="INSERT INTO OWE_TASK(OWE_TASK_ID,TIME_INFO_ID,OWE_BUSINESS_TYPE_ID,OWE_TASK_NAME,UNIT,OFFSET,TIME)VALUES (:OWE_TASK_ID,:TIME_INFO_ID,:OWE_BUSINESS_TYPE_ID,:OWE_TASK_NAME,:UNIT,:OFFSET,SYSDATE)";

void OweTask::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweTask::prepareSQL()
{
    stmt->setNumber(1,owe_task.m_owe_task_id);
    stmt->setNumber(2,owe_task.m_time_info_id);
    stmt->setNumber(3,owe_task.m_owe_business_type_id);
    stmt->setString(4,owe_task.m_owe_task_name);
    stmt->setString(5,owe_task.m_unit);
    stmt->setNumber(6,owe_task.m_offset);
}

