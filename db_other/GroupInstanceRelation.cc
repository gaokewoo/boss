#include "GroupInstanceRelation.hh"

string GroupInstanceRelation::insSQL="INSERT INTO GROUP_INSTANCE_RELATION(GROUP_ID,Z_GROUP_ID,AGREEMENT_ID,RELATION_TYPE,PRICING_PLAN_ID,EFF_DATE,EXP_DATE)VALUES (:GROUP_ID,:Z_GROUP_ID,:AGREEMENT_ID,:RELATION_TYPE,:PRICING_PLAN_ID,SYSDATE,SYSDATE)";

void GroupInstanceRelation::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void GroupInstanceRelation::prepareSQL()
{
    stmt->setNumber(1,group_instance_relation.m_group_id);
    stmt->setNumber(2,group_instance_relation.m_z_group_id);
    stmt->setNumber(3,group_instance_relation.m_agreement_id);
    stmt->setString(4,group_instance_relation.m_relation_type);
    stmt->setNumber(5,group_instance_relation.m_pricing_plan_id);
}

