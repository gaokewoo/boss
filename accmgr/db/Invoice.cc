#include "Invoice.hh"

string Invoice::insSQL="INSERT INTO INVOICE(INVOICE_ID,PAYMENT_ID,BILLING_CYCLE_ID,NAME,PARTY_ROLE_ID,BILL_FORMAT_CUSTOMIZE_ID,ACC_NBR,AMOUNT,COUNT,PRINT_COUNT,PRINT_FLAG,INVOICE_TYPE,OPER_TIME)VALUES (:INVOICE_ID,:PAYMENT_ID,:BILLING_CYCLE_ID,:NAME,:PARTY_ROLE_ID,:BILL_FORMAT_CUSTOMIZE_ID,:ACC_NBR,:AMOUNT,:COUNT,:PRINT_COUNT,:PRINT_FLAG,:INVOICE_TYPE,SYSDATE)";

void Invoice::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Invoice::prepareSQL()
{
    stmt->setNumber(1,invoice.m_invoice_id);
    stmt->setNumber(2,invoice.m_payment_id);
    stmt->setNumber(3,invoice.m_billing_cycle_id);
    stmt->setString(4,invoice.m_name);
    stmt->setNumber(5,invoice.m_party_role_id);
    stmt->setNumber(6,invoice.m_bill_format_customize_id);
    stmt->setString(7,invoice.m_acc_nbr);
    stmt->setNumber(8,invoice.m_amount);
    stmt->setNumber(9,invoice.m_count);
    stmt->setNumber(10,invoice.m_print_count);
    stmt->setString(11,invoice.m_print_flag);
    stmt->setString(12,invoice.m_invoice_type);
}

