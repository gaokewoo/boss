#include "OweBusinessType.hh"

string OweBusinessType::insSQL="INSERT INTO OWE_BUSINESS_TYPE(OWE_BUSINESS_TYPE_ID,OWE_BUSINESS_TYPE_NAME,STANDARD_CODE,LEVEL,OLD_RUN,NEW_RUN,AWAKE_TYPE,OP_TIMES,INTERVAL_TIME,OP_CODE)VALUES (:OWE_BUSINESS_TYPE_ID,:OWE_BUSINESS_TYPE_NAME,:STANDARD_CODE,:LEVEL,:OLD_RUN,:NEW_RUN,:AWAKE_TYPE,:OP_TIMES,:INTERVAL_TIME,:OP_CODE)";

void OweBusinessType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBusinessType::prepareSQL()
{
    stmt->setNumber(1,owe_business_type.m_owe_business_type_id);
    stmt->setString(2,owe_business_type.m_owe_business_type_name);
    stmt->setString(3,owe_business_type.m_standard_code);
    stmt->setString(4,owe_business_type.m_level);
    stmt->setString(5,owe_business_type.m_old_run);
    stmt->setString(6,owe_business_type.m_new_run);
    stmt->setString(7,owe_business_type.m_awake_type);
    stmt->setNumber(8,owe_business_type.m_op_times);
    stmt->setNumber(9,owe_business_type.m_interval_time);
    stmt->setString(10,owe_business_type.m_op_code);
}

