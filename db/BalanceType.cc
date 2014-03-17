#include "BalanceType.hh"

string BalanceType::insSQL="INSERT INTO BALANCE_TYPE(BALANCE_TYPE_ID,PRIORITY,SPE_PAYMENT_ID,MEASURE_METHOD_ID,BALANCE_TYPE_NAME,ACTION_MARK,PAY_TYPE)VALUES (:BALANCE_TYPE_ID,:PRIORITY,:SPE_PAYMENT_ID,:MEASURE_METHOD_ID,:BALANCE_TYPE_NAME,:ACTION_MARK,:PAY_TYPE)";

string BalanceType::emptySQL="DELETE FROM BALANCE_TYPE";

string BalanceType::selectAllSQL="SELECT BALANCE_TYPE_ID,PRIORITY,SPE_PAYMENT_ID,MEASURE_METHOD_ID,BALANCE_TYPE_NAME,ACTION_MARK,PAY_TYPE FROM BALANCE_TYPE";

void BalanceType::insertData()
{
    type=0;
    setSQL(insSQL);
    executeUpdate();
}

void BalanceType::emptyData()
{
    type=1;
    setSQL(emptySQL);
    executeUpdate();
}

vector<ST_BALANCE_TYPE> BalanceType::loadAllData()
{
    type=2;
    setSQL(selectAllSQL);
    executeQuery();

    return v_data;
}

void BalanceType::doParse()
{
    balance_type.m_balance_type_id = (long)rset->getNumber(1);
    balance_type.m_priority = (long)rset->getNumber(2);
    balance_type.m_spe_payment_id = (long)rset->getNumber(3);
    balance_type.m_measure_method_id = (long)rset->getNumber(4);
    balance_type.m_balance_type_name = rset->getString(5);
    balance_type.m_action_mark = rset->getString(6);
    balance_type.m_pay_type = rset->getString(7);

    v_data.push_back(balance_type);
}

void BalanceType::prepareSQL()
{
    if (type == 0)
    {
    stmt->setNumber(1,balance_type.m_balance_type_id);
    stmt->setNumber(2,balance_type.m_priority);
    stmt->setNumber(3,balance_type.m_spe_payment_id);
    stmt->setNumber(4,balance_type.m_measure_method_id);
    stmt->setString(5,balance_type.m_balance_type_name);
    stmt->setString(6,balance_type.m_action_mark);
    stmt->setString(7,balance_type.m_pay_type);
    }
}

