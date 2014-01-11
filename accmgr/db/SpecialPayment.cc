#include "SpecialPayment.hh"

string SpecialPayment::insSQL="INSERT INTO SPECIAL_PAYMENT(SPE_PAYMENT_ID,PARTNER_ID,PRODUCT_ID,ACCT_ITEM_GROUP_ID)VALUES (:SPE_PAYMENT_ID,:PARTNER_ID,:PRODUCT_ID,:ACCT_ITEM_GROUP_ID)";

void SpecialPayment::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void SpecialPayment::prepareSQL()
{
    stmt->setNumber(1,special_payment.m_spe_payment_id);
    stmt->setNumber(2,special_payment.m_partner_id);
    stmt->setNumber(3,special_payment.m_product_id);
    stmt->setNumber(4,special_payment.m_acct_item_group_id);
}

