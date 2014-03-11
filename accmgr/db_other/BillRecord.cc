#include "BillRecord.hh"

string BillRecord::insSQL="INSERT INTO BILL_RECORD(BILL_RECORD_ID,BILL_FORMAT_CUSTOMIZE_ID,BILL_AMOUNT,ACC_NBR,BILL_TYPE,NAME,ADDRESS_ID,POST_DATE,PARTY_ROLE_ID,BILLING_CYCLE_ID)VALUES (:BILL_RECORD_ID,:BILL_FORMAT_CUSTOMIZE_ID,:BILL_AMOUNT,:ACC_NBR,:BILL_TYPE,:NAME,:ADDRESS_ID,SYSDATE,:PARTY_ROLE_ID,:BILLING_CYCLE_ID)";

void BillRecord::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillRecord::prepareSQL()
{
    stmt->setNumber(1,bill_record.m_bill_record_id);
    stmt->setNumber(2,bill_record.m_bill_format_customize_id);
    stmt->setNumber(3,bill_record.m_bill_amount);
    stmt->setString(4,bill_record.m_acc_nbr);
    stmt->setString(5,bill_record.m_bill_type);
    stmt->setString(6,bill_record.m_name);
    stmt->setNumber(7,bill_record.m_address_id);
    stmt->setNumber(8,bill_record.m_party_role_id);
    stmt->setNumber(9,bill_record.m_billing_cycle_id);
}

