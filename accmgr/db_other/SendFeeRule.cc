#include "SendFeeRule.hh"

string SendFeeRule::insSQL="INSERT INTO SEND_FEE_RULE(BALANCE_TYPE_ID,EFF_DATE,EXP_DATE,SEND_FLAG,MIN_PAY,MAX_PAY,SEND_VALUE,OP_NOTE)VALUES (:BALANCE_TYPE_ID,SYSDATE,SYSDATE,:SEND_FLAG,:MIN_PAY,:MAX_PAY,:SEND_VALUE,:OP_NOTE)";

void SendFeeRule::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void SendFeeRule::prepareSQL()
{
    stmt->setNumber(1,send_fee_rule.m_balance_type_id);
    stmt->setString(2,send_fee_rule.m_send_flag);
    stmt->setNumber(3,send_fee_rule.m_min_pay);
    stmt->setNumber(4,send_fee_rule.m_max_pay);
    stmt->setNumber(5,send_fee_rule.m_send_value);
    stmt->setString(6,send_fee_rule.m_op_note);
}

