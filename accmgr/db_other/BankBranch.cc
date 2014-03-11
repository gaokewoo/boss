#include "BankBranch.hh"

string BankBranch::insSQL="INSERT INTO BANK_BRANCH(BANK_BRANCH_ID,BANK_ID,BANK_BRANCH_NAME,BANK_ACCT,BANK_ACCT_NAME,BANK_BRANCH_PHONE,BANK_BRANCH_ADDR,REGION_ID,BANK_CODE)VALUES (:BANK_BRANCH_ID,:BANK_ID,:BANK_BRANCH_NAME,:BANK_ACCT,:BANK_ACCT_NAME,:BANK_BRANCH_PHONE,:BANK_BRANCH_ADDR,:REGION_ID,:BANK_CODE)";

void BankBranch::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BankBranch::prepareSQL()
{
    stmt->setNumber(1,bank_branch.m_bank_branch_id);
    stmt->setNumber(2,bank_branch.m_bank_id);
    stmt->setString(3,bank_branch.m_bank_branch_name);
    stmt->setString(4,bank_branch.m_bank_acct);
    stmt->setString(5,bank_branch.m_bank_acct_name);
    stmt->setString(6,bank_branch.m_bank_branch_phone);
    stmt->setString(7,bank_branch.m_bank_branch_addr);
    stmt->setNumber(8,bank_branch.m_region_id);
    stmt->setString(9,bank_branch.m_bank_code);
}

