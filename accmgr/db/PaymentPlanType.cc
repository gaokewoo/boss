#include "PaymentPlanType.hh"

string PaymentPlanType::insSQL="INSERT INTO PAYMENT_PLAN_TYPE(REGION_ID,PAYMENT_PLAN_TYPE,PAYMENT_PLAN_TYPE_NAME,HIGHFEE_FLAG,PREDEL_MONTH,DEL_MONTH)VALUES (:REGION_ID,:PAYMENT_PLAN_TYPE,:PAYMENT_PLAN_TYPE_NAME,:HIGHFEE_FLAG,:PREDEL_MONTH,:DEL_MONTH)";

void PaymentPlanType::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void PaymentPlanType::prepareSQL()
{
    stmt->setNumber(1,payment_plan_type.m_region_id);
    stmt->setString(2,payment_plan_type.m_payment_plan_type);
    stmt->setString(3,payment_plan_type.m_payment_plan_type_name);
    stmt->setString(4,payment_plan_type.m_highfee_flag);
    stmt->setNumber(5,payment_plan_type.m_predel_month);
    stmt->setNumber(6,payment_plan_type.m_del_month);
}

