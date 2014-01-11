#include "CdrAttrGroup.hh"

string CdrAttrGroup::insSQL="INSERT INTO CDR_ATTR_GROUP(ATTR_GRP_ID,ATTR_TYPE,SUB_SN,GROUP_VALUE)VALUES (:ATTR_GRP_ID,:ATTR_TYPE,:SUB_SN,:GROUP_VALUE)";

void CdrAttrGroup::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CdrAttrGroup::prepareSQL()
{
    stmt->setNumber(1,cdr_attr_group.m_attr_grp_id);
    stmt->setString(2,cdr_attr_group.m_attr_type);
    stmt->setNumber(3,cdr_attr_group.m_sub_sn);
    stmt->setString(4,cdr_attr_group.m_group_value);
}

