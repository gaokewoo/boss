#include "OweBusinessAttr.hh"

string OweBusinessAttr::insSQL="INSERT INTO OWE_BUSINESS_ATTR(OP_CODE,ATTR_ID,ATTR_VAL,NOTE)VALUES (:OP_CODE,:ATTR_ID,:ATTR_VAL,:NOTE)";

void OweBusinessAttr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweBusinessAttr::prepareSQL()
{
    stmt->setString(1,owe_business_attr.m_op_code);
    stmt->setNumber(2,owe_business_attr.m_attr_id);
    stmt->setNumber(3,owe_business_attr.m_attr_val);
    stmt->setString(4,owe_business_attr.m_note);
}

