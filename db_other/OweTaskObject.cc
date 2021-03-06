#include "OweTaskObject.hh"

string OweTaskObject::insSQL="INSERT INTO OWE_TASK_OBJECT(OWE_TASK_ID,OWE_OBJECT_ID,OWE_OBJECT_TYPE,TASK_ORDER,ACC_NBR,ACCT_ID,CUST_ID,OLD_RUN,PREPAY_FEE,LIMIT_OWE,OWE_FEE,UNBILL_FEE,CRECTRL_TYPE,OP_ORDER,INTERVAL_TIME,OP_TIMES,STATUS,OP_DATE,STATE,STATE_DATE,STAFF_ID,PAYMENT_ID)VALUES (:OWE_TASK_ID,:OWE_OBJECT_ID,:OWE_OBJECT_TYPE,:TASK_ORDER,:ACC_NBR,:ACCT_ID,:CUST_ID,:OLD_RUN,:PREPAY_FEE,:LIMIT_OWE,:OWE_FEE,:UNBILL_FEE,:CRECTRL_TYPE,:OP_ORDER,:INTERVAL_TIME,:OP_TIMES,:STATUS,SYSDATE,:STATE,SYSDATE,:STAFF_ID,:PAYMENT_ID)";

void OweTaskObject::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void OweTaskObject::prepareSQL()
{
    stmt->setNumber(1,owe_task_object.m_owe_task_id);
    stmt->setNumber(2,owe_task_object.m_owe_object_id);
    stmt->setString(3,owe_task_object.m_owe_object_type);
    stmt->setNumber(4,owe_task_object.m_task_order);
    stmt->setString(5,owe_task_object.m_acc_nbr);
    stmt->setNumber(6,owe_task_object.m_acct_id);
    stmt->setNumber(7,owe_task_object.m_cust_id);
    stmt->setString(8,owe_task_object.m_old_run);
    stmt->setNumber(9,owe_task_object.m_prepay_fee);
    stmt->setNumber(10,owe_task_object.m_limit_owe);
    stmt->setNumber(11,owe_task_object.m_owe_fee);
    stmt->setNumber(12,owe_task_object.m_unbill_fee);
    stmt->setString(13,owe_task_object.m_crectrl_type);
    stmt->setNumber(14,owe_task_object.m_op_order);
    stmt->setNumber(15,owe_task_object.m_interval_time);
    stmt->setNumber(16,owe_task_object.m_op_times);
    stmt->setString(17,owe_task_object.m_status);
    stmt->setString(18,owe_task_object.m_state);
    stmt->setNumber(19,owe_task_object.m_staff_id);
    stmt->setNumber(20,owe_task_object.m_payment_id);
}

