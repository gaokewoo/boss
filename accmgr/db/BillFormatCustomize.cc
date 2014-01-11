#include "BillFormatCustomize.hh"

string BillFormatCustomize::insSQL="INSERT INTO BILL_FORMAT_CUSTOMIZE(BILL_FORMAT_CUSTOMIZE_ID,ACCT_ID,BILL_FORMAT_ID,BILL_POST_CYCLE,ADDRESS_ID,BILL_POST_METHOD,STATE,STATE_DATE,FORMAT_TYPE,SERV_ID,CUST_ID)VALUES (:BILL_FORMAT_CUSTOMIZE_ID,:ACCT_ID,:BILL_FORMAT_ID,:BILL_POST_CYCLE,:ADDRESS_ID,:BILL_POST_METHOD,:STATE,SYSDATE,:FORMAT_TYPE,:SERV_ID,:CUST_ID)";

void BillFormatCustomize::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BillFormatCustomize::prepareSQL()
{
    stmt->setNumber(1,bill_format_customize.m_bill_format_customize_id);
    stmt->setNumber(2,bill_format_customize.m_acct_id);
    stmt->setNumber(3,bill_format_customize.m_bill_format_id);
    stmt->setString(4,bill_format_customize.m_bill_post_cycle);
    stmt->setNumber(5,bill_format_customize.m_address_id);
    stmt->setString(6,bill_format_customize.m_bill_post_method);
    stmt->setString(7,bill_format_customize.m_state);
    stmt->setString(8,bill_format_customize.m_format_type);
    stmt->setNumber(9,bill_format_customize.m_serv_id);
    stmt->setNumber(10,bill_format_customize.m_cust_id);
}

