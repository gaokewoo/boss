#include "CollectOprt.hh"

string CollectOprt::insSQL="INSERT INTO COLLECT_OPRT(COLLECT_OPER_SN,COLLECT_NBR,ACCT_ID,PAYMENT_PLAN_ID,BANK_BRANCH_ID,COLLECT_YM,COLLECT_OPER_TYPE,REFUSE_TYPE,STAFF_ID,OP_TIME,COMMENTS)VALUES (:COLLECT_OPER_SN,:COLLECT_NBR,:ACCT_ID,:PAYMENT_PLAN_ID,:BANK_BRANCH_ID,:COLLECT_YM,:COLLECT_OPER_TYPE,:REFUSE_TYPE,:STAFF_ID,SYSDATE,:COMMENTS)";

void CollectOprt::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void CollectOprt::prepareSQL()
{
    stmt->setNumber(1,collect_oprt.m_collect_oper_sn);
    stmt->setString(2,collect_oprt.m_collect_nbr);
    stmt->setNumber(3,collect_oprt.m_acct_id);
    stmt->setNumber(4,collect_oprt.m_payment_plan_id);
    stmt->setNumber(5,collect_oprt.m_bank_branch_id);
    stmt->setNumber(6,collect_oprt.m_collect_ym);
    stmt->setString(7,collect_oprt.m_collect_oper_type);
    stmt->setString(8,collect_oprt.m_refuse_type);
    stmt->setNumber(9,collect_oprt.m_staff_id);
    stmt->setString(10,collect_oprt.m_comments);
}

