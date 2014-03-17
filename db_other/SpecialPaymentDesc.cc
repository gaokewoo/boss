#include "SpecialPaymentDesc.hh"

string SpecialPaymentDesc::insSQL="INSERT INTO SPECIAL_PAYMENT_DESC(SPE_PAYMENT_ID,SPE_PAYMENT_DESC)VALUES (:SPE_PAYMENT_ID,:SPE_PAYMENT_DESC)";

void SpecialPaymentDesc::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void SpecialPaymentDesc::prepareSQL()
{
    stmt->setNumber(1,special_payment_desc.m_spe_payment_id);
    stmt->setString(2,special_payment_desc.m_spe_payment_desc);
}

