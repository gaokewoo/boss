#include "CheckInfo.hh"

string CheckInfo::insSQL="INSERT INTO CHECK_INFO(CHECK_NBR,BALANCE,OP_TIME,BANK_BRANCH_ID,BANK_ACCT_NBR,BANK_ACCT_NAME,CHECK_STATE,ASSURE_STATE,ASSURE_TIME)VALUES (:CHECK_NBR,:BALANCE,SYSDATE,:BANK_BRANCH_ID,:BANK_ACCT_NBR,:BANK_ACCT_NAME,:CHECK_STATE,:ASSURE_STATE,SYSDATE)";

void CheckInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CheckInfo::prepareSQL()
{
    stmt->setString(1,check_info.m_check_nbr);
    stmt->setNumber(2,check_info.m_balance);
    stmt->setNumber(3,check_info.m_bank_branch_id);
    stmt->setString(4,check_info.m_bank_acct_nbr);
    stmt->setString(5,check_info.m_bank_acct_name);
    stmt->setString(6,check_info.m_check_state);
    stmt->setString(7,check_info.m_assure_state);
}

