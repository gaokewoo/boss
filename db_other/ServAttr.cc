#include "ServAttr.hh"

string ServAttr::insSQL="INSERT INTO SERV_ATTR(SERV_ID,AGREEMENT_ID,ATTR_ID,ATTR_VAL,EFF_DATE,EXP_DATE)VALUES (:SERV_ID,:AGREEMENT_ID,:ATTR_ID,:ATTR_VAL,SYSDATE,SYSDATE)";

void ServAttr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ServAttr::prepareSQL()
{
    stmt->setNumber(1,serv_attr.m_serv_id);
    stmt->setNumber(2,serv_attr.m_agreement_id);
    stmt->setNumber(3,serv_attr.m_attr_id);
    stmt->setString(4,serv_attr.m_attr_val);
}

