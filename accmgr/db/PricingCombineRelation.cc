#include "PricingCombineRelation.hh"

string PricingCombineRelation::insSQL="INSERT INTO PRICING_COMBINE_RELATION(A_PRICING_COMBINE_ID,Z_PRICING_COMBINE_ID,RELATION_TYPE)VALUES (:A_PRICING_COMBINE_ID,:Z_PRICING_COMBINE_ID,:RELATION_TYPE)";

void PricingCombineRelation::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PricingCombineRelation::prepareSQL()
{
    stmt->setNumber(1,pricing_combine_relation.m_a_pricing_combine_id);
    stmt->setNumber(2,pricing_combine_relation.m_z_pricing_combine_id);
    stmt->setString(3,pricing_combine_relation.m_relation_type);
}

