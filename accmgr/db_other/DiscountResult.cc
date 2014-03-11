#include "DiscountResult.hh"

string DiscountResult::insSQL="INSERT INTO DISCOUNT_RESULT(SERV_ID,GROUP_ID,FAVOUR_TYPE,BILLING_CYCLE_ID,DISCOUNT_EXPRESS_ID,PRICING_PLAN_ID,DISCOUNT_STRATEGY_ID,ACCT_ITEM_TYPE_ID,DISCOUNT,DEAL_TIME)VALUES (:SERV_ID,:GROUP_ID,:FAVOUR_TYPE,:BILLING_CYCLE_ID,:DISCOUNT_EXPRESS_ID,:PRICING_PLAN_ID,:DISCOUNT_STRATEGY_ID,:ACCT_ITEM_TYPE_ID,:DISCOUNT,SYSDATE)";

void DiscountResult::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void DiscountResult::prepareSQL()
{
    stmt->setNumber(1,discount_result.m_serv_id);
    stmt->setNumber(2,discount_result.m_group_id);
    stmt->setString(3,discount_result.m_favour_type);
    stmt->setNumber(4,discount_result.m_billing_cycle_id);
    stmt->setNumber(5,discount_result.m_discount_express_id);
    stmt->setNumber(6,discount_result.m_pricing_plan_id);
    stmt->setNumber(7,discount_result.m_discount_strategy_id);
    stmt->setNumber(8,discount_result.m_acct_item_type_id);
    stmt->setNumber(9,discount_result.m_discount);
}

