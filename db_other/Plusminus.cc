#include "Plusminus.hh"

string Plusminus::insSQL="INSERT INTO PLUSMINUS(PLUS_SEQ_NBR,ACC_NBR,BILLING_CYCLE_ID,ACCT_ITEM_TYPE_ID,AMOUNT,MERGE_FLAG,REASON,MERGE_BALANCE,FEE_CYCLE_ID,PARTY_ROLE_ID,CREATE_DATE,STATE,STATE_DATE)VALUES (:PLUS_SEQ_NBR,:ACC_NBR,:BILLING_CYCLE_ID,:ACCT_ITEM_TYPE_ID,:AMOUNT,:MERGE_FLAG,:REASON,:MERGE_BALANCE,:FEE_CYCLE_ID,:PARTY_ROLE_ID,SYSDATE,:STATE,SYSDATE)";

void Plusminus::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void Plusminus::prepareSQL()
{
    stmt->setNumber(1,plusminus.m_plus_seq_nbr);
    stmt->setString(2,plusminus.m_acc_nbr);
    stmt->setNumber(3,plusminus.m_billing_cycle_id);
    stmt->setNumber(4,plusminus.m_acct_item_type_id);
    stmt->setNumber(5,plusminus.m_amount);
    stmt->setString(6,plusminus.m_merge_flag);
    stmt->setString(7,plusminus.m_reason);
    stmt->setNumber(8,plusminus.m_merge_balance);
    stmt->setNumber(9,plusminus.m_fee_cycle_id);
    stmt->setNumber(10,plusminus.m_party_role_id);
    stmt->setString(11,plusminus.m_state);
}

