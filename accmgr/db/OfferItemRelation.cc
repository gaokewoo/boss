#include "OfferItemRelation.hh"

string OfferItemRelation::insSQL="INSERT INTO OFFER_ITEM_RELATION(OFFER_ID,ACCT_ITEM_TYPE_ID,ACC_DETAIL)VALUES (:OFFER_ID,:ACCT_ITEM_TYPE_ID,:ACC_DETAIL)";

void OfferItemRelation::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OfferItemRelation::prepareSQL()
{
    stmt->setNumber(1,offer_item_relation.m_offer_id);
    stmt->setNumber(2,offer_item_relation.m_acct_item_type_id);
    stmt->setString(3,offer_item_relation.m_acc_detail);
}

