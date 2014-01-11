#include "AcctLogout.hh"

string AcctLogout::insSQL="INSERT INTO ACCT_LOGOUT(LOGOUT_OP_SN,ACCT_ITEM_ID,ACCT_ID,CUST_ID,AGREEMENT_ID,OWE_STATUS,OWE_BEGIN_TIME,POST_TYPE,POST_ADDR,STAFF_ID,OPER_TIME,LOGOUT_REASON,LOGOUT_AMOUNT)VALUES (:LOGOUT_OP_SN,:ACCT_ITEM_ID,:ACCT_ID,:CUST_ID,:AGREEMENT_ID,:OWE_STATUS,SYSDATE,:POST_TYPE,:POST_ADDR,:STAFF_ID,SYSDATE,:LOGOUT_REASON,:LOGOUT_AMOUNT)";

void AcctLogout::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctLogout::prepareSQL()
{
    stmt->setNumber(1,acct_logout.m_logout_op_sn);
    stmt->setNumber(2,acct_logout.m_acct_item_id);
    stmt->setNumber(3,acct_logout.m_acct_id);
    stmt->setNumber(4,acct_logout.m_cust_id);
    stmt->setNumber(5,acct_logout.m_agreement_id);
    stmt->setString(6,acct_logout.m_owe_status);
    stmt->setString(7,acct_logout.m_post_type);
    stmt->setNumber(8,acct_logout.m_post_addr);
    stmt->setNumber(9,acct_logout.m_staff_id);
    stmt->setString(10,acct_logout.m_logout_reason);
    stmt->setNumber(11,acct_logout.m_logout_amount);
}

