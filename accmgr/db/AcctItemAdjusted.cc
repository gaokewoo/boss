#include "AcctItemAdjusted.hh"

string AcctItemAdjusted::insSQL="INSERT INTO ACCT_ITEM_ADJUSTED(ADJUST_RECORD_ID,ACCT_ITEM_ID,ADJUST_ACCT_ITEM_ID,CHARGE_ADJUST)VALUES (:ADJUST_RECORD_ID,:ACCT_ITEM_ID,:ADJUST_ACCT_ITEM_ID,:CHARGE_ADJUST)";

void AcctItemAdjusted::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void AcctItemAdjusted::prepareSQL()
{
    stmt->setNumber(1,acct_item_adjusted.m_adjust_record_id);
    stmt->setNumber(2,acct_item_adjusted.m_acct_item_id);
    stmt->setNumber(3,acct_item_adjusted.m_adjust_acct_item_id);
    stmt->setNumber(4,acct_item_adjusted.m_charge_adjust);
}

