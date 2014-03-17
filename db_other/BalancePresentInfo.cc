#include "BalancePresentInfo.hh"

string BalancePresentInfo::insSQL="INSERT INTO BALANCE_PRESENT_INFO(BALANCE_PRESENT_ID,SERV_ID,BILLING_CYCLE_ID,PRESENT_RULE_ID,PRESENT_TYPE,PRIORITY,OP_CODE,PRESENT_ID,BALANCE_TYPE_ID,BALANCE_FEE,CONTINUE_FEE,EFF_DATE,EXP_DATE,STATE,STATE_DATE)VALUES (:BALANCE_PRESENT_ID,:SERV_ID,:BILLING_CYCLE_ID,:PRESENT_RULE_ID,:PRESENT_TYPE,:PRIORITY,:OP_CODE,:PRESENT_ID,:BALANCE_TYPE_ID,:BALANCE_FEE,:CONTINUE_FEE,SYSDATE,SYSDATE,:STATE,SYSDATE)";

void BalancePresentInfo::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalancePresentInfo::prepareSQL()
{
    stmt->setNumber(1,balance_present_info.m_balance_present_id);
    stmt->setNumber(2,balance_present_info.m_serv_id);
    stmt->setNumber(3,balance_present_info.m_billing_cycle_id);
    stmt->setNumber(4,balance_present_info.m_present_rule_id);
    stmt->setString(5,balance_present_info.m_present_type);
    stmt->setNumber(6,balance_present_info.m_priority);
    stmt->setString(7,balance_present_info.m_op_code);
    stmt->setNumber(8,balance_present_info.m_present_id);
    stmt->setNumber(9,balance_present_info.m_balance_type_id);
    stmt->setNumber(10,balance_present_info.m_balance_fee);
    stmt->setNumber(11,balance_present_info.m_continue_fee);
    stmt->setString(12,balance_present_info.m_state);
}

