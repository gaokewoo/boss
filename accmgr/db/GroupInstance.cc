#include "GroupInstance.hh"

string GroupInstance::insSQL="INSERT INTO GROUP_INSTANCE(GROUP_ID,GROUP_TYPE_ID,GROUP_DESC,CUST_ID,CUST_AGREEMENT_ID,OFFER_ID,STATE,STATE_DATE,EFF_DATE,EXP_DATE,GRP_ATTR)VALUES (:GROUP_ID,:GROUP_TYPE_ID,:GROUP_DESC,:CUST_ID,:CUST_AGREEMENT_ID,:OFFER_ID,:STATE,SYSDATE,SYSDATE,SYSDATE,:GRP_ATTR)";

void GroupInstance::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void GroupInstance::prepareSQL()
{
    stmt->setNumber(1,group_instance.m_group_id);
    stmt->setNumber(2,group_instance.m_group_type_id);
    stmt->setString(3,group_instance.m_group_desc);
    stmt->setNumber(4,group_instance.m_cust_id);
    stmt->setNumber(5,group_instance.m_cust_agreement_id);
    stmt->setNumber(6,group_instance.m_offer_id);
    stmt->setString(7,group_instance.m_state);
    stmt->setString(8,group_instance.m_grp_attr);
}

