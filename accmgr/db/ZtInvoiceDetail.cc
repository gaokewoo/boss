#include "ZtInvoiceDetail.hh"

string ZtInvoiceDetail::insSQL="INSERT INTO ZT_INVOICE_DETAIL(LOGIN_ACCEPT,ACCT_ID,SERV_ID,BILLING_CYCLE_ID,INVOICE_ITEM_ID,ITEM_NAME,SHOULD_PAY,FAVOUR_FEE,ITEM_VALUE,INSERT_TIME,RESV)VALUES (:LOGIN_ACCEPT,:ACCT_ID,:SERV_ID,:BILLING_CYCLE_ID,:INVOICE_ITEM_ID,:ITEM_NAME,:SHOULD_PAY,:FAVOUR_FEE,:ITEM_VALUE,SYSDATE,:RESV)";

void ZtInvoiceDetail::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void ZtInvoiceDetail::prepareSQL()
{
    stmt->setNumber(1,zt_invoice_detail.m_login_accept);
    stmt->setNumber(2,zt_invoice_detail.m_acct_id);
    stmt->setNumber(3,zt_invoice_detail.m_serv_id);
    stmt->setNumber(4,zt_invoice_detail.m_billing_cycle_id);
    stmt->setNumber(5,zt_invoice_detail.m_invoice_item_id);
    stmt->setString(6,zt_invoice_detail.m_item_name);
    stmt->setNumber(7,zt_invoice_detail.m_should_pay);
    stmt->setNumber(8,zt_invoice_detail.m_favour_fee);
    stmt->setString(9,zt_invoice_detail.m_item_value);
    stmt->setString(10,zt_invoice_detail.m_resv);
}

