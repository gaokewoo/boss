#include "CheckOpr.hh"

string CheckOpr::insSQL="INSERT INTO CHECK_OPR(CHECK_OPER_SN,PAYMENT_ID,BANK_BRANCH_ID,BANK_ACCT_NBR,BANK_ACCT_NAME,CHECK_NBR,CHECK_MONEY,CHECK_STATE,ASSURE_STATE,ASSURE_TIME,CUST_ID)VALUES (:CHECK_OPER_SN,:PAYMENT_ID,:BANK_BRANCH_ID,:BANK_ACCT_NBR,:BANK_ACCT_NAME,:CHECK_NBR,:CHECK_MONEY,:CHECK_STATE,:ASSURE_STATE,SYSDATE,:CUST_ID)";

void CheckOpr::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CheckOpr::prepareSQL()
{
    stmt->setNumber(1,check_opr.m_check_oper_sn);
    stmt->setNumber(2,check_opr.m_payment_id);
    stmt->setNumber(3,check_opr.m_bank_branch_id);
    stmt->setString(4,check_opr.m_bank_acct_nbr);
    stmt->setString(5,check_opr.m_bank_acct_name);
    stmt->setString(6,check_opr.m_check_nbr);
    stmt->setNumber(7,check_opr.m_check_money);
    stmt->setString(8,check_opr.m_check_state);
    stmt->setString(9,check_opr.m_assure_state);
    stmt->setNumber(10,check_opr.m_cust_id);
}

