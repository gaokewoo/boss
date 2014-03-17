#include "DestEventType.hh"

string DestEventType::insSQL="INSERT INTO DEST_EVENT_TYPE(EVENT_TYPE_ID,NAME,SUM_EVENT_TYPE,EVENT_TYPE_CODE,STATE,EFF_DATE,EXP_DATE,EVENT_TYPE_DESC,SUM_EVENT_FLAG)VALUES (:EVENT_TYPE_ID,:NAME,:SUM_EVENT_TYPE,:EVENT_TYPE_CODE,:STATE,SYSDATE,SYSDATE,:EVENT_TYPE_DESC,:SUM_EVENT_FLAG)";

void DestEventType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DestEventType::prepareSQL()
{
    stmt->setNumber(1,dest_event_type.m_event_type_id);
    stmt->setString(2,dest_event_type.m_name);
    stmt->setString(3,dest_event_type.m_sum_event_type);
    stmt->setString(4,dest_event_type.m_event_type_code);
    stmt->setString(5,dest_event_type.m_state);
    stmt->setString(6,dest_event_type.m_event_type_desc);
    stmt->setString(7,dest_event_type.m_sum_event_flag);
}

