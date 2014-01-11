#include "BalanceType.hh"

string BalanceType::insSQL="INSERT INTO BALANCE_TYPE(BALANCE_TYPE_ID,PRIORITY,SPE_PAYMENT_ID,MEASURE_METHOD_ID,BALANCE_TYPE_NAME,ACTION_MARK,PAY_TYPE)VALUES (:BALANCE_TYPE_ID,:PRIORITY,:SPE_PAYMENT_ID,:MEASURE_METHOD_ID,:BALANCE_TYPE_NAME,:ACTION_MARK,:PAY_TYPE)";

void BalanceType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void BalanceType::prepareSQL()
{
    stmt->setNumber(1,balance_type.m_balance_type_id);
    stmt->setNumber(2,balance_type.m_priority);
    stmt->setNumber(3,balance_type.m_spe_payment_id);
    stmt->setNumber(4,balance_type.m_measure_method_id);
    stmt->setString(5,balance_type.m_balance_type_name);
    stmt->setString(6,balance_type.m_action_mark);
    stmt->setString(7,balance_type.m_pay_type);
}

