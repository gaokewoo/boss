#include "OwePlanCustomize.hh"

string OwePlanCustomize::insSQL="INSERT INTO OWE_PLAN_CUSTOMIZE(SERV_ID,ACC_NBR,PLAN_CODE,BEGIN_TIME,END_TIME,STAFF_ID,OP_TYPE,OP_TIME,OP_NOTE)VALUES (:SERV_ID,:ACC_NBR,:PLAN_CODE,SYSDATE,SYSDATE,:STAFF_ID,:OP_TYPE,SYSDATE,:OP_NOTE)";

void OwePlanCustomize::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OwePlanCustomize::prepareSQL()
{
    stmt->setNumber(1,owe_plan_customize.m_serv_id);
    stmt->setString(2,owe_plan_customize.m_acc_nbr);
    stmt->setString(3,owe_plan_customize.m_plan_code);
    stmt->setNumber(4,owe_plan_customize.m_staff_id);
    stmt->setString(5,owe_plan_customize.m_op_type);
    stmt->setString(6,owe_plan_customize.m_op_note);
}

