#include "OweBusinessType.hh"

string OweBusinessType::insSQL="INSERT INTO OWE_BUSINESS_TYPE(OWE_BUSINESS_TYPE_ID,OWE_BUSINESS_TYPE_NAME,STANDARD_CODE,LEVEL,OLD_RUN,NEW_RUN,AWAKE_TYPE,OP_TIMES,INTERVAL_TIME,OP_CODE)VALUES (:OWE_BUSINESS_TYPE_ID,:OWE_BUSINESS_TYPE_NAME,:STANDARD_CODE,:LEVEL,:OLD_RUN,:NEW_RUN,:AWAKE_TYPE,:OP_TIMES,:INTERVAL_TIME,:OP_CODE)";

string OweBusinessType::emptySQL="DELETE FROM OWE_BUSINESS_TYPE";

string OweBusinessType::selectAllSQL="SELECT OWE_BUSINESS_TYPE_ID,OWE_BUSINESS_TYPE_NAME,STANDARD_CODE,LEVEL,OLD_RUN,NEW_RUN,AWAKE_TYPE,OP_TIMES,INTERVAL_TIME,OP_CODE FROM OWE_BUSINESS_TYPE";

void OweBusinessType::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void OweBusinessType::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_OWE_BUSINESS_TYPE> OweBusinessType::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void OweBusinessType::doParse()
{
    owe_business_type.m_owe_business_type_id = (long)rset->getNumber(1);
    owe_business_type.m_owe_business_type_name = rset->getString(2);
    owe_business_type.m_standard_code = rset->getString(3);
    owe_business_type.m_level = rset->getString(4);
    owe_business_type.m_old_run = rset->getString(5);
    owe_business_type.m_new_run = rset->getString(6);
    owe_business_type.m_awake_type = rset->getString(7);
    owe_business_type.m_op_times = (long)rset->getNumber(8);
    owe_business_type.m_interval_time = (long)rset->getNumber(9);
    owe_business_type.m_op_code = rset->getString(10);

    v_data.push_back(owe_business_type);
}

void OweBusinessType::prepareSQL()
{
    if (type == 0)
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
}

