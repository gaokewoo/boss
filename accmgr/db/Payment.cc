#include "Payment.hh"

string Payment::insSQL="INSERT INTO PAYMENT(PAYMENT_ID,PAYMENT_METHOD,PARTY_ROLE_ID,PAYED_METHOD,OPERATION_TYPE,OP_CODE,OPERATED_PAYMENT_SERIAL_NBR,AMOUNT,PAYMENT_DATE,STATE,STATE_DATE,CREATED_DATE,INVOICE_ID,ACCT_ID,STAFF_ORG_ID,NBR_ORG_ID,SERV_ID)VALUES (:PAYMENT_ID,:PAYMENT_METHOD,:PARTY_ROLE_ID,:PAYED_METHOD,:OPERATION_TYPE,:OP_CODE,:OPERATED_PAYMENT_SERIAL_NBR,:AMOUNT,SYSDATE,:STATE,SYSDATE,SYSDATE,:INVOICE_ID,:ACCT_ID,:STAFF_ORG_ID,:NBR_ORG_ID,:SERV_ID)";

void Payment::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Payment::prepareSQL()
{
    stmt->setNumber(1,payment.m_payment_id);
    stmt->setNumber(2,payment.m_payment_method);
    stmt->setNumber(3,payment.m_party_role_id);
    stmt->setNumber(4,payment.m_payed_method);
    stmt->setString(5,payment.m_operation_type);
    stmt->setString(6,payment.m_op_code);
    stmt->setNumber(7,payment.m_operated_payment_serial_nbr);
    stmt->setNumber(8,payment.m_amount);
    stmt->setString(9,payment.m_state);
    stmt->setNumber(10,payment.m_invoice_id);
    stmt->setNumber(11,payment.m_acct_id);
    stmt->setNumber(12,payment.m_staff_org_id);
    stmt->setNumber(13,payment.m_nbr_org_id);
    stmt->setNumber(14,payment.m_serv_id);
}

